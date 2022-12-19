### 解题思路
剪枝条件：
先把nums排序，遇到相邻的数是相同的需要剪枝，要么都选，要么都不选，只能选一个的话选前一个
flag[i]=1表示已经访问过nums[i]
那么 nums[i]==nums[i-1]&&flag[i-1]==0 则可以起到剪枝作用

### 代码

```java
class Solution {
    List<List<Integer>> ans;
    int n;
    int [] nums;
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        n=nums.length;
        Arrays.sort(nums);
        this.nums=nums;
        ans=new ArrayList<>();
        List<Integer> t=new ArrayList<>();
        ans.add(t);
        if(n==0) return ans;
        int [] flag=new int [n];
        Deque<Integer> way=new ArrayDeque<>();
        dfs(way,0,flag,-1);
        return ans;
    }
    public void dfs(Deque<Integer> way,int len,int [] flag,int now)
    {
         if(len==n)
         {
             return;
         }
         for(int i=now+1;i<n;i++)
         {
             if(i>=1&&nums[i]==nums[i-1]&&flag[i-1]==0) continue;
             if(flag[i]==0)
             {
                 flag[i]=1;
                 way.addLast(nums[i]);
                 ans.add(new ArrayList<>(way));
                 dfs(way,len+1,flag,i);
                 flag[i]=0;
                 way.removeLast();
             }
         }
    }
}
```