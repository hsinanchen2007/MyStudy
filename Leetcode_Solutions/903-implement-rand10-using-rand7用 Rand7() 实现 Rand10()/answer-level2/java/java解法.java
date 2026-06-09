执行用时 :12 ms, 击败了36.45%的用户。
内存消耗 :44.3 MB, 击败了33.33%的用户
```
class Solution extends SolBase {
    public int rand10() {
        int x = rand7();
        //若为7，重新取值，使x为奇/偶数的概率一样为3/7
        while(x==7){
            x = rand7();
        }
        int res = 0;
        //奇数取1-5，偶数取6-10
        if((x%2 == 0)){
            res = 5;
        }
        int z = rand7();
        //大于5，则重新取值
        while(z>5){
            z = rand7();
        }
        return res + z;
    }
}
```