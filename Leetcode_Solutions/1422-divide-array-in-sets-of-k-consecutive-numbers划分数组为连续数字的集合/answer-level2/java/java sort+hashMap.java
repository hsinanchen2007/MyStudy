**思路**
1. 如果数组个数len不是k的倍数，说明不可能划分；
2. 拿一个Map统计每个元素出现的次数，然后从小到大遍历数组，每次拿第一个count不能0（遍历过程中，若元素被归到前面集合，count要更新的）的元素为起点，看看后面是否能构成k个连续的集合。若一发现不能构成k个连续集合，就立马reture false。
3. 为了更加快速的结束，可以定义一个集合数，总的需要划分的集合数为 $len / k$，如果遍历过程中的集合数达到这个总的集合数，就可以立马结束。

```java
class Solution {
 public boolean isPossibleDivide(int[] nums, int k) {
        int len = nums.length;

        if (len % k != 0) {
            return false;
        }

        Arrays.sort(nums);
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int num : nums) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }

        int needKSetCount = len / k;  // 需要的集合数（每个集合个数为k）
        int kCount = 0;   // 以下遍历过程集合数
        for (int num: nums) {
            int curNumCount = countMap.get(num);
            if (curNumCount == 0) {
                // 等于0说明被归到前面集合中了
                continue;
            }

            countMap.put(num, curNumCount - 1);
            for (int i = 1; i < k; i++) {
                int count = countMap.getOrDefault(num + i, 0);
                if (count == 0) {
                    // 等于0就说明以当前num为起点，找不到k个大小的连续集合
                    return false;
                }

                countMap.put(num + i, count - 1);
            }

            kCount++;
            // 当集合数已经达到需要的集合数，说明已经成功了
            if (kCount == needKSetCount) {
                return true;
            }
        }

        return true;
    }
}

```
**复杂度**
时间复杂度：$O(n*logn)$。由于存在sort。
空间复杂度：$O(n)$。因为有一个记录count的map。