### 解题思路
递归好挫啊

### 代码

```java
class Solution {
    private List<List<Integer>>res;
    public List<List<Integer>> permute(int[] nums) {
        HashSet<Integer>visited=new HashSet<>();
        res=new LinkedList<>();
        List<Integer>tmp=new ArrayList<>();
        _Work(nums,tmp,visited);
        return res;
    }
    private void _Work(int[] nums,List<Integer> tmp, HashSet<Integer> visited) {
        if(tmp.size()==nums.length){
            res.add(new ArrayList<>(tmp));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(!visited.contains(i)){
                visited.add(i);
                tmp.add(nums[i]);
                _Work(nums,tmp,visited);
                tmp.remove(tmp.size()-1);
                visited.remove(i);
            }
        }
    }
}
```