### 解题思路
此处撰写解题思路
贪心算法：本题中为了获得最大值，贪心的把所有节点按照values排序，依次选择加入结果集，当节点满足要求即(相同labels数目<=use_limit)加入贪心结果集，反之跳过，直至循环结束（结果集总个数< num_wanted）。
保存（labels的数目选择哈希表来保存提高速度）

### 代码

```java
class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
       int[][] in = new int[values.length][2];
        for (int i = 0; i < values.length; i++) {
            in[i][0] = values[i];
            in[i][1] = labels[i];
        }
        // 对节点进行排序
        Arrays.sort(in, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o2[0] - o1[0];
            }
        });
        int sum = 0;
        int num = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < values.length; i++) {
            if (num >= num_wanted) {
                break;
            }
            if (map.containsKey(in[i][1])) {
                if (map.get(in[i][1]) < use_limit) {
                    map.put(in[i][1], map.get(in[i][1]) + 1);
                    sum += in[i][0];
                    num++;
                }
            } else {
                map.put(in[i][1], 1);
                  sum += in[i][0];
                  num++;
            }
        }
        return sum;
    }
}
```