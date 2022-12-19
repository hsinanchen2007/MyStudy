```
    class Solution {
    public:
        int longestPalindrome(string s) {
            int temp[255]={0};
            int cnt(0);
            int flag(0);
            for(int i=0;i<s.length();i++)
            {
                temp[s[i]]++;
            }
            for(int j=0;j<255;j++)
            {
                if(temp[j]%2==0)
                {
                    cnt+=temp[j];
                }
                else
                {
                    if(temp[j]>2)
                    {
                        cnt+=temp[j]-1;
                    }
                    flag=1;
                }
            }

        return flag==1?cnt+1:cnt;
        }
    };
```

