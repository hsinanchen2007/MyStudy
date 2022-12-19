### 解题思路
使用了两个HashSet,第一个是为了找出交集,第二个是为了将结果集去重

### 代码
```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> hSet = new HashSet<>();
        Set<Integer> hSet2 = new HashSet<>();
        for (int i : nums1) {
            hSet.add(i);
        }
        
        int len2 = nums2.length;
        int[] result = new int[len2];
        for (int i = 0; i < len2; i++) {
            if (hSet.contains(nums2[i])) {
                hSet2.add(nums2[i]);
            }
        }
        int i = 0;
        for (Integer num : hSet2) {
            result[i++]=num;
        }
        
        return Arrays.copyOfRange(result, 0, hSet2.size());
    }
}
```