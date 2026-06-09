若n=8初始状态
                   1   2   3   4   5   6   7   8
k=1$~~~~~~~~$ | 1   2   3   4   5   6   7   8 (不翻转，直接返回)
k=2$~~~~~~~~$ 1 | 8   7   6   5   4   3   2 
k=3$~~~~~~~~$ 1   8 | 2   3   4   5   6   7 
k=4$~~~~~~~~$ 1   8   2 | 7   6   5   4   3 
总结规律：当k>1时,需要翻转的次数为k-1次，每次翻转保留前m(m = 1,2,3...k-1)个数，每次翻转都在原数组进行。
```
class Solution {
    public int[] constructArray(int n, int k) {
        int[] res = new int[n];
        for(int i = 0; i < n; i++) res[i] = i + 1;  //产生1~n个数
        if(k == 1) return res;  //k==1直接返回
        //k != 1就要翻转k - 1次，每次翻转保留前m个数
        for(int m = 1; m < k; m++)
            reverse(res, m, n - 1); 
        return res;
    }
    //翻转数组[i,j]之间的数
    void reverse(int[] res, int i, int j){
        while(i < j){
            int t = res[i];
            res[i] = res[j];
            res[j] = t;
            i++;
            j--;
        }
    }
}
```

