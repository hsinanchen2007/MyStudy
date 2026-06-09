### 解题思路
* 关键点是选择最小几何做数组初始化，然后利用api拷贝出一个新的数组

### 代码

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
       HashSet<Integer> set1 = new HashSet<Integer>();
        for (Integer n : nums1) {
            set1.add(n);
        }
        HashSet<Integer> set2 = new HashSet<Integer>();
        for (Integer n : nums2) {
            set2.add(n);
        };

        if (set1.size() < set2.size()) {
            return set_intersection(set1, set2);
        } else {
            return set_intersection(set2, set1);
        }
    }
 public int[] set_intersection(HashSet<Integer> set1, HashSet<Integer> set2) {
    int [] output = new int[set1.size()];
    int idx = 0;
    for (Integer s : set1){
      if (set2.contains(s)) {
        output[idx++] = s;
      } 
    }
    return Arrays.copyOf(output, idx);
  }
}
```