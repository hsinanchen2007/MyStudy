对于每一个数字有两种选择：加进去或不加进去 一共有2^n次种情况
               
```
 求[1,2]子集
                        []
                       /   \
    start=1：         []    [1]
                     /  \   /  \
    start=2：       [] [2] [1] [1,2]




```          
  

代码：
```
class Solution {
    List res;
    ArrayList temp;
    public List<List<Integer>> subsets(int[] nums) {
        res=new ArrayList<ArrayList<Integer>>();
        temp=new ArrayList<Integer>();
        dfs(nums,0);
        return res;
    }
     public void dfs(int []nums,int start){
        if(start==nums.length){ // 找到一组方案 将其加入res
            res.add(new ArrayList<>(temp));
            return;
        }
            
        dfs(nums,start+1); // 不加nums[start] 直接进入下一层递归
        
        temp.add(nums[start]); //加nums[start]，nums[start]加入temp再进入下一层递归
        dfs(nums,start+1);
        temp.remove(temp.size()-1);//回溯
    }

}
```
