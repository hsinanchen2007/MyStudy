### 解题思路
利用有序map记录元素出现次数，并判断奇数次元素是否大于一。

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> record;
        map<char, int>::iterator iter;
        for(int i = 0; i < s.length(); i++)
        {
            record[s[i]]++;
        }
        int cnt = 0;
        for(iter = record.begin(); iter != record.end(); iter++)
        {
            if((iter->second % 2) != 0){
                cnt++;
            }
        }
        if(cnt > 1){
            return false;
        }else{
            return true;
        }
    }
};
```