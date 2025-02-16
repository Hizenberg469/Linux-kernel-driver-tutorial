cmd_/home/device-driver/02_better_hello/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/device-driver/02_better_hello/"$$0) }' > /home/device-driver/02_better_hello/hello.mod
