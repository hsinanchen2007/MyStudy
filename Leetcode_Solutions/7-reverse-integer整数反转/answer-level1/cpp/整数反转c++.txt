给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

```
输入: 123
输出: 321
```
 示例 2:

```
输入: -123
输出: -321
```
示例 3:
```
输入: 120
输出: 21
```

注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31^,  2^31^ − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

##  分析：
由于-2^31^=-2147483648,2^31^-1=2147483647,所以在反转的时候要判断是否溢出，主要检查反转时的最后一位和倒数第二位

## 解法1：

```
class Solution {
public:
    int reverse(int x) {
        int rev=0;//存放反转后的数
        int pop=0;//存放弹出的数
        while(x!=0)
        {
            pop=x%10;//从右往左依次取数进行反转
            x/=10;
            if(rev>INT_MAX/10 || rev==INT_MAX/10&&pop>7) //判断上限
            	return 0;
            if(rev<INT_MIN/10 || rev==INT_MIN/10&&pop<-8) //判断下限
            	return 0;
            rev=rev*10+pop;
        }
        return rev;
    }
};
```
##  解法2：

```
class Solution {
public:
    int reverse(int x) {
        long long_x;
        string str_x=to_string(x);//将数字转换成字符串
        int pos=str_x.find_first_not_of("-");
        //找到第一个与‘-’不匹配的字符位置
        
        std::reverse(str_x.begin()+pos,str_x.end());
        //将除符号位的数字进行反转

        stringstream out(str_x);
        out >>long_x;//将string转换成long存储在long_x中
        if(long_x>INT_MAX || long_x<INT_MIN)
            return 0;
        return long_x;    
    }
};
```
**觉得本文对你有帮助，点个赞噢谢谢**


