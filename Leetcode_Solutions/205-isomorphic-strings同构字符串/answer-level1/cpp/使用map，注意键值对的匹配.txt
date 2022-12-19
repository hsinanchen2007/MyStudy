### 解题思路
1.记录键值对，判断是否匹配
2.存在情况，多个key匹配一个value
    如：“ab” "aa"
    这时候，添加b，a键值对的时候就判断一下，a这个value是否已经存在了
    只要判断次数和是否重复，map都是不错的选择

### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> record;//记录key和value
        map<char,int> valueTimes;//防止多个key匹配一个value
        //全员比较
        for(int i=0;i<s.size();i++)
        {
            //key没找到
            if(record.find(s[i])==record.end())
            {
                if(valueTimes[t[i]]==0)
                {
                    valueTimes[t[i]]++;
                    record[s[i]]=t[i];
                }
                else
                    return false; //多个key匹配一个value的情况
            }
            else
            {
                if(record[s[i]]!=t[i])//value不匹配的情况
                    return false;
            }
        }
        return true;
    }
};
```