/**
 * Project:
 * Author : zhaozhen
 * Email  : 2399144252@qq.com
 * Date   : 2019/10/11
 *
 * 解题思路: hash数组 暴力解决 3ms
 *
 */
```
public class leetcode788 {

    int[] hash = new int[]{1,1,2,0,0,2,2,0,1,2};
    public int rotatedDigits(int N) {

        int sum = 0;
        for(int i = 2 ; i <= N ; i ++){
            if(isGoodNum(i)) sum++;
        }
        return sum;
    }

    public boolean isGoodNum(int n){
        int t;
        boolean is_ok = false;
        while(n != 0){
            t = n % 10;
            if(hash[t] == 0) return false;
            else if(hash[t] == 2) is_ok = true;
            n = n / 10;
        }
        if(is_ok) return true;
        else return false;
    }

    public static void main(String[] args) {

    }
}

```