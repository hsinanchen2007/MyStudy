这里的判断`if(i%2==1)`不能像python一样可以直接写`if(i%2)`
```
public class Solution {
    public int[] SortArrayByParityII(int[] A) {
        var odd = 1;
        var even = 0;
        int[] res = new int[A.Length];
        foreach(var i in A){
            if(i%2==1){
                res[odd]=i;
                odd+=2;
            }else{
                res[even]=i;
                even+=2;
            }
        }
        return res;
    }
}
```
