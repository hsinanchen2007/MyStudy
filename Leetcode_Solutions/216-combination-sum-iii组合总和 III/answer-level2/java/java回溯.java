### 解题思路


### 代码

```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<List<Integer>>();
    private List<Integer> temp = new ArrayList<Integer>();
    public List<List<Integer>> combinationSum3(int k, int n) {
        for(int i=1;i<=9;i++)
        {
             backtrack(k,n,i);
             temp.remove(temp.size()-1);//可优化，不想改了
        }
        
        return ans;
    }
    public void backtrack(int k,int n, int i)//回溯
    {
        temp.add(i);
        if(temp.size()==k&&sum(temp)==n)
         ans.add(new ArrayList<Integer>(temp));
        if(temp.size()==k)
        return;
        
        for(int j=i+1;j<=9;j++)
        {
            backtrack(k,n,j);
            temp.remove(temp.size()-1);
        }
    }
    public int sum(List<Integer> nums)
    {
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums.get(i);
        }
        return s;
    }
}
```