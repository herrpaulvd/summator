#!/bin/sh

cd $(dirname $0)
make all || exit 1

dotest() {
    result=$(./summator $1 $2)
    if [ "$result" = "$3" ]; then
        echo "successful";
    else
        echo "fail";
    fi
}

for test in $(ls tests); do
    echo "Test $test"
    dotest $(cat tests/$test)
done
