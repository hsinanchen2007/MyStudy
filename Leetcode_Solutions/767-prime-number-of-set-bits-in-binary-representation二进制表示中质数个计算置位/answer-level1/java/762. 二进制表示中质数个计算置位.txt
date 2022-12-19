/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/11
 *
 * 解题思路: 主要使用 Integer.bitCount(i) 求二进制数中1的个数 速度快
 *
 * //二进制1的个数 的最大长度为20 因为10^6的二进制不大于20位
 *
 */
```
public int countPrimeSetBits(int L, int R) {
    int sum = 0;
    for(int i = L;i <=R ; i++){
        if(isZS(Integer.bitCount(i))){
            sum++;
        }
    }
    return sum;
}

//d 的最大长度为20 因为10^6的二进制不大于20位
public boolean isZS(int d){
    if(d == 1 || d == 0) return false;
    for(int i = 2;i <= Math.sqrt(d);i++){
        if(d % i == 0){
            return false;
        }
    }
    return true;
}

public int sumZW(int d){
    int sum = 0;
    while(d != 0){
        if((sum & 1) == 1){
            sum++;
        }
        sum = sum >> 1;
    }
    return sum;
}
```