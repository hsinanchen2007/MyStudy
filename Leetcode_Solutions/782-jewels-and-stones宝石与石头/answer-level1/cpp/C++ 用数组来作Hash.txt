### 解题思路
注意：大小写字母的ASCII码不是连续的！

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int length = 'z' - 'A' + 1;
        int mp [length];
        for(int i = 0; i < length; i++){
            mp[i] = 0;
        }

        for(char j:J){
            mp[j - 'A'] = 1;
        }

        int count = 0;
        for(char s:S){
            count += mp[s - 'A'];
        }
        return count;
    }
};
```