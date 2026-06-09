```
class Solution {
public:
    int balancedStringSplit(string s) {
        int Lnum=0,Rnum=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                if(Rnum){
                    Rnum--;
                    if(Rnum==0) ans++;
                }
                else Lnum++;
            }
            if(s[i]=='R'){
                if(Lnum){
                    Lnum--;
                    if(Lnum==0) ans++;
                } 
                else Rnum++;
            }
        }
        return ans;
    }
};
```
![image.png](https://pic.leetcode-cn.com/19e1df91f40a1236d430983ae59e17bc5453c83d643e910e7088c7fcbca00dfb-image.png)
