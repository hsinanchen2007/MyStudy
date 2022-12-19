[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_399_calcEquation.java)

```java
    /**
     * 解题思路：
     * 利用HashMap保存每个参数与其他参数直接的关系，当要求解新的方程式的时候，通过之前的关系递归求解出结果
     * 方法不是最优，自己完全构思出来的，如需最优的可以参考他人的
     *
     * 执行用时 :7 ms, 在所有 Java 提交中击败了 6.74%的用户
     * 内存消耗 : 35.9 MB, 在所有 Java 提交中击败了55.00%的用户
     *
     * @param equations
     * @param values
     * @param queries
     * @return
     */
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        double[] ret = new double[queries.size()];
        HashMap<String, List<String>> map = new HashMap();
        //将方程式和结果拆解成map，key为参数，value为对应其他参数的值的集合
        for (int i = 0; i < equations.size(); i++) {
            String divisor = equations.get(i).get(0);
            String dividend = equations.get(i).get(1);
            double result = values[i];
            //保存方程式结果
            List<String> divisorR = map.getOrDefault(divisor, new ArrayList<>());
            divisorR.add(result + "_" + dividend);
            map.put(divisor, divisorR);
            List<String> dividendR = map.getOrDefault(dividend, new ArrayList<>());
            dividendR.add(1 / result + "_" + divisor);
            map.put(dividend, dividendR);
        }

        //求解
        for (int i = 0; i < queries.size(); i++) {
            String divisor = queries.get(i).get(0);
            String dividend = queries.get(i).get(1);
            List<String> divisorR = map.get(divisor);
            List<String> dividendR = map.get(dividend);
            //变量是否存在
            if (divisorR == null || dividendR == null) {
                ret[i] = -1.0;
                continue;
            }
            //是否相等
            if (divisor.equals(dividend)) {
                ret[i] = 1.0;
                continue;
            }
            List<String> divisors = new LinkedList<>();
            //递归求解
            Double dfs = dfs(map, divisorR, divisors, dividend);
            ret[i] = dfs == null ? -1.0 : dfs;
        }
        return ret;
    }

    private Double dfs(Map<String, List<String>> map, List<String> divisorR, List<String> divisors, String dividend) {
        for (int i = 0; i < divisorR.size(); i++) {
            double multi = 1;
            String[] split = divisorR.get(i).split("_");
            if (divisors.contains(split[1])) {
                continue;
            }
            multi *= Double.parseDouble(split[0]);
            if (split[1].equals(dividend)) {
                return multi;
            } else {
                divisors.add(split[1]);
                Double dfs = dfs(map, map.get(split[1]), divisors, dividend);
                divisors.remove(split[1]);
                if (dfs != null) {
                    return multi * dfs;
                }
            }
        }
        return null;
    }

```