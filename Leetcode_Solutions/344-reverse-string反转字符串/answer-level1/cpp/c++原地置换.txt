### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        char tem;
        int j = s.size()-1;
        for(int i=0;i<=s.size()/2;i++)
        {
            if(i<=j)
            {
                tem=s[j];
                s[j]=s[i];
                s[i]=tem;
                j--;
            }
            else
            {
                break;
            }
        }
    }
};
```