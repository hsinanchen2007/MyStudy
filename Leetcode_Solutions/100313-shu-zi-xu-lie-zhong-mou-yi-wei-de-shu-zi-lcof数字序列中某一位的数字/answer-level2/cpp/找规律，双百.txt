```
class Solution {
public:
    int findNthDigit(int n) {
        int bit = 0;
        long len = 1, k = 9;    
        while(n - len + 1 > 0){
            ++bit;
            len += k * bit;        //len 为 0-9 ， 0-99， 0-999 总长度
            k *= 10;
        }
        n = n - (len - bit *(k / 10)) + 1;     //此时n为比前一个 9或99或999··· 多的长度，bit 为当前数的位数
        int remainder = n % bit;               //remainde 为余数
        int div = n / bit;
        if(remainder == 0) return ((int)pow(10, bit - 1) + div - 1) % 10;       //余数为0正好是末尾
        else{                                                                   //余数不为0则为后一个数的 bit-remainder 位
            int cur = (int)pow(10, bit - 1) + div;
            while(bit - remainder){
                cur /= 10;
                --bit;
            }
            return cur % 10;
        }
    }
};
```
