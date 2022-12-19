### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/6105c83aef2a17d6b122eb034434918e50bab343a25a5b8269dbb8d2c3792652-image.png)

### 代码

```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> hash;
        for(int i = 0;i < text.size();i++){
            hash[text[i]]++;
        }
        return min(min(min(min(hash['b'],hash['a']),hash['l']/2),hash['o']/2),hash['n']);
    }
};
```