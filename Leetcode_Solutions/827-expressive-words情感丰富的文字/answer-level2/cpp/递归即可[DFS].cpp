### 解题思路
此处通过DFS进行直接验证。

### 代码

```cpp
class Solution {
public:
    int count = 0;
    int expressiveWords(string S, vector<string>& words) {
        for (string word : words) {
            Dfs(S, 0, word, 0);
        }
        return count;
    }

    void Dfs(string S, int index1, string word, int index2) {
        if (index1 >= S.size() && index2 >= word.size()) {
            count++;
            return;
        }
        if (S[index1] == word[index2]) {
            int count1 = 1;
            int count2 = 1;
            while (S[index1] == S[index1 + 1]) {
                index1++;
                count1++;
            }
            while (word[index2] == word[index2 + 1]) {
                index2++;
                count2++;
            }
            if ((count1 >= 3 && count1 > count2) || count1 == count2) {
                index1++;
                index2++;
                Dfs(S,index1, word, index2);
            }
        }
        return;
    }
};
```