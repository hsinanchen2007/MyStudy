### 解题思路
使用哈希表和集合。哈希表用作找到一样的元素，找到之后就把这个value置为0(区别于下一道题)。然后集合用作与存储元素，方便最后初始化数组。

### 代码

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        List<Integer> list = new ArrayList<>();
        HashMap<Integer, Integer> hashmap = new HashMap<>();
        for(int i = 0; i < nums1.length; i++){
            if(!hashmap.containsKey(nums1[i])){
                hashmap.put(nums1[i], 1);
            }
            else
                hashmap.put(nums1[i], hashmap.get(nums1[i])+1);
        }

        for(int i = 0; i < nums2.length; i++){
            if(hashmap.containsKey(nums2[i]) && hashmap.get(nums2[i]) != 0){
                list.add(nums2[i]);
                hashmap.put(nums2[i], 0);
            }
        }
        int[] res = new int[list.size()];
        for(int i = 0; i < list.size(); i++){
            res[i] = list.get(i);
        }
        return res;
    }
}
```