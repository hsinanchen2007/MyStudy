### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1=haystack.size();
        int l2=needle.size();
        if(l2==0)
            return 0;
        int i,j,k;
        for(i=0;i<=l1-l2;i++)
        {
            k=i;
            for(j=0;j<l2;j++)
            {
                if(haystack[k]==needle[j])           
                    k++;
                else
                    break;
            }
            if(j==l2)
            { 
                return i;
                break;
            }     
        }   
        return -1;
    }
};
```