
    两个变量可以求解，只有同属于一个根节点（属于同一集合）；
    根据给定方程，建立树结构；

```
import javafx.util.Pair;
class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        //先建立图（树）结构 
        HashMap<Integer, Pair<Integer, Double>> graph = new HashMap<Integer, Pair<Integer, Double>>();
        //建立变量索引，方便后面判断不存在变量返回-1
        HashMap<String, Integer> index = new HashMap<>();
        int varNum = 0;
        for(int i=0; i<values.length; i++){
            String child = equations.get(i).get(1);
            String parent = equations.get(i).get(0);
            if(!index.containsKey(child)){
                index.put(child, varNum++);
            }
            if(!index.containsKey(parent)){
                index.put(parent, varNum++);
            }
            double value = values[i];
            setValue(graph, index.get(child), index.get(parent), value);
        }
        // System.out.println(graph);
        int len = queries.size();
        double[] ret = new double[len];
        for(int i=0; i<len; i++){
            // System.out.println("---------");
            List<String> query = queries.get(i);
            String p = query.get(0);
            String c = query.get(1);
            if(!index.containsKey(p) || !index.containsKey(c)){
                ret[i] = -1.0;
                continue;
            }
            //求解的时候只需判定是否同属一个根节点，返回根节点时并返回商值；
            Pair<Integer, Double> root0 = getRoot(graph, index.get(p));
            Pair<Integer, Double> root1 = getRoot(graph, index.get(c));
            // System.out.println(root0);
            // System.out.println(root1);
            if(root0.getKey().equals(root1.getKey())){
                ret[i] = root1.getValue()/root0.getValue();
                // System.out.println("yes");
            }
            else{
                ret[i] = -1.0;
                // System.out.println("no");
            }
        }
        return ret;
    }
    void setValue(HashMap<Integer, Pair<Integer, Double>> graph, Integer child, Integer parent, double value){
        if(graph.containsKey(child)){
            Integer pp = graph.get(child).getKey();
            double vv = graph.get(child).getValue();
            if(vv>value){
                graph.put(child, new Pair<>(parent, value));
                setValue(graph, parent, pp, vv/value);
            }
            else{
                setValue(graph, pp, parent, value/vv);
            }
        }
        else{
            graph.put(child, new Pair<>(parent, value));
        }
        return;
    }
    Pair<Integer, Double> getRoot(HashMap<Integer, Pair<Integer, Double>> graph, Integer child){
        Integer root = child;
        double value = 1.0;
        while(graph.containsKey(root)){
            Pair<Integer, Double> tmp = graph.get(root);
            value *= tmp.getValue();
            root = tmp.getKey();
        }
        return new Pair<>(root, value);
    }
}
```
