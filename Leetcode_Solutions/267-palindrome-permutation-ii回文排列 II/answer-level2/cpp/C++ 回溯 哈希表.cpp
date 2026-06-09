### 解题思路
1. 先判断是否能够排列成回文，否则返回空；
2. 根据上一步统计出来的字符数量，如果有奇数个的字符，则要保存一下，后面放到字符串中央位置；
3. 偶数个的字符取一半放在临时string中；
4. 再使用 [47.全排列 II] 的算法稍加改造。

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s, map<char, int>& m) {
        for (char ch : s) {
            if (m.find(ch) == m.end()) {
                m[ch] = 1;
            } else {
                ++m[ch];
            }
        }
        int cnt = 0;
        for (auto item : m) {
            if (item.second % 2 == 1) {
                ++cnt;
            }
        }
        return (cnt == 1 || cnt == 0);
    }
    
    void backtrace(int len, map<char, int>& numsMap, int ch, string& record, vector<string>& ans) {
        if (record.size() == len) {
            string f(record);
            string r = string(record.rbegin(), record.rend());
            if (ch != -1) {
                f.push_back(ch);
            }
            f.append(r);
            ans.push_back(f);
            return ;
        }
        for (auto& m : numsMap) {
            if (m.second == 0)
                continue ;
            --m.second;
            record.push_back(m.first);
            backtrace(len, numsMap, ch, record, ans);
            record.pop_back();
            ++m.second;
        }
    }
    
    vector<string> permuteUnique(string& nums, int ch) {
        map<char, int> numsMap;
        for (int n : nums) {
            ++numsMap[n];
        }
        string record;
        vector<string> ans;
        backtrace(nums.size(), numsMap, ch, record, ans);
        return ans;
    }
    
    vector<string> generatePalindromes(string s) {
        vector<string> ans;
        map<char, int> m;
        if (!canPermutePalindrome(s, m)) {
            return ans;  // 不能排列成回文，返回空
        }
        
        int ch = -1;
        string half;
        for (auto item : m) {
            if (item.second % 2 == 1) {  // 奇数个字符，取一个放在字符串中央
                ch = item.first;
            }
            for (int i = 0; i < item.second / 2; ++i) {  // 只需排列一半的字符
                half.push_back(item.first);
            }
        }
        
        return permuteUnique(half, ch);  // 使用 [47.全排列 II] 的算法改造成
    }
};
```

![image.png](https://pic.leetcode-cn.com/3603464eab3735d227bdec546a750174fc7487aa1219e280268da24ce93da58a-image.png)
