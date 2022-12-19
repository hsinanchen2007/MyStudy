### 解题思路
此处撰写解题思路
一开始以为和之前写的dfs差不多，但是一直有一个问题，就是List不同顺序但是相同元素的会重复出现在结果集中。要解决这个问题。只要在for循环中加一个限制条件让list为递增的便可。
### 代码

```java
class Solution {
    List<List<Integer>>ret=new ArrayList<>();
    public List<List<Integer>> combine(int n, int k) {
        List<Integer>p=new ArrayList<>();
        boolean visit[]=new boolean[n];
        if(n==0||k==0) return ret;
        dfs(n,k,visit,p);
        return ret;
    }
    private void dfs(int n,int k,boolean[]visit,List<Integer>p){
        if(p.size()==k){
            ret.add(new ArrayList(p));
            return;
        }
        for(int i=0;i<n;i++){
            if(p.size()>0&&p.get(p.size()-1)>i+1) continue;
            if(visit[i]) continue;
            visit[i]=true;
            
            p.add(i+1);
            dfs(n,k,visit,p);
            p.remove(p.size()-1);
            visit[i]=false;
        }
    }
}
```