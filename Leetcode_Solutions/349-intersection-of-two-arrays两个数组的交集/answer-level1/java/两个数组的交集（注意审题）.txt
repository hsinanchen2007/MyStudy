开始以为题目的要求是数学上的交集，就没注意看例子。
想着[1, 2, 2, 3]  和 [2, 2] 的交集是 [2, 2] 
于是有了以下的解法，但是跑出来傻眼了hh，这个解法贴出来，供学习用。
用了一些套路。
```
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map = new HashMap<>();
        List<Integer> result = new ArrayList<>();
        for(int i = 0; i < nums1.length; i++) {
            if(map.containsKey(nums1[i])) {
                map.put(nums1[i], map.get(nums1[i])+1);
            } else {
                map.put(nums1[i], 1);
            }
        }
        for(int i = 0; i < nums2.length; i++) {
            if(map.containsKey(nums2[i]) && map.get(nums2[i]) > 0) {
                map.put(nums2[i], map.get(nums2[i])-1);
                result.add(nums2[i]);
            }
        }
        return result.stream().mapToInt(i->i).toArray();
    }
}
```

正确解答：
解法一：
通过一个set对数组去重，再对数组二进行排序，遍历的过程中去重。
时间复杂度：nlog(n)  // 取决于 排序操作
空间复杂度：O(n) 申请的一个set

还有值得学习的小技巧是 list.stream().mapToInt(i->i).toArray()，是对 List 转 int[] 的一个操作。

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
       Set<Integer> set = new HashSet<>();
       List<Integer> list = new ArrayList<>();
       for(int i = 0; i < nums1.length; i++) {
           set.add(nums1[i]);
       }
       Arrays.sort(nums2);
       
       for(int i = 0; i < nums2.length; i++) {
           if(i+1 < nums2.length && nums2[i+1] != nums2[i] && set.contains(nums2[i])) {
               list.add(nums2[i]);
           } else if(i == nums2.length - 1 && set.contains(nums2[i])) {
               list.add(nums2[i]);
           }
       }
       return list.stream().mapToInt(i->i).toArray();

    }
}
```
解法二：
两个 set，达到去重效果
```
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
       Set<Integer> set = new HashSet<>();
       Set<Integer> childSet = new HashSet<>();
       List<Integer> list = new ArrayList<>();
       for(int i = 0; i < nums1.length; i++) {
           set.add(nums1[i]);
       }

       for(int num : nums2) {
           if(set.contains(num)) {
               childSet.add(num);
           }
       }
        int[] res = new int[childSet.size()];
        int index = 0;
        for(int num : childSet) {
            res[index++] = num;
        }
       return res;

    }
}
```
