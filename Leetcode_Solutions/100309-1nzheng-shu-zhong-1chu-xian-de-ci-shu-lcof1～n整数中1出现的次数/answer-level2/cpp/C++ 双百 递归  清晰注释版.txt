```
class Solution {
public:
    // 先统计n个位数
    // 递归求解
    // 23456
    // 1~20000 20001~23456->1~3456  ->  3000 3001~3456 -> 1~456 400 401~456 -> 1~56
    int countDigitOne(int n) {
        // 从各位开始到最高位统计
        int number = 0;
        int weishu  = numOfNum(n);  // 位数
        int first = maxOrder(n);  // 最高位
        if(n==0)
            return 0;
        if(weishu==1)
            return 1;   // 1~9只有1个1
        if(first>1){
            number += (first)*pow(10, weishu-2)*(weishu-1)+ pow(10, weishu-1);
            //cout<<number;
            cout<<n % (int)(first*pow(10, weishu-1))<<endl;
            number += countDigitOne(n % (int)(first*pow(10, weishu-1)));
        }
        else{
            number += 1 + (weishu-1)*pow(10, weishu-2) + n-pow(10, weishu-1);
            number += countDigitOne(n % (int)(first*pow(10, weishu-1)));
        }
        return number;
    }
    int numOfNum(int n){
        // n不等于0是成立的
        int x = 0;
        while(n){
            x++;
            n /= 10;
        }
        return x;
    }

    int maxOrder(int n){
        // 取出最大位来
        int x;
        while(n){
            x = n;
            n /= 10;
        }
        return x;
    }
};   
```
