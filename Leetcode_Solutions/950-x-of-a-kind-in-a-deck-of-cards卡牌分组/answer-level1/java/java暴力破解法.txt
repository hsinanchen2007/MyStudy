### 解题思路
统计每个数出现的次数，最后得到这些出现次数的最大公约数满足条件即可返回true。

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer,Integer> map=new HashMap<>();
        if (deck.length < 2){return false;}
        for (int num : deck) {
            if (map.containsKey(num)) {
                map.put(num, map.get(num) + 1);
            } else {
                map.put(num, 1);
            }
        }
        int maxCount = 0;
        for (Integer key : map.keySet()) {
            if(maxCount < map.get(key)){
                maxCount=map.get(key);
            }
        }
        for (int i = 2; i <= maxCount; i++) {
            boolean flag = true;
            for (Integer key : map.keySet()) {
                if (map.get(key) % i != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.println("X=" + i);
                return true;
            }
        }
        return false;
    }
}
```