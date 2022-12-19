`class Solution {
    
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        double[] ans = new double[queries.size()];
        Map<String, Map<String, Double>> g = new HashMap<>();
        bulidGraph(g, equations, values);
        int index = 0;     
        for (List<String> q: queries){
            String x = q.get(0);
            String y = q.get(1);
            if(!g.containsKey(x) || !g.containsKey(y)){
                ans[index] = -1.0;
                index++;
                continue;
            }
            HashSet<String> visited = new HashSet<>();
            ans[index] = divide(x, y, g, visited);
            index++;
        }
        return ans;
    }

     // get a / b
    private double divide(String a, String b, Map<String, Map<String, Double>> g, Set<String> visitied){
        if( a == b){
            return 1.0;
        }
        visitied.add(a);
        for(String next: g.get(a).keySet()){
            if(visitied.contains(next)) continue;
            double d = divide(next, b, g, visitied); //  d = next / b
            //  a /b =  next /b * a / next
            if(d > 0)
                return d * g.get(a).get(next);
        }
        return -1.0;
    }

     private void bulidGraph(Map<String, Map<String, Double>>  g , List<List<String>> equations, double[] values){
        int index = 0;
        for(List<String> e: equations){
            String a = e.get(0);
            String b = e.get(1);
            g.putIfAbsent(a, new HashMap<>());
            g.putIfAbsent(b, new HashMap<>());
            g.get(a).put(b, values[index]);   //  a -> b  : a / b
            g.get(b).put(a, 1.0 / values[index]); //  b -> a : b / a;
            index++;
            g.get(a).put(a, 1.0);
            g.get(b).put(b, 1.0);  //  自己到自己的权重为1
        }

    }
}`
这段代码在idea上可以运行，答案也正确， 但是复制到leetcode测试，输出全是-1，就错了，我觉得这个算法没毛病， 求大佬们解解惑！拜托，弄了一天了。。