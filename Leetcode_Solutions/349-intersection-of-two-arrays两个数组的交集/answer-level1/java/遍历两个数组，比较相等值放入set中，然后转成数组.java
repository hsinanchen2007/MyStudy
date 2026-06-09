### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> set = new HashSet<>();
        for(int i = 0; i < nums1.length; i++) {
            for(int j = 0; j < nums2.length; j++) {
                if(nums1[i] == nums2[j]) {
                    set.add(nums1[i]);
                }
            }
        }
        Integer[] integers = set.toArray(new Integer[set.size()]);
        int[] result = new int[integers.length];
        for(int i = 0; i < result.length; i++) {
            result[i] = integers[i];
        }
        return result;
    }
}
```