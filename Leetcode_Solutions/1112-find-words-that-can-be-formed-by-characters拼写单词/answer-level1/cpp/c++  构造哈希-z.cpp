### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> mp(26);                   //构造哈希数组
        int len = 0;
        for(char c : chars)            
            mp[c-'a']++;

        for(string word : words)
        {
            vector<int> temp(mp); ;             //每次拼写都使用原来的哈希数组进行验证
            bool flag=true;                     //flag表示是否掌握这个单词
            for(char n : word)
            {
                if(temp[n-'a'] -- <= 0)         //判断该字母的出现次数是否大于掌握的次数
                {
                    flag=false;
                    break;
                }
            }
            
            if(flag)        len += word.size();                        
        }
        return len;
    }
};
```