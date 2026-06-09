### 解题思路


### 代码

```cpp
class Solution {
  public:
    string addBinary(string a, string b) {
        string str;
        int carry = 0;
        for(int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || carry; --i, --j) {
            int x = i < 0 ? 0 : a[i] - '0';
            int y = j < 0 ? 0 : b[j] - '0';
            int sum = (x + y + carry) % 2;
            carry = (x + y + carry) / 2;
            str.insert(0, 1, sum + '0');
        }
        return str;
    }
};
```