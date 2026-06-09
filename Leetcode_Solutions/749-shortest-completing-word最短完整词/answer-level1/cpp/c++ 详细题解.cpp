### 解题思路
将licensePlate中的字母个数存到数组m1中，再依次将每个单词中字母出现的次数存到数组m2中，每存完一个单词就判断一下是否符合条件，不符和条件的话，令flag=0，跳出循环；符合条件的话，将flag置1。但是符合条件后不能直接输出，因为要找出一个最短的完整词。所以可定义一个string变量ans，用来实时更新结果，保存最短的完整词。

觉得有帮助的话，欢迎点赞或评论😄

### 代码

```cpp
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int m1[26]={0};
        for(int i=0;i<licensePlate.size();i++)
            if(isalpha(licensePlate[i]))
                m1[tolower(licensePlate[i])-'a']++;//将licensePlate中字母出现的次数存到m1
        int flag=0;
        string ans="";
        for(int i=0;i<words.size();i++)
        {
            int m2[26]={0};
            for(int j=0;j<words[i].size();j++)
                m2[tolower(words[i][j])-'a']++;//将单词中字母出现的次数存到m2
            
            for(int k=0;k<26;k++)
            {
                if(m1[k]>m2[k])//若m1中字母出现次数多
                {
                    flag=0;//则跳出循环
                    break;
                }
                else
                    flag=1;//否则将flag置1
            }
            if(flag)
            {
                if(ans.size()==0)//如果ans为空，则将word[i]赋给ans
                    ans=words[i];
                else //若ans不为空，就比较ans和word[i]的长度
                    if(words[i].size()<ans.size())
                        ans=words[i];   
            }        
        }
        return ans;
    }
};
```