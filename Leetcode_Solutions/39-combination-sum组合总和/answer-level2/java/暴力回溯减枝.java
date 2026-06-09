```
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates); 
        List<List<Integer>> res=new ArrayList<>();
            dfs(candidates,0,target,new LinkedList<>(),res,0);
            return  res;
    }

    private void dfs(int num[],int start,int target,LinkedList<Integer> list, List<List<Integer>> res,int sum) {
     //如果扫描到最后一个元素或者元素和等于目标值
        if (start==num.length||sum==target)
        {
            if (sum==target)
            res.add(new ArrayList<>(list));
            return;
        }
        //减脂条件
        if (target-sum<num[start])return;
        for (int i = start; i <num.length ; i++) {
            int cnt=(target-sum)/num[i];
            //贪心策略：对于每个元素，尽可能的多取
            if (cnt==0)return;
            sum+=num[i]*cnt;
            for (int j = 0; j <cnt ; j++) {
                list.addLast(num[i]);
            }
            //先搜索，回溯时删除一个该元素
            while (cnt>0)
            {
                dfs(num,i+1,target,list,res,sum);
                list.removeLast();
                sum-=num[i];
                cnt--;
            }
        }


    }
}
```
