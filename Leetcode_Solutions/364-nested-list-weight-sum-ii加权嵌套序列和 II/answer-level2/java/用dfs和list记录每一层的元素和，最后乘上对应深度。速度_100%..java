```
class Solution {
    public int depthSumInverse(List<NestedInteger> nestedList) {
        List<Integer> list=new ArrayList<>();
        int result=0;
        dfs(nestedList,list,0);

        for (int i=0;i<list.size();i++){
            result+=list.get(i)*(list.size()-i);
        }
        return result;
    }

    public void dfs(List<NestedInteger> nestedList,List<Integer> list,int depth){
        if (nestedList==null){
            return;
        }

        for (int i=0;i<nestedList.size();i++){
            if (nestedList.get(i).isInteger()){
                while (list.size()<=depth){
                    list.add(0);
                }
                list.set(depth,list.get(depth)+nestedList.get(i).getInteger());
            }
            else{
                dfs(nestedList.get(i).getList(),list,depth+1);
            }
        }
    }
}
```

