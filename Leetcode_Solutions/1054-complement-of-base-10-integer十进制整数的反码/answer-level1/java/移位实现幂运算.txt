- 无符号二进制整数加上补码之后，所有位上的数都是1，长度为len，在这基础上加1之后，就变成了2的len次幂。
``` java
public int bitwiseComplement(int N){
    int len = Integer.toBinaryString(N).length()-1;
    //使用移位来进行幂运算
    return (2<<len)-1-N;
}