### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        // 结果从低位到高位暂时保存
        string ret;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int tmp = (i >= 0 ? (a[i] - '0') : 0) +  (j >= 0 ? (b[j] - '0') : 0) + carry;
            carry = tmp / 2;
            ret.push_back(tmp % 2 + '0');
            i--; j--;
        }
        if(carry == 1) ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

```