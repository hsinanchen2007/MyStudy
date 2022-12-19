### 解题思路
1. 统计`chars`的每个字符的个数
2. 统计`words`数组中每个单词的字符数，判断`步骤1.`统计的字符数量是否能满足`words`中的某个单词
3. 若满足某个单词，代表能掌握该单词，记录长度只和的变量`ans`要加上该单词的长度

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        unordered_map<char, int> mp_t;
        for(char c: chars) mp_t[c] ++;
        unordered_map<char, int> mp_s;
        for(string word: words){
            mp_s.clear();
            // 统计每个单词
            for(int i = 0; i < word.size(); i++){
                mp_s[word[i]] ++;
            }
            int tmp = 0;
            bool flag = true;
            for(auto pr: mp_s){
                char cur = pr.first;
                int cnt = pr.second;
                tmp += cnt;
                if(mp_t.count(cur) && mp_t[cur] >= cnt) continue;
                else flag = false;
            }
            if(flag == true){
                ans += tmp;
            }
        }
        return ans;
    }
};
```