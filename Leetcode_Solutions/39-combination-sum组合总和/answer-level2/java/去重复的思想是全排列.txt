### 解题思路
就是如何去重复很烦人
### 代码

```java
class Solution {
    private List<List<Integer>>res;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        this.res=new ArrayList<>();
        List<Integer>tmp=new ArrayList<>();
        if(target<0)
            return null;
        _Work(candidates,target,tmp,0,0);

        return this.res;
    }
    private void _Work(int[] candidates, int target, List<Integer> tmp,int k,int lever) {
        if(target<0)
            return;
        if(target==0){
            this.res.add(new ArrayList<>(tmp));
        }
        for(int i=k;i<candidates.length;i++){
            if(target-candidates[i]<0)
                continue;
            tmp.add(candidates[i]);
            _Work(candidates,target-candidates[i],tmp,i,lever+1);
            tmp.remove(lever);
        }
    }
}
```