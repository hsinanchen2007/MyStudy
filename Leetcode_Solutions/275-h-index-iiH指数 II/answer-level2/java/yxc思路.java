
```java
class Solution {
    public int hIndex(int[] citations) {
        if(citations.length==0) return 0;

        int l=0,r=citations.length-1;
        while(l<r){
            int mid=l+r>>1;
            if(citations[mid]>=citations.length-mid) r=mid;
            else l=mid+1;
        }
        if (citations.length - l <= citations[l]) return citations.length-l;
        return 0;
    }
}
```