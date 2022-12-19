找规律题，大家的思路都相似，看了其他双百选手，觉得自己的代码还需要进一步简化

主要思想是分两步找到n所对应的数字num，然后在寻找过程中不断减小n的数值
1. 找到n对应的数字位数digit
2. 利用n/digit，找到n对应的数字num，这里我分了能否整除两种情况进行讨论

```
class Solution {
public:
    int findNthDigit(int n) {
        if(n<10)return(n);//偷懒不考虑小于10的情况
        //计算对应的位数
        int digit=1;
        while(n>9*digit*pow(10,digit-1)){
            n -= 9*digit*pow(10,digit-1);
            digit++;
        }
        // 计算n对应的是digit位数中第几个数字
        int j=n/digit;
        int num;//对应的数字
        if(n%digit==0){
            // 如果n%digit==0，那么就对应第j个数字的最后一位
            num =pow(10,digit-1)+j-1;
            return(num%10);
        }
        // 如果n%digit!=0，那么就对应第j+1个数字(下面用num所表示)的第n位
        // 如对应1253的第3位，那么结果就是5，我这边使用vector进行表示,输出vector第n位
        n -= j*digit;        
        num = pow(10,digit-1)+j;
        vector<int> ans(digit);
        for(int k=0;k<digit;k++){
            ans[digit-k-1] = num%10;
            num /= 10;
        }
        return(ans[n-1]);
    }
};
```
