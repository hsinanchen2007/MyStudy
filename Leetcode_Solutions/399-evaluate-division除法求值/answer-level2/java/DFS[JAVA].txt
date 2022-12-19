```
// DFS
// time complexity O(n * m)
class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, Map<String, Double>> map = new HashMap<>();
        for (int i = 0; i < values.length; i++) {
            map.computeIfAbsent(equations.get(i).get(0), k -> new HashMap<>()).put(equations.get(i).get(1), values[i]);
            map.computeIfAbsent(equations.get(i).get(1), k -> new HashMap<>()).put(equations.get(i).get(0), 1 / values[i]);
        }
        double[] res = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            res[i] = dfs(queries.get(i).get(0), queries.get(i).get(1), 1.0, map, new HashSet<>());
        }
        return res;
    }

    private double dfs(String s, String t, double res, Map<String, Map<String, Double>> m, Set<String> seen) {
        if (!m.containsKey(s) || seen.contains(s)) {
            return -1;
        }
        if (s.equals(t)) {
            return res;
        }
        seen.add(s);
        Map<String, Double> next = m.get(s);
        for (String c : next.keySet()) {
            double subRes = dfs(c, t, res * next.get(c), m, seen);
            if (subRes != -1) {
                return subRes;
            }
        }
        return -1;
    }
}
```