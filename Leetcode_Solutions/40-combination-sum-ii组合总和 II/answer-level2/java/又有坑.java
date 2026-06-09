### 解题思路
此处撰写解题思路
if(i>0&&candidates[i-1]==candidates[i]&&!visit[i-1]) continue;
这一行避免了有相同的元素，造成结果集重复的问题；
如果之前访问过，便不再访问
### 代码

```java
class Solution {
    List<List<Integer>>ret=new ArrayList<>();
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<Integer>p=new ArrayList<>();
        boolean[]visit=new boolean[candidates.length];
        if(candidates==null||candidates.length==0||target==0) return ret;
        Arrays.sort(candidates);
        dfs(candidates,target,p,visit);
        return ret;
    }
    private void dfs(int[]candidates,int target,List<Integer>p,boolean[]visit){
        if(target==0){
            ret.add(new ArrayList(p));
            return;
        }
        for(int i=0;i<candidates.length;i++){
            if((p.size()>0&&p.get(p.size()-1)>candidates[i])||visit[i]) continue;
            if(i>0&&candidates[i-1]==candidates[i]&&!visit[i-1]) continue;
            if(candidates[i]<=target){
                visit[i]=true;
                p.add(candidates[i]);
                dfs(candidates,target-candidates[i],p,visit);
                visit[i]=false;
                p.remove(p.size()-1);
            }
        }

    }
}
```