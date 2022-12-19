参考了 @onesilverbullet 以及 @Frank 的题解,写了JAVA版本的

```
class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, Integer> nodeMap = new HashMap<>();

        int n = 0;
        for (int i = 0; i < equations.size(); i++) {
            List<String> equation = equations.get(i);
            String sa = equation.get(0);
            String sb = equation.get(1);
            if (!nodeMap.containsKey(sa)) {
                nodeMap.put(sa, n++);
            }

            if (!nodeMap.containsKey(sb)) {
                nodeMap.put(sb, n++);
            }
        }

        double[][] graph = new double[n][n];

        for (int i = 0; i < equations.size(); i++) {
            List<String> equation = equations.get(i);
            int ia = nodeMap.get(equation.get(0));
            int ib = nodeMap.get(equation.get(1));

            graph[ia][ib] = values[i];
            graph[ib][ia] = 1/values[i];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (graph[i][j] == 0 && graph[i][k] != 0 && graph[k][j] != 0) {
                        graph[i][j] = graph[i][k]*graph[k][j];
                    }
                }
            }
        }

        double[] res = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            List<String> query = queries.get(i);

            if (!nodeMap.containsKey(query.get(0)) || !nodeMap.containsKey(query.get(1))) {
                res[i] = -1.0f;
            } else {
                double value = graph[nodeMap.get(query.get(0))][nodeMap.get(query.get(1))];
                res[i] = value != 0 ? value : -1.0f;
            }
            
        }

        return res;

    }
}
```
