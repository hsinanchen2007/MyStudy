### 解题思路
用一个HashSet即可搞定

### 代码

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> set = new HashSet<>();
        for(int i:nums1){
            set.add(i);
        }
        int[] res = new int[nums1.length];
        int index = 0;
        for(int i:nums2){
            if(set.contains(i)) {
                res[index++] = i;
                set.remove(i);  //防止重复添加
            }
        }
        return Arrays.copyOf(res,index);
    }
}
```