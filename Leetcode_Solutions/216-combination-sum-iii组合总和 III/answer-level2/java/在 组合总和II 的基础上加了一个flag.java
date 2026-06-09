### 解题思路

跟组合总和2的题目很相似，就把候选数组初始化一下并且加上flag来保证总的位数为k。


![image.png](https://pic.leetcode-cn.com/da6aa40f58da68c08db730959d282d97b8be3e328af078fa830d3f41dd910818-image.png)

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum3(int k, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> tmp_ans = new ArrayList<>();
        int[] candidates = {1,2,3,4,5,6,7,8,9};
        System.out.println(candidates.length);
        back_track(candidates,target,ans,tmp_ans,k,0);
        return ans;//.stream().distinct().collect(Collectors.toList());
    }
    public void back_track(int[] candidates, int target, List<List<Integer>> ans, List<Integer> tmp_ans, int flag,int num){
        if(target<0)return;
        if(target == 0 && flag ==0){
            ans.add(new ArrayList(tmp_ans));
            return;
        }
        for(int i=num;i < candidates.length; i++){
            if(i>num&&candidates[i] == candidates[i-1])continue;
            if(target<0||flag<0)break;//根据都是正整数的条件加速
            tmp_ans.add(candidates[i]);
            back_track(candidates,target - candidates[i],ans,tmp_ans,flag - 1,i+1);
            tmp_ans.remove(tmp_ans.size() - 1);
        }
    }
}
```