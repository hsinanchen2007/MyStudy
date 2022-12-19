### 解题思路
不太懂递归，所以，一定要把递归改成循环来完成
假设两个串A, B满足有该题要求的最大公因子M，那么A = t1*M, B=t2*M，（A+B)=(B+A)=(t1 + t2)*M。 
先判断A+B 是否等于 B+A， 不相等，则没有公因子。相等的话，就找两者长度的最大公因子。并返回字符串从0到公因子的长度即可。

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if((str1 + str2) != (str2 + str1))    return "";
        int res = maxPublicDig(str1.size(), str2.size());
        return str1.substr(0, res);
    }
    
    int maxPublicDig(int a, int b)
    {
        while(a != 0 && b != 0)
        {
            a = a % b;
            if(a == 0)
                break;
            swap(a,b);
        }
        return b;
    }
};
```