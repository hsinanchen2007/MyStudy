# Thinking
- 采用最简单的递归回溯思路。废话不多说，直接看代码结合注释，很简单都能看懂
# Code
```
public class Solution
{
    private int[] candidates;
    private List<List<Integer>> ans=new ArrayList<>();
    private int target;
    
    private void backTrack(List<Integer> list,int index,int sum)
    {
        for(int i=index;i<candidates.length;i++)
        {
            if(sum+candidates[i]<target)//get chance.
            {
                list.add(candidates[i]);
                backTrack(list,i,sum+candidates[i]);
                list.remove(list.size()-1);//recovery list
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
                list.remove(list.size()-1);//recovery list.
                return;
            }
        }
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) 
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
