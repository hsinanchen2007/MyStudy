### 解题思路
需要先排序字符，方便后面剔除掉重复的排列情况，然后递归处理就好了

### 代码

```cpp
class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> ans;
        
        // 这里需要先排序，方便后面剔除掉重复的排列情况
        sort(S.begin(), S.end());
        perm(S, 0, ans);

        return ans;
    }
    void perm(string &s, int begin, vector<string> &ans) {
        if(begin == s.size()) {
            ans.push_back(s);
            return;
        }

        for(int i = begin; i < s.length(); i++) {
            // 第一次交换是 i 和 begin之间
            // 后续的交换是 i 和 i-1，以上两种特殊的情况都要剔除掉
            if(i > begin && (s[i] == s[begin] || s[i] == s[i-1])) 
                continue;
            // 交换字符后，开始考虑下一个字符
            swap(s[begin], s[i]);
            perm(s, begin+1, ans);
            // 操作完后，需要将字符交换回去。
            swap(s[begin], s[i]);
        }
    }
};
```