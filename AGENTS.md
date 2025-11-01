# Repository Guidelines

## Project Structure & Module Organization
- `src/` hosts the C++/Qt engine and UI; colocate new tests under `src/test` alongside focused fixtures.
- `res/` stores skins, translations, controller mappings, and audio assets—keep additions optimized and localized.
- `lib/` carries vendored dependencies (avoid modifying without upstream coordination).
- `tools/` contains automation helpers such as `macos_buildenv.sh`, clang-format hooks, and packaging scripts; `buildenv/` caches platform SDKs.
- `packaging/` holds distro- and installer-specific specs; update these when shipping platform changes.

## Build, Test, and Development Commands
- `source tools/macos_buildenv.sh setup` (or `tools/windows_buildenv.bat`, `tools/debian_buildenv.sh setup`) provisions dependencies.
- `cmake -S . -B build -G Ninja` configures an out-of-tree build; adjust the generator if Ninja is unavailable.
- `cmake --build build --target mixxx -j$(sysctl -n hw.ncpu)` compiles the desktop app; run `./build/mixxx` to launch it.
- `cmake --build build --target package` produces installers; `ctest --test-dir build --output-on-failure` executes the regression suite.

## Coding Style & Naming Conventions
- C++ adheres to `.clang-format` (Google base, 4 spaces, no tabs) and `.clang-tidy`; prefer `PascalCase` types, `camelCase` methods, `mCamelCase` members, and `kConstant` naming.
- Python utilities are formatted with Black (`line-length = 79`) and linted by Flake8; JavaScript uses ESLint plus Prettier (`eslint.config.cjs`, `.prettierrc.yaml`).
- Install automation locally: `pre-commit install && pre-commit install -t pre-push`; run `pre-commit run --all-files` before submitting.

## Testing Guidelines
- Add unit and integration coverage in `src/test`, following the existing `<feature>_test.cpp` naming and gtest structure.
- Reuse or extend bundled fixtures (`soundFileFormats/`, `mixxx_library_struct.tar.gz`, etc.) to keep regressions reproducible.
- Document manual verification steps when automated coverage is impractical (e.g., controller mappings, GUI tweaks).

## Commit & Pull Request Guidelines
- Keep commits buildable and scoped; 72-character subjects with optional prefixes (`feat(ui): …`, `LateNight: …`) match project history.
- Reference issues or Zulip threads in commit bodies when relevant, and explain notable architectural decisions.
- Pull requests should list test commands run (`cmake --build …`, `ctest …`), include before/after screenshots for UI, and mention affected controllers or packaging targets.
- Avoid force-pushing shared branches; coordinate rebases in Zulip and let CI finish before requesting review.
