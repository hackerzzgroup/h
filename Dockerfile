FROM debian:buster-slim as h

RUN apt-get update && apt-get install -y \
    gcc \
    make \
    && rm -rf /var/lib/apt/lists/*

COPY *.c Makefile /

RUN CC="gcc -static" make


FROM scratch

COPY --from=h /h /h

ENTRYPOINT ["/h"]
CMD ["-h"]