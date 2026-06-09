### 解题思路
使用哈希表存储 字符, <频数, 索引>

### 代码

```java []
class Solution {
    public int firstUniqChar(String s) {
        // 空间换时间
        char []rec = new char[26];
        char []A = s.toCharArray();

        for(int i=0; i<A.length; ++i){
            rec[A[i]-'a']++;
        }

        for(int i=0; i<A.length; ++i){
            if(rec[A[i]-'a']==1)
                return i;
        }
        
        return -1;
    }
}
```
```python []
class Solution:
    def firstUniqChar(self, s: str) -> int:
        M = 26
        rec = [0 for _ in range(M)]
        for i in range(0, len(s)):
            rec[ord(s[i])-ord('a')]+=1

        for i in range(0, len(s)):
            if rec[ord(s[i])-ord('a')] == 1:
                return i

        return -1
```
```c++ []
class Solution {
public:
    int firstUniqChar(string s) {
        // 建立哈希表, 字符, <频数, 索引>
        map<char, pair<int, int>> rec;
        for(int i=0; i<s.size(); ++i){
            if(rec.count(s[i])==0){
                rec[s[i]] = make_pair(1, i);
            }
            else{
                rec[s[i]].first++;
            }
        }

        vector<int> res;
        for(auto mit=rec.begin(); mit!=rec.end(); ++mit){
            if(mit->second.first == 1)
                res.push_back(mit->second.second);
        }

        if(res.empty())
            return -1;
        else{
            sort(res.begin(), res.end());
            return res[0];
        }
    }
};
```