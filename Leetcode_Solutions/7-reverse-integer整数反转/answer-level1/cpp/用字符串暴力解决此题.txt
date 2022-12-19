### 解题思路
先用一个longlong型的变量b来代替x，把该变量转成string类型，直接string类型的函数进行反转，再重新输入b，判断b是否再int范围内，如果不在就返回0，如果在就根据x的正负输出结果。

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        long long b=0;
        long long res;
        b=x;
        if(b<0)
            b=b*(-1);
        string str_x = to_string(b);
 	    std::reverse(str_x.begin(), str_x.end());
 	    stringstream out(str_x);
 	    out >> res;
        if (res<INT_MIN||res>INT_MAX)
            return 0;
        if(x<0)
            return res*(-1);
        return res;
    }
};
```