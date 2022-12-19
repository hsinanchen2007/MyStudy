### 解题思路
1. 先遍历数组,存入到map,key为数值,value为频率
2. 数组排序,去重.
3. 双重循环
4. 三种情况:
4. a. 3个相同数都为0
5. b. 2个相同数,1个不同数
6. c. 3个不同数

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        HashMap<Integer, Integer> counter = new HashMap<>();
        for (int num : nums) {
            if (counter.containsKey(num)) {
                counter.put(num, counter.get(num) + 1);
            } else {
                counter.put(num, 1);
            }
        }

        // 排序,去重
        int[] arr = Arrays.stream(nums).sorted().distinct().toArray();

        // a. 3个相同数 都为0
        List<List<Integer>> res = new ArrayList<>();
        if (counter.get(0) != null && counter.get(0) >= 3) {
            res.add(Arrays.asList(0, 0, 0));
        }

        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {

                // b. 2个相同数,1个不同数
                // 2个i,1个j
                if (arr[i] * 2 + arr[j] == 0 && counter.get(arr[i]) >= 2) {
                    res.add(Arrays.asList(arr[i], arr[i], arr[j]));
                }
                // 1个i,2个j
                if (arr[i] + arr[j] * 2 == 0 && counter.get(arr[j]) >= 2) {
                    res.add(Arrays.asList(arr[i], arr[j], arr[j]));
                }

                // c. 3个不同数
                // 1个i,1个j,1个其他
                int c = -arr[i] - arr[j];
                if (c > arr[j] && counter.get(c) != null) {
                    res.add(Arrays.asList(arr[i], arr[j], c));
                }
            }
        }

        return res;
    }
}
```