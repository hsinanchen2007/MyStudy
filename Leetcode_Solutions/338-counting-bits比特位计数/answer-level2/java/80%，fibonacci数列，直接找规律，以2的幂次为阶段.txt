其实应该用Linkedlist解更容易
2^m ~ 2^m - 1 中的数的bit表示的1的数量是0 ~ 2^m - 1的bit表示的1的数量每个数加1
```
class Solution {
    public int[] countBits(int num) {
        if(num == 0)
            return new int[]{0};
        int[] r = new int[num + 1];
        r[1] = 1;
        int p = 1;
        while(p <= num) {
            int i = p;
            for(int j = 0; j < i; ++ j) {
                r[i + j] = 1 + r[j];
                if(i + j == num)
                    return r;
            }
            p *= 2;
        }
        return r;
    }
}
```
