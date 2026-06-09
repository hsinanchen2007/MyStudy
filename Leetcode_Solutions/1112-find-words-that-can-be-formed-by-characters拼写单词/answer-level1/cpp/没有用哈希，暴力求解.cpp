### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int length=words.size();
        if(length==0) return 0;
        int court=0;
        bool flag=0;
        for (int i=0;i<length;i++){//单词循环 vector
            int length1=words[i].size();//3
            string char1=chars;
            for(int j=0;j<length1;j++)//单词字母循环 cat
            {
                int length2=chars.size();//5
                
                //判断当前单词中的字母在不在chars中 atach
                
                for(int k=0;k<length2;k++){
                    flag=0;
                    if(words[i][j]==char1[k])
                    {flag=1;char1[k]='#';break;}//用过的置#
                }
                if(flag==0)  break;
            }
            if(flag==1) court+=length1;
        }
        return court;
    }
};
```