### 解题思路
1.使用hash_map给magainze中所有的出现的字符进行计数。
2.遍历赎金信是查找hash_map中计数其是否为0，若为0说明字母不够返回false，若没找到字符说明缺字符也返回false，检查全通过才能返回true。

### 代码

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
           unordered_map<char,int> char_counts;

    for(int i = 0;i < magazine.length();i++){
        char_counts[magazine[i]]++;
    }

    for(int i = 0;i < ransomNote.length();i++){
        if(char_counts.find(ransomNote[i]) == char_counts.end()){
            return false;
        }
        else if(char_counts.find(ransomNote[i]) != char_counts.end()){
            unordered_map<char,int>::iterator char_counts_iter = char_counts.find(ransomNote[i]);
            if(char_counts_iter->second == 0){
                return false;
            }
            else{
                char_counts[ransomNote[i]]--;
            }
        }
    }
    return true;
    }
};
```