### 解题思路
现将数组从小到大排序，开始从数组最后一位开始递归
1.将当前数一直加入到tmp和cur中，如果超过了target就跳出循环
2.将多余的从cur减掉、tmp中删掉。同时向前一个数递归

### 代码

```java
class Solution {
    List<List<Integer>> res=new ArrayList();
    List<Integer> tmp=new ArrayList();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        dfs(candidates,target,candidates.length-1,0);
        return res;
    }
    private void dfs(int[] candidates,int target,int index,int cur){
        if(index<0)return;
        int count=0;
        while(cur<target){
            cur+=candidates[index];
            tmp.add(candidates[index]);
            count++;
        }
        if(cur==target)res.add(new ArrayList(tmp));
        while(count>0){
            tmp.remove(tmp.size()-1);
            cur-=candidates[index];
            count--;
            dfs(candidates,target,index-1,cur);            
        }

    }
}
```