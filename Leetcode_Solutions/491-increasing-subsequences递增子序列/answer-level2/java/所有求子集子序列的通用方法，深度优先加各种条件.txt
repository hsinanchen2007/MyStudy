目的是将树上所有符合结果的节点，而不只是叶子节点的值加入结果集中

伪代码如下：
``` java
    public void generate(){
        //判断结束深搜的时机

        //将当前符合要求的结果加入结果集中

        //深度优先遍历这个节点往下的内容（递归），在遍历的过程中再灵活的具体分析具体要求
    }
```


```java
class Solution {
    //int temp = -101;
    public List<List<Integer>> findSubsequences(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> item = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        generate(0, nums, item, res, set);
        return res;
    }
    public void generate(int start, int[] nums,  List<Integer> item, List<List<Integer>> res, Set<Integer> fset){
        if(start >= nums.length){
            if(item.size()>=2){
                res.add(new ArrayList(item));
            }
            return ;
        }
        if(item.size()>=2){
            res.add(new ArrayList(item));
        }
        for(int i = start; i<nums.length;i++){
            // 这种去重前提条件是数组有序
            /*if(nums[i] == temp){
                continue;
            }*/
            if(fset.contains(nums[i])){
                continue;
            }
            if(item.size()>=1 && nums[i] < item.get(item.size()-1)){
                continue;
            }
            item.add(nums[i]);
            fset.add(nums[i]);
            Set<Integer> set = new HashSet<>();
            generate(i+1, nums, item, res, set);
            item.remove(item.size()-1);
        }
    }
}
```
执行用时 :7 ms, 在所有 Java 提交中击败了95.04%的用户
内存消耗 :47.4 MB, 在所有 Java 提交中击败了100.00%的用户