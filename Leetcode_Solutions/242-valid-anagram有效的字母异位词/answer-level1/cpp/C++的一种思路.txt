### 解题思路
    考虑特殊情况，如果两字符串长度不同，则一定不是字母异位词。然后回到一般情况，申请26个容器存储每个字符出现的次数，确保每个字符出现的次数一致。

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length())
            return false;
        
        vector<int> ascaii_container(26);//存储26个字母的出现频率
        //对s字符串进行处理，将字符分类计数
        for(int i=0;i<s.length();i++)
        {
            int index=s[i]-'a';
            ascaii_container[index]+=1;
        }

        for(int j=0;j<t.length();j++)
        {
            int index=t[j]-'a';
            if(ascaii_container[index]!=0)
            {
               ascaii_container[index]-=1; 
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
```