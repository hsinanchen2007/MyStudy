```java
class Solution {
    public int hIndex(int[] citations) {
        int len = citations.length;
        int left = 0;
        int right = len;
        while (left < right) {
            int mid = (left + right) >>> 1;
            // 以[0,1,3,5,6]为例.
            // 假如当前citation = 1,assume1篇至少1个引用,actual竟然有4篇至少1个引用,所以往后找,故left = mid+1.
            // 假如当前citation = 5,assume5篇至少5个引用,actual只有2篇至少5个引用,只能往前找,故right = mid.
            // 注意: assume == actual的时候要保留mid,所以放在了right = mid的分支.
            int assume = citations[mid];
            int actual = len - mid;

            if (assume < actual) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return len - left;
    }
}
```
