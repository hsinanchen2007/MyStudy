### 解题思路
递归

### 代码

```java
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> permute(int[] nums) {
        int len = nums.length;
        if(nums.length==0) return res;
        helper(new ArrayList<Integer>(), nums, 0, len-1);
        return res;
    }
    public void helper(List<Integer> pre, int[] nums, int start, int end){
        if(start == end){
            pre.add(nums[start]);
            res.add(pre);
        }else{
            for(int i=start;i<=end;i++){
                int[] tmpNums = Arrays.copyOf(nums,nums.length);
                int tmp = tmpNums[i];
                tmpNums[i] = tmpNums[start];
                tmpNums[start] = tmp;
                List<Integer> list = new ArrayList<>();
                list.addAll(pre);
                list.add(tmp);
                helper(list, tmpNums, start+1, end);
            }
        }
    }
}
```