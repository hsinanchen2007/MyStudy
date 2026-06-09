### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private List<List<Integer>> ret = new ArrayList<>();
    public List<List<Integer>> permute(int[] nums) {
        if(nums.length == 0){
            List<Integer> l = new ArrayList<>();
            ret.add(l);
            return ret;
        }
        List<Integer> already = new ArrayList<>();
        List<Integer> notUse = new ArrayList<>();
        for(int num : nums){
            notUse.add(num);
        }
        helper(already, notUse);
        return ret;
    }
    private void helper(List<Integer> already, List<Integer> notUse){
        if(notUse.size() == 0){
            List<Integer> tem = new ArrayList<>();
            tem.addAll(already);
            ret.add(tem);
            return;
        }
        for(int i = 0; i < notUse.size(); i++){
            int e = notUse.get(i);
            already.add(e);
            notUse.remove(i);
            helper(already, notUse);
            notUse.add(i, e);
            already.remove(already.size() - 1);
        }
        return;
    }
}
```