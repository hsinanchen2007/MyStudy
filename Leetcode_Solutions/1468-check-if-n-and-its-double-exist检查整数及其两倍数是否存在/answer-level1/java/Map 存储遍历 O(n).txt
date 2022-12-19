显然，0 是特殊元素，0 和任何元素相乘都得0，因此，如果 0 的个数大于 1，直接返回 true 即可。
基本思路：map 存储，key 为元素值，value 为索引，然后第二次遍历，查找 2倍元素是否存在即可
时间复杂度O(n)，空间复杂度O(n)
```java
class Solution {
    public boolean checkIfExist(int[] arr) {
        if (arr == null || arr.length < 2) {
            return false;
        }
        Map<Integer, Integer> map = new HashMap<>();
        int num_zero = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0) {
                num_zero++;
            } else {
                map.put(arr[i], i);
            }
            if (num_zero > 1) {
                return true;
            }
        }
        for (int i = 0; i < arr.length; i++) {
            int temp = 2 * arr[i];
            if (map.containsKey(temp)) {
                return true;
            }
        }
        return false;
    }
}
```
