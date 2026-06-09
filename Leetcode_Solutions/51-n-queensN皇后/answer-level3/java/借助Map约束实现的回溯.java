执行结果：
通过
显示详情
执行用时 :
116 ms
, 在所有 Java 提交中击败了
5.11%
的用户
内存消耗 :
51.2 MB
, 在所有 Java 提交中击败了
5.08%
的用户
```
class Solution {
    List<Integer> allset = new ArrayList<>();
    int nn=0;
    List<List<Integer>> res = new ArrayList<>();
    public List<List<String>> solveNQueens(int n) {
        nn=n;
        if(n==0)return null;
        
        for(int i=0; i<n; i++){
            allset.add(i);
        }
        
        Map<Integer,List<Integer>> map = new HashMap<>();
        for(int i=0; i<n; i++){
            map.put(i,new ArrayList<Integer>(allset));
        }
        
        get(0, map, new ArrayList<Integer>());
        List<List<String>> ret = new ArrayList<>();
        for(List<Integer> list:res){
            List<String> ls =new ArrayList<>();
            for(Integer i:list){
                StringBuffer sb = new StringBuffer();
                for(int kk=0; kk<n; kk++){
                    if(kk==i){
                        sb.append("Q");
                    }else{
                        sb.append(".");
                    }
                }
                ls.add(sb.toString());
            }
            ret.add(ls);
        }
        return ret;
        
    }
    private void get(int cur, Map<Integer,List<Integer>> map , List<Integer> list){
        
        
        List<Integer> left = map.get(cur);
        if(left.isEmpty()){
            return;
        }
        if(cur==nn-1 && left.size()==1){
            List<Integer> nlist = new ArrayList<>(list);
            nlist.add(left.get(0));
            res.add(nlist);
            return;
        }
       
        Set<Integer> touse = new HashSet<>(left);
        for(Integer i: touse){
            list.add(i);
            int z = i;
            int x = i;
            Map<Integer,Integer> backup1 = new HashMap<>();
            Map<Integer,Integer> backup2 = new HashMap<>();
            Map<Integer,Integer> backup3 = new HashMap<>();
            for(int k=cur+1;k<nn;k++){
                if(map.get(k).contains(Integer.valueOf(i))){
                    map.get(k).remove(Integer.valueOf(i));
                    backup1.put(k,Integer.valueOf(i));
                }
                z++;
                if(map.get(k).contains(Integer.valueOf(z))){
                    map.get(k).remove(Integer.valueOf(z));
                    backup2.put(k,Integer.valueOf(z));
                }
                x--;
                if(map.get(k).contains(Integer.valueOf(x))){
                    map.get(k).remove(Integer.valueOf(x));
                    backup3.put(k,Integer.valueOf(x));
                }
               
            }
            get(cur+1,map,list);
            
            backup1.entrySet().forEach(
                (Map.Entry<Integer,Integer> entry)->{
                    map.get(entry.getKey()).add(entry.getValue());
                }
            );
            backup2.entrySet().forEach(
                (Map.Entry<Integer,Integer> entry)->{
                    map.get(entry.getKey()).add(entry.getValue());
                }
            );
            backup3.entrySet().forEach(
                (Map.Entry<Integer,Integer> entry)->{
                    map.get(entry.getKey()).add(entry.getValue());
                }
            );
            
            list.remove(Integer.valueOf(i));
        }
    }
}
```
