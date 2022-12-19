### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
    
        vector<char> ch = chars;
        chars.clear();
        int count = 1;  //统计连续字符的数量
        //char c = ch[0];
       // cout << "ch.size()" << ch.size() - 1 << endl;
        for(int i = 0; i < ch.size() - 1; i++)
        {
            //cout << i + 1 << endl;
            //前后两个字符相同
            if(ch[i] == ch[i + 1])
                count++;
            else
            {
            //前后两个字符不同
                chars.push_back(ch[i]);
                if(count > 1)
                {
                   string s(to_string(count));
                   for(auto c : s)
                        chars.push_back(c);
                   //cout << s << endl;
                }
                count = 1;
            }
        }
        
        chars.push_back(ch[ch.size() -1]);
        if(count > 1)
        {
            string s(to_string(count));
            for(auto c : s)
                chars.push_back(c);
        }
        return chars.size();
    }
};
```