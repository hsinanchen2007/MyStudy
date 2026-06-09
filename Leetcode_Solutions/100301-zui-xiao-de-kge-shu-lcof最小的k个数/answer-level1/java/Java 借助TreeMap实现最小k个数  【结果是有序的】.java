### 解题思路
借助于TreeMap来实现

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (arr == null || k == 0) {
            return new int[0];
        }
        if (arr.length <= k) {
            return arr;
        }

        // TreeMap的key是arr数组的元素, value是当前元素出现的个数
        // count表示当前map总共存了多少个数字（包含重复的）
        TreeMap<Integer, Integer> map = new TreeMap<>();
        int count = 0;
        for (int num : arr) {
            // 遍历数组，若当前map中的数字个数小于k，则map中当前数字对应个数+1
            if (count < k) {
                map.put(num, map.getOrDefault(num, 0) + 1);
                count++;
                continue;
            } 
            // 取出map中最大的Key（即最大的数字), 判断当前数字与map中最大数字的大小关系：
            // 若当前数字比map中最大的数字还大，就直接忽略；
            // 若当前数字比map中最大的数字小，则将当前数字加入map中，并将map中的最大数字的个数-1。
            Map.Entry<Integer, Integer> entry = map.lastEntry();
            if (entry.getKey() > num) {
                map.put(num, map.getOrDefault(num, 0) + 1);
                if (entry.getValue() == 1) {
                    map.pollLastEntry();
                } else {
                    map.put(entry.getKey(), entry.getValue() - 1);
                }
            }
            
        }

        // 根据map中的数据构建最终的返回结果
        int[] res = new int[k];
        int index = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            count = entry.getValue();
            while (count-- > 0) {
                res[index++] = entry.getKey();
            }
            // map中出现次数为0的key通过上面的循环会直接忽略
        }
        return res;
    }
}
```