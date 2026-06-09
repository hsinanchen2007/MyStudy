### 解题思路
这是一个像 转换进制的题

### 代码

```cpp
class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n){
            n--;
            string str = "";
            str +=  'A' + n%26;
            ans = str.append(ans);
            n /= 26;
        }
        return ans;
    }
};
```