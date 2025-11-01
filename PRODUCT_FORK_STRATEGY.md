# Product Fork Strategy

## Goals
- Rebrand the Mixxx codebase for a commercial product while keeping upstream bug fixes.
- Maintain a predictable workflow for merging upstream changes into the customized release branch.

## Repository Layout
- `upstream-main`: tracks `mixxxdj/mixxx` without product edits; keep history pristine for easy rebases and merges.
- `product-main`: default development branch with branding updates, proprietary features, and packaging changes.
- Optional topic branches (`feature/<name>`, `hotfix/<name>`) branch off `product-main` and are merged back through review.

## Syncing Upstream Changes
- Fetch upstream regularly: `git fetch upstream`.
- Merge, don’t rebase, when bringing `upstream/main` into `product-main` to preserve public history: `git merge upstream/main`.
- Resolve conflicts immediately; rerun the regression checklist (configure, `cmake --build`, `ctest`, smoke tests) before pushing.
- Tag synced points (`sync-YYYYMMDD`) so regressions can be traced to a specific upstream integration.

## Product-Specific Work
- Centralize branding strings, icons, app IDs, and packaging metadata so future upstream merges touch fewer files.
- Guard divergent behavior with CMake options or compile-time switches such as `-DPRODUCT_VARIANT=ON`; keep default paths matching upstream.
- Group long-lived features in dedicated modules or plugins to limit overlap with upstream source files.

## Release & Packaging
- Tag releases from `product-main` (`vX.Y-product`) and archive build artifacts alongside release notes.
- Maintain parallel packaging specs under `packaging/product/` while retaining upstream definitions for reference.
- Document manual validation steps (UI, controller mappings, licensing checks) in the release checklist.

## Contribution Hygiene
- Preface commits with `product:` or subsystem-specific scopes (`product-ui:`, `build:`) to highlight divergences.
- Upstream any generic fixes when possible to reduce future merge churn; track pending upstream submissions in an issue board or TODO list.
- Avoid force-pushing shared branches; coordinate significant history rewrites with the team via Zulip or your chosen channel.
