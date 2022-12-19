看到题解并没有c++的写法，就仿写了一个powcai的写法。52ms。

```
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> word_map;  // unordered_map 采用hash实现，查找快； map内部采用红黑树，有序。
        vector<int> result;
        if (s=="" || words.size()==0)
            return result;
        
        int word_len = words[0].size();
        int word_num = words.size();
        if (s.size() < word_len * word_num)
            return result;
        
        for (int i=0;i<word_num;i++) {
            if (word_map.count(words[i]) == 0)
                word_map[words[i]] = 1;
            else
                word_map[words[i]]++;
        }
        
        for (int i=0;i<word_len;i++) {
            int left = i;
            int right = i;
            unordered_map<string, int> find_map; // 查找map
            int count = 0;   // 匹配个数
            while (right + word_len <= s.size()) {
                string cur = s.substr(right, word_len);
                count++;
                right += word_len;
                if (word_map.count(cur) == 0) { // 遇到不在字典里的字符，直接清空，跳过
                    count = 0;
                    find_map.clear();
                    left = right;
                    continue;
                }
                if (find_map.count(cur) == 0)
                    find_map[cur] = 1;
                else
                    find_map[cur]++;
               
                while (find_map[cur] > word_map[cur]) { // 个数使用过多，区间左半边向前移动
                    string lefts = s.substr(left, word_len);
                    left += word_len;
                    find_map[lefts]--;
                    count--;
                }
                if (count == word_num)
                    result.push_back(left);
            }
        }
        return result;
    }
};
```


