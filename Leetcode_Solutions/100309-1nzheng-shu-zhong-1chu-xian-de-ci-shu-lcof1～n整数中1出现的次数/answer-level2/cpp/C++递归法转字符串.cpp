### 解题思路
先把n转为string，记录首位数字是几；
把n分为两部分，用without记录；
对于大于without部分，先计算最高位1有多少个（分最高位是1和大于1讨论）；再计算其他位1的个数；
对于小于without部分，递归；直到个位。


### 代码

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;
        if(n<10) return 1;
      
        string s=to_string(n);//转化为字符串
        int size=s.size();//几位数
        int high=s[0]-'0';//记录首位数是几
        int without=n-high*pow(10,size-1);//划分(1~without),(without+1,n)
        //先来搞without+1~n
        int num1=0;//最高位1的个数
        if(high==1) num1=without+1;
        else num1=pow(10,size-1);
        int num2=0;//除最高位外其他位数为1的个数
        num2=high*pow(10,size-2)*(size-1);
        return num1+num2+countDigitOne(without);
        


    }
};
```