两个指针便遍历
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        int size1=haystack.size();
        int size2=needle.size();
        int res=-1;
        for(int i=0;i<size1;i++)
        {
            if(size1-i<size2) break;
            if(haystack[i]==needle[0])
            {
                res=i;
                for(int j=1;j<size2;j++)
                {
                    i++;
                    if(needle[j]!=haystack[i])
                    {
                        i=res;
                        res=-1;
                        break;
                    }
                }
                if(res!=-1) break;
            }
        }
        return res;
    }
};
```
