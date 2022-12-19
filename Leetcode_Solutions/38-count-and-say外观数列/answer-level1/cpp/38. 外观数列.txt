### 解题思路
从str = “1”开始，遍历“读”str。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string ans{"1"};
        for(int i=2; i <= n; i++) {
            ans = readStr(ans);     // warn：string类的性质，会覆盖写
        }
        return ans;
    }
    string readStr(string str) {
        string ret;
        for(int i=0; i < str.size(); i++) {
            char c = str[i];    // 读到的字符c
            int cnt = 1;        // 记录c的个数
            while(i < str.size() - 1) {
                if(c == str[i+1]) {
                    cnt++;
                    i++;
                }
                else {
                    break;
                }
            }
            ret.push_back((cnt + '0')); //“个数”“字符” 接在新字符串尾
            ret.push_back(c);
        }
        return ret;
    }
};
```
![12.png](https://pic.leetcode-cn.com/b69a8be1157b12460aac15cdcff01d95d88a85e5382a2392b25125210633a8f3-12.png)
