#题目描述
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
#解释
1.代码方法，都放到map中，记录一下字母和出现的次数，比较两个map是否相等。
2.sort一下，看是否相等

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mapString,mapString2;
        for(int i = 0; i<s.length(); i++){
            if(mapString.find(s[i]) == mapString.end()){
                mapString.insert(make_pair(s[i],1));
            } else{
                auto achar = mapString.find(s[i]);
                ++achar->second;
            }
        }
        for(int i = 0; i<t.length(); i++){
            if(mapString2.find(t[i]) == mapString2.end()){
                mapString2.insert(make_pair(t[i],1));
            } else{
                auto achar2 = mapString2.find(t[i]);
                ++achar2->second;
            }
        }
        return mapString==mapString2;
    }
};

```