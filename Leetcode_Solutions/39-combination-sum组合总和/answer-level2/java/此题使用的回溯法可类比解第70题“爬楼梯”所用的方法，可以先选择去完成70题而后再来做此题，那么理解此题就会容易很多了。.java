class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        
        List<List<Integer>> result = new ArrayList<>();
        
        int n = candidates.length;
        
        List<Integer> temp = new ArrayList<>();//此处list作用为存储数据
        
        backtrack(0,candidates,target,temp,result);//以0开始回溯
            
        return result;
    }
    
    public void backtrack(int candidate,int[] candidates,int target,
                          List<Integer> temp,List<List<Integer>> result)
    {
        
        if(candidate<target)//如果累计之和比target小，则继续回溯
        {
            for(int i=0;i<candidates.length;i++)
            {//对每个数进行回溯，例如对于（2，3,6,7）的2而言，变为2+2,2+3,2+6,2+7
                
                List<Integer> l = new ArrayList<>();//针对每一次回溯创建一个list，用于记录数据
                for(int j=0;j<temp.size();j++)//将已有的数据读取出来。例如temp为（2,2），l则也为（2,2）
                {
                    l.add(temp.get(j));
                }
                
                if(candidate==0 || candidates[i]>=temp.get(temp.size()-1))//此处为去重处理，只能大于等于上一次回溯所用的
                    //数才能继续回溯，例如第一次回溯为0+2 0+3 0+6 0+7
                    //那么第二次回溯就只能为0+2+2 0+2+3 0+2+6 0+2+7
                    //0+3+3 0+3+6 0+3+7
                    //0+6+6 0+6+7
                    //0+7+7
                {
                    l.add(candidates[i]);//添加新的数据，例如对每一次回溯变为（2,2,2）   （2,2,3） （2,2,6） （2,2,7）
                    backtrack(candidate+candidates[i],candidates,target,l,result);//累加数回溯
                }
            }
        }
        else if(candidate==target)
        {
            result.add(temp);
        }
        else
        {
            
        }
    }
    
}