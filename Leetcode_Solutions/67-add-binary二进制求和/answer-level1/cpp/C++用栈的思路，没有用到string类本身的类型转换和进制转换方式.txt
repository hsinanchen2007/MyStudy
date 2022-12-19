### 解题思路
我的这个内存消耗比较少，C++的代码，没有用到string类本身的类型转换和进制转换方式
具体两个思路    1：短的字符串在前面添'0'，注意是前面添0，然后再进行加减操作
               2：低位先做操作，先入栈，高位后操作，后入栈，然后弹出元素的顺序才是正确的
代码还有很多不足的地方，望各位大神轻喷。
### 代码

```cpp
class Solution {
public:
    std::string addBinary(std::string &a, std::string &b) {
        int x = a.length(), y = b.length();
        int num1 = (x > y) ? x : y;     //获得较大的长度，方便后面的循环
        std::vector<char> res;          //申请一个栈操作类型的数据结构
        if (x < y)
            a.insert(0, (y - x), '0');      //没有足够的长度补0
        else
            b.insert(0, (x - y), '0');      //没有足够的长度补0
        int carray = 0; //进位信息
        for (int value = num1 - 1; value >= 0; value--) {
            int rec = (a[value] - '0') + (b[value] - '0') + carray;     //减去'0'是为了转化为int型
            carray = rec / 2;
            rec %= 2;
            res.push_back(rec + '0');   //+'0'转化为字符
        }
        if (carray)     //遗留的进位
            res.push_back('1');     //注意这里的'1'
        std::string restr;
        while (!res.empty()) {
            restr.append(1, res.back());    //后进栈的是高位，先进栈的是地位
            res.pop_back();
        }
        return restr;
    }
};
```