### 解题思路
看来剪枝效果很好
### 代码

```java
class Solution {
    private List<List<Integer>>res;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        this.res=new ArrayList<>();
        List<Integer>tmp=new ArrayList<>();
        if(target<0)
            return null;
        Arrays.sort(candidates);
        _Work(candidates,target,tmp,0,0);
        return this.res;
    }
    private void _Work(int[] candidates, int target, List<Integer> tmp,int k,int lever) {
        int previous=Integer.MIN_VALUE;
        if(target==0){
            this.res.add(new ArrayList<>(tmp));
        }
        for(int i=k;i<candidates.length;i++){
            if(target-candidates[i]<0)
                break;
            if(previous==candidates[i])
                continue;
            else
                previous=candidates[i];
            tmp.add(candidates[i]);
            _Work(candidates,target-candidates[i],tmp,i+1,lever+1);
            tmp.remove(lever);
        }
    }
}
```