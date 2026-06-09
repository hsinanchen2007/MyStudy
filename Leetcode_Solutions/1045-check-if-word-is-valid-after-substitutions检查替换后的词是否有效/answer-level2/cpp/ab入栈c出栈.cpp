### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isValid(string S) {
        if(S[0]!='a'||S[1]=='c'||S.size()%3!=0)return false; 
        char res[20001];
        int top=0;
        res[top++]=S[0];
        for(int i=1;i<S.size();i++)
        {
            if(S[i]=='a'||S[i]=='b')res[top++]=S[i];
            else
            {
                if(top>=2&&res[top-2]=='a'&&res[top-1]=='b')top-=2;
                else return false;
            }
        }
        return top==0;
    }
};
```