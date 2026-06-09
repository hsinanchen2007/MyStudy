### 解题思路


### 代码

```cpp
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        unordered_map<string, int> mp;
        for(int i = 0 ; i < s.length() ; ++i)
        {
            string temp = s.substr(i, minSize);
            if(temp.length() < minSize)
                break;
            int hashTable[126] = {0};
            bool flag = true;
            int letterCnt = 0;
            for(int j = 0 ; j < temp.length() ; ++j)
            {
                if(hashTable[temp[j] - '0'] == 0)
                    letterCnt++;
                hashTable[temp[j] - '0']++;
                if(letterCnt > maxLetters)
                {
                    flag = false;
                    break;
                }
            }
            if(!flag)
                continue;
            mp[temp]++;
            ans = max(ans, mp[temp]);
        }
        return ans;
    }
};
```