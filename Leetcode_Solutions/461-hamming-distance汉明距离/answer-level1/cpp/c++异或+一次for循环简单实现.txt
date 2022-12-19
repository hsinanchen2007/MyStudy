执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :8.2 MB, 在所有 cpp 提交中击败了82.53%的用户
```
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        for(int z = x^y;z>0;z=z>>1){
            if(z&1==1){
                res++;
            }
        }
        return res;
    }     
};
```
