### 解题思路
分治法：
1. 先用一个map存储所有字母的出现次数
2. 遍历一次查看是否所有字母都满足，如果满足就返回整个字符串的长度
3. 如果不满足，这些不满足的字母将成为截断字符；遍历字符串截断得到多个子串，递归处理。

![截屏2020-03-15下午7.33.36.png](https://pic.leetcode-cn.com/f852aacea74cdf538e10adfd507c10bcc1efac5d9dc8c96e5c03f3debf903a6d-%E6%88%AA%E5%B1%8F2020-03-15%E4%B8%8B%E5%8D%887.33.36.png)

### 代码

```cpp
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s=="") return 0;
        map<int, int> counts;
        for(auto w:s){
            auto it = counts.find(w);
            if(it==counts.end()) counts[w] = 1;
            else counts[w]++;
        }
        bool isAll = true;
        for(auto it = counts.begin();it!=counts.end();it++){
            if(it->second<k){
                isAll = false;
                break;
            }
        }
        if(isAll) return s.size();
        int maxCounts = 0;
        for(int i=0;i<s.size();i++){
            int start = i, nums = 0;
            while(i<s.size()&&counts[s[i]]>=k) {
                nums++;
                i++;
            }
            if(nums>0) maxCounts = max(longestSubstring(s.substr(start, nums), k), maxCounts);
        }
        return maxCounts;
    }
};
```