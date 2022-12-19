### 解题思路
相信看过网上的解析，大家都知道使用DFS或者并查集进行求解，但是对于数据结构和算法不是很敏感的小伙伴而言，看半天还是云里雾里，尤其是元素关系的数值关系为什么那样建立？求解公式为什么可以一直递归或者循环乘除？至少对我来讲，确实花费了我很多时间，那么今天我就准备把这两个核心过程通过数学公式进行梳理一下。
![image.png](https://pic.leetcode-cn.com/cbc4685835f3df949bd139310a260a8b20a562c857c4eabed0695f96f4ef7b59-image.png)
![image.png](https://pic.leetcode-cn.com/4dda1b463cd1b47e74f7b4f06ddb07c39b6159f8bc1fe2e825cd959d2ac36707-image.png)
![image.png](https://pic.leetcode-cn.com/e898ea26a811fe7b20a0c632f774423acb33eeee0918e9f0402441d66eef9855-image.png)
![image.png](https://pic.leetcode-cn.com/5add5458c0d99f96667a9c551862deb62555e1a18f2ed98c6f053ce45e93cb03-image.png)



### 代码

```java
class Solution {
  /**
     * key : 当前节点
     * value : 其父节点
     */
    private Map<String, String> parents = new HashMap<>();
    /**
     * key : 当前节点
     * value : 父节点/当前节点
     */
    private Map<String, Double> values = new HashMap<>();

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        for (int i = 0; i < equations.size(); i++) {
            union(equations.get(i).get(0), equations.get(i).get(1), values[i]);
        }
        double[] result = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            String e = queries.get(i).get(0);
            String q = queries.get(i).get(1);
            if (!(parents.containsKey(e) && parents.containsKey(q))) {
                result[i] = -1;
                continue;
            }
            if (e.equals(q)) {
                result[i] = 1;
                continue;
            }
            String r1 = root(e);
            String r2 = root(q);
            if (!r1.equals(r2)) {
                // 如果两者不相等，说明两个节点是不连通的
                result[i] = -1;
                continue;
            }
            result[i] = pm(q)/pm(e);
        }
        return result;
    }

    private void union(String parent, String child, double value) {
        add(parent);
        add(child);
        String r1 = root(parent);
        String r2 = root(child);
        if (!r1.equals(r2)) {
            parents.put(r2, r1);
            values.put(r2, value * (pm(parent)/pm(child)));
        }
    }
    private void add(String x) {
        if (!parents.containsKey(x)) {
            parents.put(x, x);
            values.put(x, 1.0);
        }
    }



    /**
     * 找到x的根节点
     */
    private String root(String x) {
        while (!parents.get(x).equals(x)) {
            x = parents.get(x);
        }
        return x;
    }


    /**
     * 循环的pm函数
     */
    private double pm(String x) {
        double v = 1;
        while (!parents.get(x).equals(x)) {
            v*= values.get(x);
            x = parents.get(x);
        }
        return v;
    }

//    /**
//     * 递归的pm函数
//     * @param x
//     * @return
//     */
//    private double pm(String x){
//        return parents.get(x).equals(x)?1:values.get(x)*pm(parents.get(x));
//    }

}
```