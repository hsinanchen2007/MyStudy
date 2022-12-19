### 解题思路
1.% /的用法  取模运算得到 n 的最后一位对于数字来说，一般要善于运用 n%10来达到遍历的效果。对于字符串来说，一般要善于运行char来达到遍历的效果
2.检查的思路：循环是否跳出，运算逻辑是否正确

另一种思路：数字转换为字符串然后对字符串遍历。
即本题的实质需求是实现数字遍历，实现遍历主要就两种思路的方法。

知识点：to_string()函数：
to_string() 函数无法处理非十进制整数的转换。如果需要该功能，则应该使用 ostringsteam 对象来完成该转换。
	1. 
int a = 5;
	2. 
string str = to_string(a*a);
	3. 
cout << " The square of 5 is " << str << endl;



数字转字符串：
用stringstream即可把多种数值类型转换为String类型的字符串


atof(s)
将字符串s[n]转换为双精度浮点型值。
 atoi(s)
将字符串s[n]转换为整型值。
 atol(s)
将字符串s[n]转换为长整型值。






字符串的遍历：
for(int i=0;i<str.size();i++)
{
str[i];
}

string::iterator it=str.begin();
while(it!=str.end())
{
*it;
}

for(auto ch:str)
{

ch;
}

错误代码分析：
for(auto ch:str )
        {
            muti*=muti*atoi(ch);
            sum+=atoi(ch);
        }
注意这里ch为char即字符，而atoi的作用目标是字符串
两者不同所以会报错

整数转化为字符串：加 ‘0’ ，然后逆序
字符串转化为数字：减'0'。

错误提示：
编译报错：error: stray '\357' in program
原因：在程序中打入了全角字符

### 代码

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int muti=1;
        int sum=0;
        string str=to_string(n);
        for(auto ch:str )
        {
            muti*=(ch-'0');
            sum+=(ch-'0');
        }
        return muti-sum;
        
    }
};
```