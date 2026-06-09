### 解题思路
这一题和349一样的，就一个地方不一样。

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> list = new ArrayList<>();
        HashMap<Integer, Integer> hashmap = new HashMap<>();
        for(int i = 0; i < nums1.length; i++){
            if(!hashmap.containsKey(nums1[i])){
                hashmap.put(nums1[i], 1);
            }
            else{
                hashmap.put(nums1[i], hashmap.get(nums1[i])+1);
            }
        }

        for(int i = 0; i < nums2.length; i++){
            if(hashmap.containsKey(nums2[i]) && hashmap.get(nums2[i]) != 0){
                list.add(nums2[i]);
                hashmap.put(nums2[i], hashmap.get(nums2[i])-1);//就是这
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