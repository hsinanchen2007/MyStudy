```
class Solution {
  public int[] replaceElements(int[] arr) {
        int [] ret = new int[arr.length];
        //请你将每个元素用它右边最大的元素替换，
        int  max = arr[arr.length-1];
        for( int i = arr.length-1;i>=0; i-- ){
            ret[i] = max ;
            max = Math.max(max, arr[i]);
        }

        ret[arr.length-1] = -1 ;
        return ret ;
    }
}
```
