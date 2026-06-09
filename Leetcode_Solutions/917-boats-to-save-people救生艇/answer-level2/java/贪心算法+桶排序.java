![捕获.PNG](https://pic.leetcode-cn.com/0890366c71697f58ae31da6293087c63eadad34d34d01c4e96960e209fb4518d-%E6%8D%95%E8%8E%B7.PNG)

根据官方算法改编而来，采用桶排序，可以将复杂度减小为O(n).
```
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int max = -1;
        for (int p: people)
            max = Math.max(max, p);
        int[] map = new int[max+1];
        for (int p: people)
            map[p]++;
        int l = 0, r = max;
        int res = 0;
        while (l <= r) {
            while (l <= r && map[l] == 0) l++;
            while (l <= r && map[r] == 0) r--;
            if (l > r) break;
            if (l == r && map[l] == 1) {
                res++; break;
            }
            if (l +r > limit) {
                res++;
                map[r]--;
            } else {
                res++;
                map[r]--;
                map[l]--;
            }
        }
        return res;
    }
}
```