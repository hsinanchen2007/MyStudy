# 方法1：1个 set + array

```java []
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        int minLen = Math.min(nums1.length, nums2.length);
        int[] res = new int[minLen];
        
        for(int num : nums1){
            set.add(num);
        }
        
        int k = 0;
        for(int num : nums2){
            if(set.contains(num)){
                res[k++] = num;
                set.remove(num);
            }    
        }
        
        return Arrays.copyOf(res, k);
    }
}
```

复杂度分析

- 时间复杂度：O(m+n)。
- 空间复杂度：O(m+n)， 最坏的情况是数组中的所有元素都不同。



# 方法2 ： 2个set,求交集，再转换成数组

```java []
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> s1 = new HashSet<>();
        Set<Integer> s2 = new HashSet<>();
        
        for(int num : nums1){
            s1.add(num);
        }
        
        for(int num : nums2){
            s2.add(num);
        }
        
        s1.retainAll(s2); // 2个set交集
        
        int[] res = new int[s1.size()];
        int k = 0;
        for(int num : s1){
            res[k++] = num;
        }

        return res;
    }
}
```

复杂度分析

- 时间复杂度：一般情况下是 O(m+n)，最坏情况下是当数组元素都不相同时 O(m×n)。
- 空间复杂度：最坏的情况是 O(m+n)，当数组中的元素全部不一样时。


