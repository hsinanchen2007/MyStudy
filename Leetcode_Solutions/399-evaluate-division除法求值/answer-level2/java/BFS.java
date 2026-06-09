### 解题思路
把每个除数、被除数当成图中的一个点，一条等式当成图的边
利用   `Map<String, Map<String, Double>> cache` 来保存所有边
例如 `a / b = 2.0`, `a / c = 3.0`，则cache中有a键，其值为一个字典 `Map<String, Double>`
其中字典有键b与c，值为2.0 与3.0 ，并且还要同时保存`b / a`, `c / a`的值（有向图）

然后BFS，边遍历点边算到达此点的值
先把要求的等式的被除数与当前值1.0放入队列，相当于BFS的第一点，然后从队列头开始扩展，
经过一条边就要把 边的另一端 和 当前值与边的乘积 放入队列
直到达到除数。

当然BFS前要判断点可不可达，直接查`cache`有没有被除数或除数。

### 代码

```java
class Solution {
    //双向路径
    private Map<String, Map<String, Double>> cache = new HashMap<String, Map<String, Double>>();
    
    class Strdou {//放入队列的元素，
        public String x;    //除数
        public Double val;  //当前值
        public Strdou(String xx, Double cc) {
            x = xx;
            val = cc;
        }
    }

    private double BFS(List<String> query)
    {
        if (!cache.containsKey(query.get(0)||!cache.containsKey(query.get(1)) { //不可达
            return -1.0;
        }
        if (query.get(0).equals(query.get(1))) {    //相等返回1
            return 1.0;
        }
        Queue<Strdou> que = new LinkedList<Strdou>();
        Set<String> paths = new HashSet<String>();  //记录已经走过的点
        que.offer(new Strdou(query.get(0), 1.0));
        paths.add(query.get(0));

        while (!que.isEmpty()) {
            Strdou s = que.poll();
            Map<String, Double> c = cache.get(s.x);
            //从key点开始遍历周围的点
            for (String key : c.keySet()) {
                if (paths.contains(key)) {
                    continue;
                }
                paths.add(key);//标记走过
                que.offer(new Strdou(key, s.val * c.get(key)));
                if (key.equals(query.get(1))) {
                    return s.val * c.get(key);
                }
            }
        }
        return -1.0;


    }

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        if (queries.size() == 0) {  //别算了
            return null;
        }
        for (int i = 0; i < equations.size(); i++) {
            String first = equations.get(i).get(0);
            String second = equations.get(i).get(1);
            //保存正向的路径    a / b
            if (cache.containsKey(first)) {
                cache.get(first).put(second, values[i]);
            }
            else {
                Map<String, Double> c = new HashMap<String, Double>();
                c.put(second, values[i]);
                cache.put(first, c);
            }
            //保存逆向的路径    b / a
            if (cache.containsKey(second)) {
                cache.get(second).put(first, 1.0 / values[i]);
            }
            else {
                Map<String, Double> c = new HashMap<String, Double>();
                c.put(first, 1.0 / values[i]);
                cache.put(second, c);
            }
        }

        double[] res = new double[queries.size()];
        
        for (int i = 0; i < res.length; i++) {
            res[i] = BFS(queries.get(i));
        }
        return res;
    }
}
```