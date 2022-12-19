### 解题思路
在39题的基础上，由于不能重复选取，所以每次递归应该自动查找下一个数。
另外，由于输入的数组有重复的数字，为了避免出现题解重复的现象，应该在同一层递归层上增加判断条件。方法是这一层递归层移除的元素不能和下一个选取的元素一致。
### 代码

```java
class Solution {
    private int[] candidates;
    private List<List<Integer>> ans=new ArrayList<>();
    private int target;
    
    private void backTrack(List<Integer> list,int index,int sum)
    {
        int removed=-1;
        for(int i=index;i<candidates.length;i++)
        {
            if(candidates[i]==removed)continue;//本层移除的元素不能与下一个元素一致。避免重复。
            if(sum+candidates[i]<target)
            {
                list.add(candidates[i]);
                backTrack(list,i+1,sum+candidates[i]);
                removed=candidates[i];//记录下本层移除的元素，即遍历过的元素。
                list.remove(list.size()-1);
            }
            else if(sum+candidates[i]>target)
            {
                return;
            }
            else
            {
                list.add(candidates[i]);
                List<Integer> anslist=new ArrayList<>();
                anslist.addAll(list);
                ans.add(anslist);
                list.remove(list.size()-1);
                return;
            }
        }
    }
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) 
    {
        Arrays.sort(candidates);
        this.candidates=candidates;
        this.target=target;
        List<Integer> list=new ArrayList<>();
        backTrack(list,0,0);
        return ans;
    }
}
```