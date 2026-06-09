### 解题思路
    先用map将单个数出现的次数记录一下，之后从map中取出次数和数组长度做除法。

### 代码

```java
class Solution {
    public int findSpecialInteger(int[] arr) {
       if (arr == null) {
            return -1;
        }
        // 记录数字出现次数
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (map.keySet().contains(arr[i])) {
                map.put(arr[i], map.get(arr[i]) + 1);
            } else {
                map.put(arr[i], 1);
            }
        }
        int arrLength = arr.length;
        int ret = 0;
        // 拿出每个数的出现次数，跟数组长度做除法
        for (int num : map.keySet()) {
            int count = map.get(num);
            if (((float)count/arrLength)> 0.25) {
                ret = num;
                break;
            }
        }
        return ret;
    }
}
```