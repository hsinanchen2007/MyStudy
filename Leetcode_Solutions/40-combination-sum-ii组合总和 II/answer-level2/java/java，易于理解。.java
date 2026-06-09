这道题目中，**数组有重复数字**，而结果中不能出现重复结果。这道题目中，去重的方法完全可以**借助15题三数之和中的去重思想：第一次遇见重复数字的时候不能跳过，当后边再一次遇见重复数字的时候，跳过**

```
  List list=new ArrayList();
    List sub=new ArrayList();
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        helper(candidates,target,0,0,sub);
        return list;
    }

    public  void helper(int[] nums,int target,int index,int sum,List sub)
    {
        if(sum>target)
        {
            return ;
        }
        if(sum==target)
        {
             list.add(new ArrayList<>(sub));
             return ;
        }
        for(int i=index;i<nums.length;i++)
        {
            if(i>index&&nums[i]==nums[i-1])
            {
                continue;
            }
            sum+=nums[i];
            sub.add(nums[i]);
            helper(nums,target,i+1,sum,sub);
            sum-=nums[i];
            sub.remove(sub.size()-1);
        }
    }
```
