首先计算出输入IP地址的长度，然后遍历每一个字符。

如果当前字符为'.'，就在它的前后两侧分别加上'['和']'字符。

值得一提的是，C++的String类型提供了以上操作的函数，我们可以直接调用内部函数，使得我们的程序更加简洁，更加清晰明了。

下面给出AC代码:
```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        int len = address.size();//直接计算出IP地址的长度
        for (int i = 0; i < len; i++)//遍历每一个字符
        {
            if (address[i] == '.')//如果当前字符为'.'
            {
                address.insert(i, "[");//在它的前面添加'['字符
                address.insert(i + 2, "]");//在它的后面添加']'字符
                i = i + 2;//由于添加了2个字符,因此当前位置应该加上2
                len = len + 2;//字符串长度也要加上2
            }
        }
        return address;//返回处理好的IP地址
    }
};
```