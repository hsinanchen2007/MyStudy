### 解题思路
参考了breezean的优化版竖式(打败99.4%)中优化竖排相乘的思路。
这里不用检查sum是否overflow因为最后都是以string的形式返回结果的。
但是自己犯了一个错误，为了减少空间复杂度，在两层for循环的时候，使用了unsigned char作为index，但是这样就算index到了0再减1也不会出现负值，而是直接到了255，还是可以继续进入循环，引起了数组越界。
string中at函数会检查传入的index是否越界并抛出out of range的错误。

### 代码

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if ((num1 == "0") || (num2 == "0"))
            return "0";
        unsigned char num1_length = num1.size();
        unsigned char num2_length = num2.size();
        unsigned char* res = new unsigned char[num1_length + num2_length];
        unsigned char n1 = 0;
        unsigned char n2 = 0;
        unsigned char sum = 0;
        for (unsigned char i = 0; i < (num1_length+num2_length); i++)
            res[i] = 0;
        for (int i = (num1_length - 1); i >= 0; i--)
        {
            n1 = (num1.at(i) - '0');
            for (int j = (num2_length - 1); j >= 0; j--)
            {
                n2 = (num2.at(j) - '0');
                sum = (res[i+j+1] + n1*n2);
                res[i+j+1] = (sum % 10);
                res[i+j] += (sum / 10);
            }
        }

        string result;
        for (unsigned char i = 0; i < (num1_length+num2_length); i++)
        {
            if (i==0 && res[i]==0)
                continue;
            result.push_back('0' + res[i]);
        }
        delete[] res;
        return result;
    }
};
```