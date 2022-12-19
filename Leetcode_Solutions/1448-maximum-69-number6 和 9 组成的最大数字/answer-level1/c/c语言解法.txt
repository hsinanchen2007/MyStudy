判断是否有6，若有则判断第一个6的位数。将该位上的6变为9即可。

int maximum69Number (int num){
    int res =0;
    int digit = 3;
    //int mod
    int num_temp = num / pow(10, digit);
    while (num_temp%10 != 6 && digit >= 0) {
        digit--;
        num_temp = num / pow(10, digit);
    }
    if (digit < 0) {
        res = num;
    }
    else {
        res = num + 3 * pow(10,digit);
    }
    return res;
}
![image.png](https://pic.leetcode-cn.com/432dfe408b00b5af88fe2548f0e27715386d983310928e7b48adc4603210df26-image.png)
