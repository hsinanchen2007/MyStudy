### 解题思路
这题与全排列不同的是，指定了长度k，并且不能每个排列的数字不能都相同
所以，应该写个回溯函数，指明k以及首数字，当前list的长度==k时，加入并返回，否则从首数字开始依次递归下去。
### 代码

```java
class Solution {
    private List<List<Integer>> anslist=new ArrayList<>();
    
    private void backTrackCombine(int[] nums,List<Integer> list,int first,int k)
    {
        if(list.size()==k)
        {
            anslist.add(new ArrayList(list));
            return;
        }
        
        for(int i=first;i<nums.length;i++)
        {
            list.add(nums[i]);
            backTrackCombine(nums,list,i+1,k);
            list.remove(Integer.valueOf(nums[i]));
        }
    }
    public List<List<Integer>> combine(int n, int k) 
    {
        if(k==0||n==0)return anslist;
        
        int nums[]=new int[n];
        for(int i=0;i<n;i++)nums[i]=i+1;
        
        List<Integer> list=new ArrayList<>();
        backTrackCombine(nums,list,0,k);
        
        return anslist;
    }
}
```