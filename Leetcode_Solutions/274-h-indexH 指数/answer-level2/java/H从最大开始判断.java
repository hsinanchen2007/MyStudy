H最大就是数组长度，因此递减判断有没有H个大于H的论文就好了
```java
class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int h = 0;
        for(h=citations.length; h>0; h--){
            if( citations[citations.length-h] >= h) {
                break;
            }
        }
        return h;
    }
}
```
