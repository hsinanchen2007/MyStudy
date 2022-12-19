### 解题思路
Short Encoding of Words
### 代码

```cpp
class Solution {
public:
    bool Match(string s1,string s2){
        for(int i = 0;i < s1.length();i++)
        {
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        if(n == 0) return 0;
        else if(n == 1) return words[0].size()+1;
        else
        {
            for(int i = 0;i < n;i++) reverse(words[i].begin(),words[i].end());
            sort(words.begin(),words.end());
            int ans = words[n-1].size()+1;
            for(int i = 0;i < n-1;i++)
            {
                if(Match(words[i],words[i+1])==0)
                {
                    ans += words[i].size()+1;
                }
            }
            return ans;
        }
    }

};
```