```
class Solution {
public:
    // 先统计n个位数
// 递归求解
// 23456
// 1~20000 20001~23456->1~3456  ->  3000 3001~3456 -> 1~456 400 401~456 -> 1~56
// 

    int countDigitOne(int n) {
        // 从各位开始到最高位统计
        int number = 0;
        int weishu  = numOfNum(n);  // 位数
        int first = maxOrder(n);  // 最高位
        if(n==0)
            return 0;
        if(weishu==1)
            return 1;   // 1~9只有1个1
        if(n==10)
            return 2;
        if(weishu==2){
            // 如果最低位是0 就减去1
            // 个位为1，十位有0,1,2...first种选择，01就代表1
            // 十位为1，个位有0,1...个位中选择
            if(first>1){
                number = (first+1) + 10;
            }
            else{  // 十位等于1的情况
                number =  (first+1) + (n-first*10+1);                    // 个位是1，十位有(0, 1)
            }
            // 个位是0，返回值减去1
            if(n-first*10)
                return number;
            else
                return number-1;
        }
        // 大于两位数的开始递归，先求整数位，将余数位递归
        // 最高位大于1
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
