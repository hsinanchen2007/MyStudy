### 解题思路
哈希表解法

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
              if (numbers.length < 2) {
            return null;
        }
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < numbers.length; i++) {
            map.put(numbers[i], i);
        }
        for (int i = 0; i < numbers.length; i++) {
            int rest=target-numbers[i];
            if (map.containsKey(rest)) {
                return new int[]{i + 1, map.get(rest)+1};
            }

        }
        return null;  
    }
}
```