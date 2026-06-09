### 解题思路
此题主要是题目意思不太容易懂，一开始我看了好久，才发现其实题目意思是让我们判断所给的几个外星词语直接是否按外星词典排序。
1. 先用map存储外星语词典顺序
2. 比对相邻词语同个位置字母
    a. 如果这两个字母违反词典顺序，则返回false
    b. 如果这两个字母相等，若前面的词语已到最后一个字母而后一个词还未到最后一个字母，则返回false；否则，继续步骤2
    c. 如果这两个字母符合词典顺序，则比对下一组相邻词语

### 代码

```cpp
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> oreder_map;
        for(int i = 0; i < order.length(); i ++) {
            order_map[order[i]] = i;
        }
        for(int j = 1; j < words.size(); j ++) {
            for(int i = 0; i < min(words[j - 1].length(), words[j].length()); i ++) {
                if(order_map[words[j - 1][i]] > order_map[words[j][i]]) {
                    return false;
                }
                else if(order_map[words[j - 1][i]] == order_map[words[j][i]]) {
                    if((i + 1 == words[j].length()) && (i + 1 < words[j - 1].length())) {
                        return false;
                    }
                    continue;
                }
                else {
                    break;
                }
            }
        }
        
        return true;
    }
};
```