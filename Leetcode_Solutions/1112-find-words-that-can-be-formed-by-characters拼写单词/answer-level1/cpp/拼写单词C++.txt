
将字母出现的次数放在数组中，如果words[i]中有哪个字母数量超过chars中的字母数量，就跳过该次循环


```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int a[26]={0},j,cnt=0;
        for (j=0;j<chars.length();j++) a[chars[j]-'a']+=1;//对chars做一次统计
        for(int i=0;i<words.size();i++)
        {
            int temp[26]={0};
            for(j=0;j<words[i].length();j++)
            {
                int num=words[i][j]-'a';
                if(temp[num]==a[num]) break;//如果继续操作那么chars中的字母无法满足word[i]
                else temp[num]++;
            }
            if (j==words[i].length()) cnt+=j;
        }
        return cnt;
    }
};
```