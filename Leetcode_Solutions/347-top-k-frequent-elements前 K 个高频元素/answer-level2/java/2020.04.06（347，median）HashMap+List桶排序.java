### 解题思路
本题的最优解法是利用**桶排序**

- 首先创建一个 `Map` 记录数组中每个元素的频率

- 然后创建一个数组将元素**按照频率**升序存放在 `list` 中

- 定义 `i` 来接收每个元素的频率，并且元素就按照自己的**频率作为数组的下标**存储

- 最后对数组**逆向**求出前 `k`个高频率的元素，放入结果集 `ans` 即可。

### 代码

```java []
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> ans = new ArrayList<>();
        if (nums == null) {
            return ans;
        }
        // 记录每个元素的频率
        Map<Integer,Integer> map = new HashMap<>();
        for (int n : nums) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        // 按照 map 中元素的频率来创建数组，高频率的元素位于数组最后边
        List<Integer>[] tmp = new List[nums.length + 1];
        for (int key : map.keySet()) {
            // 定义 i 来接收每个元素的频率值
            int i = map.get(key);
            if (tmp[i] == null) {
                tmp[i] = new ArrayList();
            }
            // 将对应频率的元素放入以频率为下标的数组中
            tmp[i].add(key);
        }
        // 逆向找出前 k 高频率的元素
        for (int i = tmp.length - 1; i >= 0 && ans.size() < k; i--) {
            if (tmp[i] == null) {
                continue;
            }
            // 将当前频率下的元素放入结果集 ans 中
            ans.addAll(tmp[i]);
        }
        return ans;
    }
}
```