### 解题思路
此处撰写解题思路
让下一次搜索的元素都比上一次的大，只需要每次循环的时候将i的初值设为上一次搜索的下一个值，因为nums数组是按照从小到大的顺序排列的，所以他的下一个元素一定打，这样，减少了循环的次数。
### 代码

```java
class Solution {
    List<List<Integer>>ret=new ArrayList<>();
    public List<List<Integer>> subsets(int[] nums) {
        if(nums==null||nums.length==0) return ret;
        
        List<Integer>p=new ArrayList<>();
        for(int i=0;i<=nums.length;i++){
            dfs(nums,p,i,0);
        }
        return ret;
    }
    private void dfs(int[]nums,List<Integer>p,int n,int s){
        if(p.size()==n){
            ret.add(new ArrayList(p));
            return;
        }
        for(int i=s;i<nums.length;i++){
            //if(p.size()>0&&p.get(p.size()-1)>=nums[i]) continue;
            p.add(nums[i]);
            dfs(nums,p,n,i+1);
            p.remove(p.size()-1);
        }
    }
}
```