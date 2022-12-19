### 解题思路
标准回溯流程
每次从start点开始遍历
由于数字可重复，就需要每次都从start开始遍历，并且下一次递归的起始位置还是start，保证可重复的选项。
剪枝：sort之后，如果遍历的当前值candidate【i】大于target，那么就可以不用遍历了，之间break，后续肯定比target大，那么根本放不进数组里面。

### 代码

```java
class Solution {
    public List<List<Integer>> res=new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
            ArrayList<Integer> temp= new ArrayList<Integer>();
            Arrays.sort(candidates);
            helper(candidates,0,target,temp);
            return res;

    }
    public void helper(int[] candidates, int start, int target, ArrayList<Integer> temp)
    {
        if(target==0)
        {
            res.add(new ArrayList<>(temp));
            return;
        }
        if(start==candidates.length)
            return;

        for(int i=start;i<candidates.length;i++)
        {
            if(candidates[i]>target)
                break;

            if(target-candidates[i]>=0)
            {
                temp.add(candidates[i]);
                helper(candidates,i,target-candidates[i],temp);
                temp.remove(temp.size()-1);
            }
        }
    }
}
```