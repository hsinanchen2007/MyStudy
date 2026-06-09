### 解题思路
回溯算法
### 代码

```java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
 List<List<Integer>> sub=new ArrayList<>();
 List<Integer> sub1=new ArrayList<>();
 reback(0,nums,sub1,sub);
 return sub;
    }
    public void reback(int start,int[] nums,List<Integer> sub1,List<List<Integer>> sub){
         sub.add(new ArrayList<>(sub1));
         for(int i=start;i<nums.length;i++){
             sub1.add(nums[i]);
             reback(i+1,nums,sub1,sub);
             sub1.remove(sub1.size()-1);
         }
    }
}
```