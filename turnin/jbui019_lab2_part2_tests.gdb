# Add tests below
test "PINA[1:0] : 01, PORTB0: 1"
setPINA 0x01
continue 2
expectPORTB 0x01
checkResult

test "PINA[1:0] : 10, PORTB0 : 0"
setPINA 0x02
continue 2
expectPORTB 0x00
checkResult

test "PINA[1:0] : 11, PORTB0 : 0"
setPINA 0x03
continue 2
expectPORTB 0x00
checkResult

test "PINA[3:0] : 0001, PORTC[2:0] : 001"
setPINA 0x01
continue 2
expectPORTC 0x01
checkResult

test "PINA[3:0] : 0110, PORTC[2:0] : 010"
setPINA 0x06
continue 2
expectPORTC 0x02
checkResult

test "PINA[3:0] : 1101, PORTC[2:0] : 011"
setPINA 0x0D
continue 2
expectPORTC 0x03
checkResult


test "PINA[3:0] : 1111, PORT[2:0] : 100"
setPINA 0x0F
continue 2
expectPORTC 0x04
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
