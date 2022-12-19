
```C++ []
class Solution {
public:
    vector<int> grayCode(int n) {
        int len=pow(2,n);
        vector<int> res(len,0);
        int i,j;
        int temp;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<pow(2,i-1);j++)
            {
                temp=res[j]+pow(2,i-1);
                res[pow(2,i)-j-1]=temp;
            }
        }
        return res;
    }
};
```
