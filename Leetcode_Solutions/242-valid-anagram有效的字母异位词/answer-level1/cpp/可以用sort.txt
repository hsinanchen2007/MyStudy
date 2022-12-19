### 解题思路
此处撰写解题思路
先把两个字符串排序，这样就不存在异位了。我们再遍历两个字符串比较，如果有哪个位置不相等那肯定是错的。
反之，如果遍历完了，那就说明两个串是异位词。
### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();++i){
            if(s[i]!=t[i]){
                return false;
            }
        }
        return true;
    }
};
```