```
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> c(26,0);
       
        int res = 0;
        int flag = 1;
        for(int i = 0;i<chars.length();i++)
        {
            c[int(chars[i]-'a')] += 1;
        }
        for(int i = 0;i<words.size();i++)
        { 
            vector<int> t(26,0);
            for(int j =0;j<words[i].length();j++)
            {
                t[int(words[i][j]-'a')] += 1;
            }

            for(int k =0;k<26;k++)
            {
                if(t[k]>c[k])
                 {
                    flag = 0;
                 }
            }
            if(flag)
            {res += words[i].length();}
            flag = 1;

        }
        return res;
    }
};
```
遇到这种统计字母个数，感觉利用ASCII码和数组很方便，但是一直没试过数组解法快还是hashtable更快。