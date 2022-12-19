### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
         List<Integer> L=new ArrayList<>();
         int[] n=new int[nums.length];
         for(int i=0;i<nums.length;i++){
             L.add(index[i],nums[i]);
         }
         for(int i=0;i<nums.length;i++){
            n[i]=L.get(i);
         }
         return n;
    }
}
```