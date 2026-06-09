执行用时 :4 ms, 在所有 Java 提交中击败了97.99%的用户
内存消耗 :34 MB, 在所有 Java 提交中击败了12.13%的用户

逐步增加除数的大小，每次增加为之前除数的2倍，如果除以除数为0，则除数重新置位2，以递归的方式重新计算
```
class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }else{
            return cal(n);
        }
    }

    public boolean cal(int n){
        int div = 2;
        while(n/div!=0&&n%div==0){
            n = n/div;
            div = div*2;
        }
        if(n%2==0){
            return cal(n);
        }else if(n==1){
            return true;
        }else{
            return false;
        }
    }
}
```

