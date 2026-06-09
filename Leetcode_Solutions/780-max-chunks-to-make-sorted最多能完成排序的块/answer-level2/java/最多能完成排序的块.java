```java
class Solution {
    public int maxChunksToSorted(int[] arr) {
        
        if(arr ==null){
            return 0;
        }
        
        int ret = 0;
        int max =arr[0];
        for(int i=0;i< arr.length;i++){
            max = Math.max(max,arr[i]);
            if(max==i){
                ret++;
            }
        }
        return ret;
    }
}

```