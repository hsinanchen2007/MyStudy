最简单的方法就是使用c++中的stringstream类将整数转化为字符串并进行反转。
我们知道int型的最小值是1<<31，最大值为unsigned(1<<31)-1。而最小值在int范围内没有对应的绝对值，所以在刚开始首先进行判断。
将要反转的数的绝对值进行反转，因为反转后得到的整数值可能超出int型的范围，所以使用long long型保存。
最后将反转后的整数值与int型最大值进行比较，若大于最大值，则溢出；否则返回反转后的整数值与符号位的乘积。
```
class Solution {
public:
    int reverse(int x) {
        int min=(1<<31);
        unsigned max=(unsigned)min-1;
        if(x==min) return 0;//特殊条件，int型最小值在int范围内没有对应的绝对值
        int tmp=abs(x);//取绝对值
        stringstream str;
        str<<tmp;
        string s="";
        str>>s;
        std::reverse(s.begin(),s.end());//反转整数字符串
        str.str("");
        str.clear();
        str<<s;
        int up=(x>=0)?1:-1;//判断符号位
        //为防止超出int范围，用long long保存
        long long ans;
        str>>ans;
        //与最大值进行比较判断是否溢出
        if(ans>max) return 0;
        else return (int)(ans*up);
        
        return 0;
    }
};
```