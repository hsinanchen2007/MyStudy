### 解题思路
看到楼上甜姨,官方给出的诸多妙计,真是令我叹为观止,但是杀鸡焉用牛刀?
既然这道题的数据里没有给出这样的结构: 字母 + 空格 + 数字
那我们就可以利用C++的"sstream"头文件中ostringstream 和 istringstream两个对象,,改变输入流

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str)
{
    int num=0;
    istringstream str_1(str);
    //while (num==0)
        str_1 >> num;
    if (num > INT_MAX)
        return INT_MAX;
    else if (num < INT_MIN)
        return INT_MIN;
    else
        return num;
}
};
```