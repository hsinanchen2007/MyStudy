观察发现数n中1的个数有一下规律：
1.当n为奇数，f(n) = f(n-1)+1;
2.当n为偶数，f(n) = f(n/2);
根据这两条式子可以递归出所有数字中1的个数。
```
class Solution{
    public int[] countBits(int num) {
        int[] res = new int[num + 1];
        if(num == 0)
            return res;
        res[0] = 0;
        res[1] = 1;
        for(int i=2;i<=num;i++){
            if((i & 1) != 0){   //odd
                res[i] = res[i-1] + 1;
            }else res[i] = res[i / 2];
        }
        return res;
    }
}
```
