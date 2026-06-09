### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> ret = new ArrayList<>();
    public List<List<Integer>> permuteUnique(int[] nums) {
        if(nums.length == 0){
            List<Integer> l = new ArrayList<>();
            ret.add(l);
            return ret;
        }
        List<Integer> already = new ArrayList<>();
        List<Integer> noUse = new ArrayList<>();
        for(int num : nums){
            noUse.add(num);
        }
        helper(already, noUse);
        return ret;
    }
    private void helper(List<Integer> already, List<Integer> noUse){
        if(noUse.size() == 0){
            List<Integer> l = new ArrayList<>();
            for(int a : already){
                l.add(a);
            }
            ret.add(l);
            return;
        }
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < noUse.size(); i++){
            int element = noUse.get(i);
            if(set.contains(element)){
                continue;
            }
            else{
                set.add(element);
            }
            noUse.remove(i);
            already.add(element);
            helper(already, noUse);
            already.remove(already.size() - 1);
            noUse.add(i, element);
        }
        return;
    }
}
```