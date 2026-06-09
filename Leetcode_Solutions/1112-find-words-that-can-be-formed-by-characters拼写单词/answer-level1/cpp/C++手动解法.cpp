### 解题思路
对比字母数量就完事了

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int div[26]={0};
        int sum=0;
        int lens=(int)chars.length();
        for(int i=0;i<lens;++i)
        {
            ++div[chars[i]-'a'];
        }
        for(int i=0;i<(int)words.size();++i)
        {
            int tmp[26]={0};
            for(int j=0;j<(int)words[i].size();++j)
            {
                ++tmp[words[i][j]-'a'];
            }
            int ok=1;
            for(int k=0;k<26;++k)
            {
                if(tmp[k]>div[k])
                {
                    ok=0;
                    break;
                }
            }
            if(ok) sum+=(int)words[i].size();
        }
        return sum;
    }
};
```