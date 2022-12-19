### 解题思路
如果字符串为另一个字符串子串，那么其子串依旧是。所以没必要求字符串子串。遍历一次数组，然后判断两两是否为子串。
为子串的条件：一次往前搜索，有一个搜索不到就跳出。

### 代码

```cpp
class Solution {
public:
    bool IsSunStr(string s1, string s2)
    {
        int cIndex = 0;
        bool flag = true;
        for (int i = 0; i < s1.size(); i++) {
            cIndex = s2.find(s1[i], cIndex);
            if (cIndex == s2.npos) {
                flag = false;
                break;    
            }
            cIndex++;
        }
        return flag;
    }
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        for (int i = 0; i < strs.size(); i++) {
            bool flag = true;
            for (int j = 0; j < strs.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (IsSunStr(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                int length =  strs[i].size();
                ans = max(ans, length);
            }
        }
        return ans;
    }
};
```