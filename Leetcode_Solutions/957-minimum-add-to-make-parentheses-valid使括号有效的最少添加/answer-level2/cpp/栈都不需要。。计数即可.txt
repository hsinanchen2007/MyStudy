接收到'(' 则计数left++
接收到')' 如果此时left=0，那么这个')'是无法被匹配的，给计数right++；如果left>0，则匹配之前的一个'('，left--
最后输出left+right，即无法被匹配的')'个数+尚未被匹配的'('个数



```
class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0;
        int right = 0;
        for (auto &c:S){
            if (c=='(') left++;
            else{
                if (left>0) left--;
                else right++;
            }   
        }
        return left+right;
    }
};
```
