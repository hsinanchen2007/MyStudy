class Solution {
    public List<List<Integer>> permute(int[] nums) {
        
        List<List<Integer>> result = new ArrayList<>();
        
        List<Integer> temp = new ArrayList<>();
        
        for(int i=0;i<nums.length;i++)
        {
            sort(nums[i],nums,temp,result);
        }//开始回溯
        
        return result;
    }
    
    public void sort(int num,int[] nums,List<Integer> temp,List<List<Integer>> result)
    {   
        boolean isequal = false;//用来判断将要添加到result的List<Integer>是否已经存在
        
        if(temp.size()==nums.length)//如果temp长度等于nums长度，则说明temp中的数都是不重复数字，可以添加到result
        {
            for(int i=0;i<result.size();i++)
            {
                for(int j=0;j<temp.size();j++)
                {
                    if(temp.get(j)!=result.get(i).get(j))
                    {
                        break;
                    }
                    else if(j==temp.size()-1)
                    {
                        isequal=true;
                    }
                }
            }//用于判断temp是否已经存在于result中
            if(isequal)
            {
                
            }
            else
            {
                result.add(temp);
            }
        }
        else//继续回溯
        {
            List<Integer> l = new ArrayList<>();
            
            if(temp.contains(num))//temp包含num，不再继续添加进行
            {
                
            }
            else
            {
                for(int i=0;i<temp.size();i++)
                {
                    l.add(temp.get(i));
                }
                l.add(num);//将temp中的数和num添加到l中
                for(int i=0;i<nums.length;i++)
                {
                    sort(nums[i],nums,l,result);
                }//回溯
            }
        }
    }
}