### 解题思路
与字符串压缩类似

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        int i,j;
        string arry[31];
        arry[1]="1";
        for(i=2;i<=30;i++)
        {
            j=0;
            while(j<arry[i-1].length())
            {
                int k=j;
                while(arry[i-1][k]==arry[i-1][j]&&k<arry[i-1].length())
                {
                    k++;
                }
                arry[i]+=to_string(k-j)+arry[i-1][j];
                j=k;
            }
        }
        return arry[n];
    }
};
```