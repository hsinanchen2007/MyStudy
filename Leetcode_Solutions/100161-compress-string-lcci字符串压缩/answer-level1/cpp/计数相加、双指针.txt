### 解题思路
打卡

### 代码

```cpp
class Solution {
public:
    //计数法
    string countCompress(string S)
    {
        if(S.empty()) return S;
        string res = "";
        int count = 1;
        char last = S[0];
        for(int i = 1; i < S.length(); i++)
        {
            if(S[i]!=last)
            {
                res += last + to_string(count);
                last = S[i];
                count = 1;
            }
            else count++;
        }
        res += last + to_string(count);
        return res.length() < S.length() ? res : S;
    }
    //双指针法
    string doublePtr(string S)
    {
        if(S.empty()) return S;
        int i = 0, j = 0;
        string res = "";
        while(j < S.length())
        {
            if(S[j]!=S[i])
            {
                res += S[i] + to_string(j-i);
                i = j;        
            }
            j++;
        }
        res += S[i] + to_string(j-i);
        return res.length() < S.length() ? res : S; 
    }

    string compressString(string S) {
        //计数法
        // return countCompress(S);

        //双指针法
        return doublePtr(S);
    }
};
```