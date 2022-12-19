### 解题思路
1.第一次做这题的时候思路很简单，就是在循环里使用string的find和erase方法，找到一个删除一个，找不到了就退出。这样做是完全按照题目描述内容去解决问题，时间复杂度较高，O(m*n)，每次删除之后再匹配都需要从匹配字符的首位开始查找。
2.再回顾这题时注意到一行字：“所有字符串中都仅包含小写英文字母”，也就是只会有26个字符，那么就想到了类似哈希表的用法，直接用int数组把每个单词的数量给记下来，每遇到一个单词对应的哈希表项就减一，如果减到了负数那就代表单词不够了。时间复杂度从O(m*n)变为了O(m+n)，时间和内存消耗都有所优化。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int suml=0;
        int letter[26]={0};
        int count[26];
        int flag=0;
        for(int i=0;i<chars.length();i++){
            letter[chars[i]-'a']++;
        }
        for(auto str : words){
            flag=0;
            for(int i=0;i<26;i++){
                count[i]=letter[i];
            }
            for(int i=0;i<str.length();i++){
                count[str[i]-'a']--;
                if(count[str[i]-'a']<0){ flag=-1;break; }
            }
            if(flag!=-1){ suml+=str.length(); }
        }
        return suml;
    }
};
```