### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int minDistance = INT_MAX;
        bool flag1 = false;
        bool flag2 = false;
        int index1 = 0;
        int index2 = 0;
        for (int i = 0; i < words.size(); i++) {
            if (word1 == words[i]) {
                flag1 = true;
                index1 = i;
                if (flag2) {
                    flag2 = false;
                    minDistance = min(abs(index1 - index2), minDistance);
                }
            } else if (word2 == words[i]) {
                flag2 = true;
                index2 = i;
                if (flag1) {
                    flag1 = false;
                    minDistance = min(abs(index1 - index2), minDistance);
                }
            }
        }
        return minDistance == INT_MAX ? 0 : minDistance;
    }
};
```