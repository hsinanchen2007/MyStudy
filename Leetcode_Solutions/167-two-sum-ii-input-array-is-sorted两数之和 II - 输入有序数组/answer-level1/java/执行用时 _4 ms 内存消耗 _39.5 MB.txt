### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
 // 判断数组的元素个数是否不小于2
        if (numbers.length < 2) {
            return null;
        }

        Map<Integer, Integer> map = new HashMap<>();
        int x = 0;
        int y = 0;

        for (int i = 0; i < numbers.length; i++) {
            if (!map.containsKey(numbers[i])) {
                map.put(numbers[i], i);
            }

            if (map.containsKey(target - numbers[i])) {
                //得到元素的索引
                x = i + 1;
                y = map.get(target - numbers[i]) + 1;
            }
        }

        return (x > y) ? new int[]{y, x} : new int[]{x, y};
    }
}
```