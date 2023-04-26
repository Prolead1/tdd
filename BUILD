load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")

refresh_compile_commands(
    name = "refresh_compile_commands",
)

cc_library(
  name = "MereTDDlibrary",
  hdrs = glob(["*.h"]),
)

cc_binary(
  name = "main",
  srcs = glob(["**/*.cpp"]),
  deps = [":MereTDDlibrary"]
)
