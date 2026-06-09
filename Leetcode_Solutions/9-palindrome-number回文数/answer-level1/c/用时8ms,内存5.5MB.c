### 解题思路
此处撰写解题思路
首先定义x_x变量保留x的值作为while循环之后的判断条件，然后定义trans作为将x翻转的中间数并初始化为0（初始化为0是一个很巧妙的技巧，将会在第3个if判断显示出来）.
第一个if判断语句排除负数；
第二个if判断语句排除个位为0的的数（二位数以上的数）；
while循环将数值翻转;
第三个if判断语句判断翻转后的数据是否和x_x保留的初始值相同，若x初始值为0，则直接调到第三个判断语句，由于trans初始值为0，刚好符合，所以可以直接判断出0也是回文数。
### 代码

```c
bool isPalindrome(int x){
long trans=0;
int x_x=x;

if(x<0 )
    return false;
if(x%10 == 0 && x > 10)
        return false;

while(x)
{
    
    trans=trans*10+x%10;
    x=x/10;
}
if(x_x==trans)
{
    return true;
}
else
    return false;
}
```