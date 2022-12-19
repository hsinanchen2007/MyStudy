数据量很小，可以直接暴力解，扫描发现哪个数出现了第二次直接返回就好
```
class Solution {
    public int repeatedNTimes(int[] A) {
        boolean[] check = new boolean[10001];
        for(int a : A){
            if(check[a] == false)
                check[a] = true;
            else
                return a;
        }
        return 0;
    }
}
```
