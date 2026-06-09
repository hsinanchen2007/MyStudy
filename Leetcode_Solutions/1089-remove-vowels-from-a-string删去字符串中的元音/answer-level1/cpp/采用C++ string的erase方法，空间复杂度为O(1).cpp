### 解题思路
 S.erase(i,1)表示删除第i项的1个字母，如果是S.erase(i,2)，则代表2个字符；
另外关键的一点--i，因为如果两个元音字母是连续的，那么当删除第一个元音字母S[i]时，需要回到之前的位置才是下一个元音字母，否则就会直接跳过第二个。

### 代码

```cpp
class Solution {
public:
    string removeVowels(string S) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        for(int i = 0; i<S.size(); ++i){
            if (vowels.count(S[i])==1){
                S.erase(i,1);
                --i;
            }
        }
        return S;
    }
};
```