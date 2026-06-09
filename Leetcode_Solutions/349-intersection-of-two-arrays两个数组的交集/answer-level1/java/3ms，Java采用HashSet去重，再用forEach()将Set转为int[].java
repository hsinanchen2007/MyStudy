### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> set1 = new HashSet<>();
        HashSet<Integer> set2 = new HashSet<>();
        for(int num1 : nums1){
            set1.add(num1);
        }
        for(int num2 : nums2){
            if(set1.contains(num2)) set2.add(num2);
        }
        int[] res = new int[set2.size()];
        int index = 0;
        for(Integer n : set2){
            res[index++] = n;
        }
        return res;
    }
}
```