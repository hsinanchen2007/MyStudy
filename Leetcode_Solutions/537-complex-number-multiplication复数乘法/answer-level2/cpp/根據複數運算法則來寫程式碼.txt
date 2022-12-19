### 解题思路
思路不是很難，細心點就好了

### 代码

```cpp
class Solution {
public:
    string complexNumberMultiply(string a, string b)
    {
        int alen = a.length(), blen = b.length();
        string a1 = "", a2 = "", b1 = "", b2 = ""; //用于获取实部虚部
        int ai, bi; //字符串索引
        //获取实部和虚部
        for (ai = 0; a[ai] != '+'; ai++)
            a1 += a[ai];
        for (ai += 1; a[ai] != 'i'; ai++)
            a2 += a[ai];
        for (bi = 0; b[bi] != '+'; bi++)
            b1 += b[bi];
        for (bi += 1; b[bi] != 'i'; bi++)
            b2 += b[bi];
        int A1 = stoi(a1), A2 = stoi(a2), B1 = stoi(b1), B2 = stoi(b2); //转换为int
        int real = A1 * B1 - A2 * B2, img = A1 * B2 + A2 * B1; //计算实部和虚部
        return to_string(real) + "+" + to_string(img) + "i";
    }
};
```