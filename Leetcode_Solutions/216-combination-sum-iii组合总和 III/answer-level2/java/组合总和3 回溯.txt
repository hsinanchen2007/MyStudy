```
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> combinationSum3(int k, int n) {
        //和组合1，2比，限制了数目为k个
        int[] visited = new int[9];
        if(k == 0 || n == 0) return res;
        List<Integer> cur = new ArrayList<>();
        dfs(1, cur,k,n,visited);
        return res;        
    }
    private void dfs(int start, List<Integer> cur, int k, int n, int[] visited){//添加start 避免出现123.231这种
        if(cur.size() == k && n==0)//添加到res的条件
            {res.add(new ArrayList<>(cur));
             return;}
        for(int i=start;i<10;i++){ //遍历回溯
            if(visited[i-1]==1)   //visit下标为0-8，数字i为1-9.所以注意所有visit下标减一
                continue;  
            cur.add(i);
            visited[i-1]=1;
            dfs(i,cur,k,n-i,visited);
            visited[i-1]=0;//visit 要改回来
            cur.remove(cur.size()-1);
        }
        
        
    }
}
```
