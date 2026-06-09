class Solution
{
    public List<List<Integer>> subsets(int[] nums) 
    {
        List<List<Integer>> lists = new ArrayList(); 
        List<Integer> list1 = new ArrayList();       
        lists.add(list1);                            
        for(int i=0;i<nums.length;i++)               
        {  
           int m =lists.size();                      
           for (int j=0;j<m;j++)
           {
               List<Integer>list2 =new ArrayList(lists.get(j)); 
               list2.add(nums[i]);                              
               lists.add(list2);                                
           }         
        }      
        return  lists;    
    }   
}
外层循环选择元素，内层循环遍历lists，取出每个链表，添加新的被选择元素后，添加回lists。