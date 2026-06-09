### 解题思路
搞懂二进制是怎么相加的原理，就简单了，1+1结果是0并且进位1

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) 
    {
        int aLen = a.size();
        int bLen = b.size();
        int i(aLen-1), j(bLen-1);
        int carry(0);
        vector<char> calcPath;
        while (i >= 0 || j >= 0 || carry)
        {
            char up(' ');
            char down(' ');
            if (i >= 0)
            {
                up = a[i];
            }
            if (j >= 0)
            {
                down = b[j];
            }
            if (up == '1' && down == '1' && carry)
            {
                calcPath.push_back('1');
            }
            else if (up == '1' && down == '1')
            {
                calcPath.push_back('0');
                carry = 1;
            }
            else if ( (up == '1' || down == '1') && carry )
            {
                calcPath.push_back('0');
                carry = 1;
            }
            else if ( (up == '1' || down == '1') )
            {
                calcPath.push_back('1');
            }
            else if ( carry )
            {
                calcPath.push_back('1');
                carry = 0;
            }
            else
            {
                calcPath.push_back('0');
            }
            i--;
            j--;
        }
        string result;
        while (calcPath.size())
        {
            result += calcPath.back();
            calcPath.pop_back();
        }
        return result;
    }
};
```