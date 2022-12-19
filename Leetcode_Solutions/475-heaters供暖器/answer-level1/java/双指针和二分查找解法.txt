#### 双指针模型

```java
class Solution {
    // 双指针
    public int findRadius(int[] houses, int[] heaters) {
        // 1. 排序
        Arrays.sort(houses);
        Arrays.sort(heaters);

        int res = 0;
        int i = 0;
        // 2. 双指针计算最大半径
        // 下面的代码最难懂的地方是 Math.abs(heaters[i] - house) >= Math.abs(heaters[i + 1] - house)
        // 我们举一个例子来说明这行代码的意思：
        // houses：1，2，3，4
        // heaters：1，4
        // 对于 house 1，heater 1 比 heater 4 更接近 house1，所以不将 i 移动到 i + 1
        // 对于 house 2，heater 1 比 heater 4 更接近 house2，所以不将 i 移动到 i + 1
        // 对于 house 3，heater 4 比 heater 1 更接近 house3，所以将 i 移动到 i + 1
        // 对于 house 4，依次类推
        for (int house : houses) {
            while (i < heaters.length - 1 &&
                    Math.abs(heaters[i] - house) >= Math.abs(heaters[i + 1] - house)) {
                i++;
            }
            // 更新最大半径
            res = Math.max(res, Math.abs(heaters[i] - house));
        }

        return res;
    }
}
```

#### 二分查找
```java
class Solution {
    // 二分查找
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);

        int res = 0;
        
        for (int house : houses) {
            // 二分搜索当前 house 在 heaters 中的位置
            int index = binarySearch(heaters, house);

            if (index < 0) { // 说明没找到，index 等于当前的 house 应该在 heaters 的位置的负数
                // 计算出当前的 house 应该在 heaters 数组中的位置
                index = -(index + 1);
                // 计算当前 house 离左边最近的 heater 的距离
                int leftDist = index - 1 >= 0 ? house - heaters[index - 1] : Integer.MAX_VALUE;
                // 计算当前 house 离右边最近的 heater 的距离
                int rightDist = index < heaters.length ? heaters[index] - house : Integer.MAX_VALUE;

                // 当前 house 需要的 heater 的半径取 leftDist 和 rightDist 的最小值
                res = Math.max(res, Math.min(leftDist, rightDist)); 
            }
        }

        return res;
    }

    private int binarySearch(int[] heaters, int house) {
        int low = 0;
        int hight = heaters.length - 1;
        while (low <= hight) {
            int mid = (low + hight) >>> 1;

            if (heaters[mid] < house) {
                low = mid + 1;
            } else if (heaters[mid] > house) {
                hight = mid - 1;
            } else {
                return mid;
            }
        }
        return -(low + 1);
    }
}
```