### 解题思路
这题用Hashmap做就可以吧。
1.对magazine使用Hashmap统计出现的字符及次数
2.扫描ransomNote，如果出现没有的字符或者次数不够了，都返回false;

### 代码

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int> m;
        for(int i=0; i<magazine.length(); i++){
            m[magazine[i]]++;
        }
        for(int i=0; i<ransomNote.length(); i++){
            auto c = m.find(ransomNote[i]);
            if(c == m.end() || (c != m.end() && c->second == 0)){
                //没找到，或者找到但是字符数不够
                return false;
            }
            else{
                //找到了，字符数又够
                c->second--;
            }
        }
        return true;
    }
};
```