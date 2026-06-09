### 解题思路
 思路：dfs找两个点的路径即可,总结一下；两种dfs，一种是点dfs，找路径，一种是边dfs，找欧拉路径使用，也叫Hierholzer算法
 一点体会:因为这里在dfs的中途可能就返回，处理看起来复杂，其实只要考虑(1)如何将当前的值保存，
 回溯之后因着当前层值如何继续查找，(2)如何正确恰当的在找到正确值之后直接返回，而不是继续查找所有点，
 所以这里将这中情况定义为"dfs半路查找"

### 代码

```java
class Solution {
    
    
    
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String,Map<String,Double>> map=new HashMap<>();
        // 建立双向表
        for(int i=0;i<equations.size();i++){
            Map<String,Double> mapInMapLast=map.computeIfAbsent(equations.get(i).get(0),k->new HashMap<>());
            mapInMapLast.put(equations.get(i).get(1),values[i]);
            Map<String,Double> mapInMapNext=map.computeIfAbsent(equations.get(i).get(1),k->new HashMap<>());
            mapInMapNext.put(equations.get(i).get(0),(1/values[i]));
        }
        double[] ansArray=new double[queries.size()];
        for(int i=0;i<queries.size();i++){
            ansArray[i]=dfs(queries.get(i).get(0),queries.get(i).get(1),1.0,map,new ArrayList<>());
        }
        return ansArray;
    }
   
    public Double dfs(String src,String fin,Double value,Map<String,Map<String,Double>> map,List<String> seen){
        seen.add(src);
        Map<String,Double> neighbor=map.get(src);
        if(neighbor==null){
            return -1.0;
        }
        for(Map.Entry<String,Double> neighEntry:neighbor.entrySet()){
            if(fin.equals(neighEntry.getKey())){
                return value*neighEntry.getValue();
            }
            if(seen.contains(neighEntry.getKey())){
                continue;
            }
            Double dfsValue=dfs(neighEntry.getKey(),fin,value*neighEntry.getValue(),map,seen);
            if(dfsValue>0){
                return dfsValue;
            }
        }
        return -1.0;
    }

}
```