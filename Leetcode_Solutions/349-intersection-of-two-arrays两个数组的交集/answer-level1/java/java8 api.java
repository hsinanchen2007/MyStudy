### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        List<Integer> list1 = Arrays.stream(nums1).boxed().collect(Collectors.toList());
        List<Integer> list2 = Arrays.stream(nums2).boxed().collect(Collectors.toList());
        list1.retainAll(list2);
        return list1.stream().distinct().mapToInt(i -> i.intValue()).toArray();
    }
}
```