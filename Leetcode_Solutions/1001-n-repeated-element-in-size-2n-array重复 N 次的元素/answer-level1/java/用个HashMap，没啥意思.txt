### 解题思路
HashMap计数。

### 代码

```java
class Solution {
    public int repeatedNTimes(int[] A) {
        Map<Integer, Integer> map = new HashMap<>();
        int res = 0;
        for (int key : A) {
            if (map.containsKey(key)) {
                if(map.get(key) + 1 == A.length / 2){
                    res = key;
                    break;
                }
                map.put(key, map.get(key) + 1);
            } else {
                map.put(key, 1);
            }
        }
        return res;
    }
}
```