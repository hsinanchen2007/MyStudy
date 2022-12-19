统计出现个数为1的数  倒序输出第1个

```
class Solution {
    public int largestUniqueNumber(int[] A) {
        int []  hash =  new int[1001] ;
        for( int test : A){
            hash[test]++ ;
        }
        for(int i = 1000; i>=0 ;i-- ){
            if(hash[i] == 1 ) return i ;
        }
        return -1 ;
    }
}
```
