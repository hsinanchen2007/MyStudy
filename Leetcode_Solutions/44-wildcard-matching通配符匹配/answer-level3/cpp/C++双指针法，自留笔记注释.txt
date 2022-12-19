### 解题思路
自留供以后查看

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();

        int i=0,j=0,iStar=-1,jStar=-1;
        while(i<m){
            if(j<n && (s[i]==p[j] || p[j]=='?')){
                i++;
                j++;
            }
            else if(j<n && p[j]=='*'){
                iStar=i;//遇到一个*后，第一次假设不匹配，i不动
                jStar=j++;//遇到一个*后，第一次假设不匹配，j自增来匹配下一个，相当于跳过了*
            }
            else if(iStar>=0){
                i=++iStar;//到这里说明按照之前的假设（即*不匹配）最后不会匹配成功，所以i在之前假设的位置上＋1，代表*多匹配一位
                j=jStar+1;//此处的j+1代表跳过*
            }
            else
                return false;
        }
        while(j<n && p[j]=='*') j++;//去除多余的*
        return j==n;
    }
};
```