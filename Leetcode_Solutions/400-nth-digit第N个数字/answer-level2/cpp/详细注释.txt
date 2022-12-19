1位数占$1*10^0*9$位
2位数占$2*10^1*9$位
...
bit位占$bit*10^{bit-1}*9$位
```c++
class Solution {
public:
/*
    bit记录第n个数是属于数字num有几位数例如n=190对应的位数是3
    t是有bit位数的数字计数器例如 n=190 因为有三位数所以从190-(9+180)-1=0开始(减去不足bit位数的所有数占的位数)
    t/bit就是表示是有bit位数的第几个例如t=0,bit=3时t/bit表示是三位数的第0个即100
    t%bit就是n所属于的数的第几位例如n=189属于数字99,此时bit=2,t=189-9-1=179,t/bit=89,t%2=1对应的是bit中第二个数(从0开始所以加一)
    再举个例子
    n=289
    此时bit=3;
    t=289-(9+180)-1=99,t/bit=33,t%3=0对应的是bit位中的第1位(计数从0开始)
*/
    int findNthDigit(int n) {
        long long ten=1,bit=1,sum=ten * bit * 9;
        if(n<10)return n;
        while(sum < n){
            bit++;
            ten*=10;
            sum += ten * bit * 9;
            if(sum>=n){
                sum -= ten * bit * 9;
                break;
            }
        }
        ten = pow(10,bit-1);
        int t = n - sum - 1,pos=t/bit,res = t%bit;
        int num = ten * (pos/ten + 1) + pos%ten;//第n位属于哪个数字 例如属于数字100的n可以是190 191 192这里的num就是通过n反求的num
        for(int j=bit-1;j>=0;j--){
            if(j==res)return num%10;
            num/=10;
        }
        return 0;
    }
};
```