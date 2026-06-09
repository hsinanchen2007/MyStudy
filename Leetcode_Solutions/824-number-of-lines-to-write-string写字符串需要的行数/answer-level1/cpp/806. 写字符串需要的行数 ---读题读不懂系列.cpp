### 解题思路

一行一行的放字母
如果当前字符所占单位和之前的和大于100，则放弃当前行，将当前字符放入下一行

### 代码

```cpp
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int sum=0,cnt=0;
        for(int i=0;i<S.size();i++){
            if(sum+widths[S[i]-'a']>100){
                cnt++;sum=widths[S[i]-'a'];
            }else sum+=widths[S[i]-'a'];
        }
        return {cnt+1,sum};
    }
};
```