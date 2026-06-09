### 解题思路
哈希表存储字母和对应的索引，判断字符串先后关系的时候要用到
然后比较两个字符串，选较短的长度来比较
a[i]对应的字典中的索引为indexA;
b[i]对应的字典中的索引为indexB;
如果indexA < indexB, 直接返回true;
如果indexA > indexB, 直接返回false;
如果前minLen个字符都相等的话，最后判断下字符串的长度

### 代码

```cpp
class Solution {
public:
    bool compare(string& a, string& b, unordered_map<char, int>& mp) {
        int sizeA = a.size();
        int sizeB = b.size();
        int minLen = sizeA > sizeB ? sizeB : sizeA;
        int same = 0;
        for (int i = 0; i < minLen; i++) {
            if (mp[a[i]] < mp[b[i]]) {
                return true;
            } else if(mp[a[i]] > mp[b[i]]) { 
                return false;
            }else if (mp[a[i]] == mp[b[i]]) {
                same++;
            }
        }
        
        if (same == minLen) {
            return a.size() < b.size();
        }
        
        return false;
        
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for (int i = 0; i < 26; i++) {
            mp[order[i]] = i;
        }
        int size = words.size();
        if (size == 1) {
            return true;
        }
        
        for (int i = 0; i < (size - 1); i++) {
            if (compare(words[i], words[i+1], mp) == false) {
                return false;
            }
        }
        return true;
    }
};
```