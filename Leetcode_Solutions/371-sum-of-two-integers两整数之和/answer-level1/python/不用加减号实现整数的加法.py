while b:
    a, b = (a ^ b) & 0xFFFFFFFF, ((a & b) << 1) & 0xFFFFFFFF
if a> 0x7FFFFFFF:
    a = ~(a ^ 0xFFFFFFFF)
return a
每次异或运算或者与运算之后再和0xFFFFFFFF做一次与运算，从而保证数据的长度。最后注意一下数的大小，如果结果大于0x7FFFFFFF，溢出了，还要和0xFFFFFFFF异或之后取反。