### 解题思路

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
       if(nums1 == null || nums2 == null) {
           return new int[0];
       }
       if(nums1.length == 0 || nums2.length == 0) {
           return new int[0];
       }
       Map<Integer,Integer> map = new HashMap<>();
       for(int num : nums1) {
            Integer c = map.get(num);
            map.put(num,c == null? 1 : c+1);
       }
       int i = 0;
       for(int num: nums2) {
           Integer c = map.get(num);
           if(c != null && c > 0) {
               nums1[i++] = num;
               map.put(num,--c);
           }
       }
       int[] result = new int[i];
       System.arraycopy(nums1,0,result,0,i);
       return result;
    }
}
```