执行结果：
通过
显示详情
执行用时 :
8 ms
, 在所有 Java 提交中击败了
77.23%
的用户
内存消耗 :
49.1 MB
, 在所有 Java 提交中击败了
66.92%
的用户
```
class Solution {
    List<List<Integer>> list = new ArrayList<List<Integer>>();
    public List<List<Integer>> combine(int n, int k) {
        if(k>n)return list;
        List<Integer> ll = new ArrayList<Integer>();
        for(int i=1; i<=n;i++){
            ll.add(i);
        }
        if(k==n){
            list.add(ll);
            return list;
        }
        List<Integer> res = new ArrayList<Integer>();
        get(ll,k,res,0);
        return list;
    }
    private void get(List<Integer> ll, int k, List<Integer> res,int start){
        if(k==ll.size()-start){
            List<Integer> newl = new ArrayList<Integer>();
            newl.addAll(res);
            for(int v=start; v<ll.size();v++){
                newl.add(ll.get(v));
            }
            list.add(newl);
            return;
        }
        int i = ll.get(start);
        start++;
        
        get(ll,k,res,start);
        List<Integer> newl = new ArrayList<Integer>();
        newl.addAll(res);
        newl.add(i);
        if(k-1==0){
            list.add(newl);
        }else{
            get(ll,k-1,newl,start);
        }
        
    }
}
```
