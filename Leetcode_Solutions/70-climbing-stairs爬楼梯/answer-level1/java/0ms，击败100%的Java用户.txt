递归会超时，用了循环，前3直接返回。

```
class Solution {
    public int climbStairs(int n) {
        int count = 0;
        int first = 2;
        int second = 3;
        if(n<4){
            return n;
        }
        for(int i=4;i<=n;i++){
                count = first+second;
                first = second;
                second = count;
            }
        return count;
    }
}
```
