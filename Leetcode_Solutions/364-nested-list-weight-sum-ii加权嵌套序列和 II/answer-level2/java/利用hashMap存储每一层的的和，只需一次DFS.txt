```
class Solution {
    Map<Integer,Integer> nodeSumMap = new HashMap<>();
    public int depthSumInverse(List<NestedInteger> nestedList) {
        dfs(nestedList,1);
        int len = nodeSumMap.size();
        // System.out.print(" "+len);
        int sum =0;
        for(Integer key:nodeSumMap.keySet()){
            sum+=nodeSumMap.get(key)*(len-key+1);
        }
        return sum;
    }

    void dfs(List<NestedInteger> nestedList,int level){
        int sum = 0;
        for(NestedInteger nested:nestedList){
            if(nested.isInteger()){
                sum+=nested.getInteger();
            }else{
                dfs(nested.getList(),level+1);
            }
        }
        if(nodeSumMap.containsKey(level)){//记录当前层所有所有数字节点的和
            nodeSumMap.put(level,nodeSumMap.get(level)+sum);
        }else{
            nodeSumMap.put(level,sum);
        }
    }
}
```

