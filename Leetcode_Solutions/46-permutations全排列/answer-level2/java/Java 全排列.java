回溯算法；
用列表来代替nums是因为，列表容易删除元素，改变它的大小
candidate:候选可用数字进行排列；seq:组成的全排列；ans:最终结果


```
class Solution{
    public List<List<Integer>> permute(int[] nums){
        List<List<Integer>> ans = new LinkedList<List<Integer>>();
        List<Integer> seq = new ArrayList<Integer>();
        List<Integer> candidate = new ArrayList<>();
        for(int i = 0; i< nums.length; i++){
            candidate.add(nums[i]);
        }
        helper(candidate, seq, ans);
        return ans;
    }
    public void helper(List<Integer> candidate, List<Integer> seq, List<List<Integer>> ans){
        if(candidate.size() == 0){
            ans.add(seq);
            return ;
        }
        for(int i = 0; i<candidate.size(); i++){
            List<Integer> tmpCandidate = new ArrayList<Integer>(candidate);

            seq.add(candidate.get(i));
            tmpCandidate.remove(candidate.get(i));
            
            List<Integer> tmpseq = new ArrayList<Integer>(seq);
            helper(tmpCandidate, tmpseq, ans);
            seq.remove(candidate.get(i));
        }
        return ;    
    }
}

```

时间复杂度 O(n!);
