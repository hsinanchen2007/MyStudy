### 解题思路
此处撰写解题思路
此题稍稍有点不同的就是集合里面可能存在相同的元素，这样就很有可能出现重复的子集，这时就需要一个visit数组来判断是否产生重复了，就是下面dfs的for循环内的第一行代码。
### 代码

```java
class Solution {
    List<List<Integer>>ret=new ArrayList<>();
    List<Integer>p=new ArrayList<>();
    boolean[]visit;
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        visit=new boolean[nums.length];
        if(nums==null||nums.length==0) return ret;
        Arrays.sort(nums);
        for(int i=0;i<=nums.length;i++){
            dfs(0,nums,i);
        }
        return ret;
    }
    private void dfs(int s,int[]nums,int n){
        if(p.size()==n){
            ret.add(new ArrayList(p));
            return;
        }
        for(int i=s;i<nums.length;i++){
            if(i>0&&nums[i-1]==nums[i]&&!visit[i-1]) continue;
            visit[i]=true;
            p.add(nums[i]);
            dfs(i+1,nums,n);
            p.remove(p.size()-1);
            visit[i]=false;
        }
    }
}
```