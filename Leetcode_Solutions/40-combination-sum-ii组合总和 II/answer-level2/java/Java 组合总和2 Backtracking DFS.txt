### 解题思路
穷举类问题想到用回溯算法。
为什么要进行排序呢？我们先看一下排序后的效果。
如candidates = [10,1,2,7,6,1,5], target = 8。
排序后candidates = [1,1,2,5,6,7,10] 假如做到1+1+2，下一步加5已经大于target，因此
在这种情况之后的所有组合都可以跳过不做，如果不排序是达不到这种效果的。
关于去重的问题，在这里另外提供一个比较麻烦但是很容易理解的思路：
开一个HashSet<List<Integer>>,每次加入结果前,判断set是否包含即将添加的list。

### 代码

```java
class Solution {
    List<List<Integer>> ans = new ArrayList<>() ;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        if(candidates == null || candidates.length == 0) return ans ;
        Arrays.sort(candidates) ;
        helper(candidates,target,0,0,new ArrayList<>()) ;
        return ans ;
    }
    public void helper(int[] candidates,int target,int sum,int index,List<Integer> temp){
        if(sum == target){
            ans.add(new ArrayList<>(temp)) ;
            return ;
        }else{
            for(int i = index ; i < candidates.length ; i++){
                if(i > index && candidates[i] == candidates[i-1]) continue ; //continue的原因在于当前数和上一个数字大小相同，那么上个数字出现的符合预期的所有结果会包含这个数字出现的结果里。
                if(sum + candidates[i] <= target){
                    temp.add(candidates[i]) ;
                    helper(candidates,target,sum+candidates[i],i+1,temp) ;
                    temp.remove(temp.size()-1) ;
                }
            }
        }
    }
}
```