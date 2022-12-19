### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.HashMap;
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < time.length; i++)
            //hashmap中放入mod 60的余数
            map.put(time[i] % 60, map.getOrDefault(time[i] % 60, 0) + 1);
        int result = 0;
        for (Integer i : map.keySet()) {
            int a = map.get(i);
            int b = map.getOrDefault(60 - i, 0);
            //用组合原理相乘 30 60 0 的情况特殊 处理
            if (i == 30 || i == 60 || i == 0)
                result += a * (a - 1);
            else
                result += a * b;
        }
        //因为每对算了两次 最后除以2
        return result / 2;
    }
}
```