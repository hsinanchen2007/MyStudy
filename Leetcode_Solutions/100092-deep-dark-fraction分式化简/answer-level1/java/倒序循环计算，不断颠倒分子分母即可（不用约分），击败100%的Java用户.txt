```
class Solution {
    public int[] fraction(int[] cont) {
        int[] ans = {1,1};
        int len = cont.length;
        if (len == 0) return ans;
        ans[1] = cont[len - 1];
        for(int i = len - 2; i >= 0; i--) {
            int tmp = ans[1];
            ans[1] = cont[i] * ans[1] + ans[0];
            ans[0] = tmp;
        };
        ans[0] = ans[0] ^ ans[1];
        ans[1] = ans[0] ^ ans[1];
        ans[0] = ans[0] ^ ans[1]; 
        return ans;
    }
}
```
