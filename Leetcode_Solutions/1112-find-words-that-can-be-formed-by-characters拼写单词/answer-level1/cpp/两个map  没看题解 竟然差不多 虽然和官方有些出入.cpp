### 解题思路
一个map用来保存原来的字符的个数  一个map用来减  最后用第一个复制回给第二个

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> m;
        map<char,int> tmp;
        int count = 0 ;
        for(char c : chars)
        {
            m[c]++;
            tmp[c]++;
        }
        bool flag = true;
        for(string word : words)
        {
            for(char c : word)
            {
                if(!m[c]--)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                for(char c : word)
                {
                    count ++;
                }
            }
            else
            {
                flag = true;
            }
            m = tmp;
        }
        return count;
    }
};
```