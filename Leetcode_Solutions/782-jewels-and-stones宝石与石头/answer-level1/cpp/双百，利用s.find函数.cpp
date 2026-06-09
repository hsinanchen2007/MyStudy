![image.png](https://pic.leetcode-cn.com/627bc1c5e964c5f1d04caf5c8748fda17bf02214d6483509c9685ddb4f99413d-image.png)
```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int cnt=0;
        int i=0;
        while(S.find(J[i])!=string::npos||i<J.length()){
            int pos = S.find(J[i]);
            if(pos==string::npos){
                i++;
                continue;
            }
            cnt++;
            S[pos]='0';
        }
        return cnt;
    }
};
```
