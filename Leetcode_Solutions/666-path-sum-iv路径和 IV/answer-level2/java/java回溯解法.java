这个题要注意的点有两个：1.节点值可能是0，所以我在赋值的时候+1，这样可以区分开赋值与否。2.要算上根节点到所有叶子节点之和，往往大家会误解为根节点到最深叶子节点之和。
解题思路：把每一个节点都存储在数组中，数组数据形式为trees[D][P]=V+1;
```java
class Solution {
    int sum=0;
    int []nums;
    int deepth;
    int [][]trees;
    
    public int pathSum(int[] nums) {
        this.nums=nums;
        deepth=nums[nums.length-1]/100;
        trees=new int[5][(int)Math.pow(2,deepth-1)];
        for(int i=0;i<nums.length;i++)
        {
            int D=nums[i]/100;
            int P=nums[i]%100/10;
            int V=nums[i]%10;
            trees[D-1][P-1]=V+1;
        }
        dfs(0,0,0);
        return sum;
    }
    public void dfs(int D,int P,int now_sum)
    {
        //没有赋值;
        if(trees[D][P]==0)
        {
            //sum+=trees[D][P];
            return;
        }
       //要所有的根节点到叶子节点之和，而不是从根节点到最深的叶子节点之和
        if(D==deepth-1||trees[D+1][P*2]==0&&trees[D+1][P*2+1]==0)
        {
            sum+=now_sum+trees[D][P]-1;
            return;
        }
        
        dfs(D+1,P*2,now_sum+trees[D][P]-1);
        dfs(D+1,P*2+1,now_sum+trees[D][P]-1);
    }
}
```