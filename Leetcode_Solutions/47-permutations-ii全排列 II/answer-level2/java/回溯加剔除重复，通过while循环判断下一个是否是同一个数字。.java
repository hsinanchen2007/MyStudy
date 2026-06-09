### 解题思路

回溯问题
用一个visited数组来表示对应的数字有没有之前被使用过，只用没用过的，
并且在每次操作之后，判断后一个数字是不是一样的，如果是一样的，就跳过该数字，不能刚把1加进去，并减出来，之后又回溯了后一个位置的1，
这样就能避免上述的情况，而112这种情况可以被回溯到，因为在第一个1被visited的时候，进了helper，是可以选中当前的1，保证了11111这种就出现一次。
### 代码

```java
class Solution{
    List<List<Integer>> res=new ArrayList<>();
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<Integer> temp=new ArrayList<>();
        boolean[] visited=new boolean[nums.length];
        for (int i=0;i<nums.length;i++)
            visited[i]=false;
        helper(nums,visited,temp);
        return res;

    }
    public void helper(int[] nums, boolean[] visited,List<Integer> temp)
    {
        if(temp.size()==nums.length)
        {
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i=0;i<nums.length;i++)
        {
            if(!visited[i])
            {
                visited[i]=true;
                temp.add(nums[i]);
                helper(nums,visited,temp);
                temp.remove(temp.size()-1);
                visited[i]=false;
                while(i+1<nums.length && nums[i]==nums[i+1])
                    i++;
            }

        }
    }
}

```