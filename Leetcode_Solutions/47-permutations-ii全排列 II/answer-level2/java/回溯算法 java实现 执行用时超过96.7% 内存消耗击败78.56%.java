### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> ans;
    int n;
    int [] nums;
    public List<List<Integer>> permuteUnique(int[] nums) {
        this.nums=nums;
        Arrays.sort(nums);
        n=nums.length;
        ans=new ArrayList<>();
        if(n==0) return ans;
        Deque<Integer> queue=new ArrayDeque<>();
        int [] flag=new int [n];
        dfs(flag,queue,0);
        return ans;
    }
    public void dfs(int [] flag,Deque<Integer> queue,int len)
    {
        if(len==n)
        {
            ans.add(new ArrayList<>(queue));
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(i>=1&&nums[i]==nums[i-1]&&flag[i-1]==0) continue;
            if(flag[i]==0)
            {
                flag[i]=1;
                queue.addLast(nums[i]);
                dfs(flag,queue,len+1);
                queue.removeLast();
                flag[i]=0;
            }
        }
    }
}
```