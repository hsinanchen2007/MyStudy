### 解题思路
这种“顺序打乱”的题目，两种解法：
1.排序遍历（既然乱序，那就排个序，双指针遍历即可）
2.采用某种数据结构统计chars和words[i]里面字母出现次数，看是否能够覆盖，类似于“字典”（1.映射的话map 2.这里只有26个字母且字母含有递增关系，用数组即可，索引O(1)）
### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if(words.empty()) return 0;
        //此题可以选择用字符计数方法
        //看char里面的字符数是否将words[i]的的所有字符都覆盖
        //字母顺序打乱，就可以考虑排序和计数
        sort(chars.begin(),chars.end());
        int sumLength = 0;
        for(int i = 0;i < words.size();++i){
            sort(words[i].begin(),words[i].end());
            int charsIndex = 0,wordIndex = 0;
            while(charsIndex < chars.size() && wordIndex < words[i].size()){
                if(chars[charsIndex] != words[i][wordIndex])
                   ++charsIndex;
                else{
                    ++charsIndex;
                    ++wordIndex;
                }
            }
            sumLength += (wordIndex == words[i].size()) ? words[i].size() : 0;
        }
        return sumLength;
    }
};
```