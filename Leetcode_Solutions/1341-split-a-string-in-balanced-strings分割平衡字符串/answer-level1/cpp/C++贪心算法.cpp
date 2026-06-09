遍历整个字符串，计数L和R的数量,若LR相等且不为0则配对成功，结果加1。

```
class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int l=0;
        int r=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='L')
            l++;
            else
            r++;
            if(l==r&&l!=0){
            ans++;
            l=0;
            r=0;
            }
        }
        return ans;
    }
};
```


