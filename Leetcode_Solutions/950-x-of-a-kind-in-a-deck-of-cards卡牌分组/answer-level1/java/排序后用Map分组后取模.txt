### 解题思路
1.先把数组排序
2.使用Map计算每个数字的出现次数
3.获取到下标为0的数据出现次数times，fori循环times
4.对Map中的value对i取模,不满足结束本次循环，times减一；
5.如果最终times大于1，则存在这样的分组
### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
     if (deck.length < 2) {
            return false;
        }
        Arrays.sort(deck);
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : deck) {
            if (map.containsKey(i)) {
                map.put(i, map.get(i) + 1);
            } else {
                map.put(i, 1);
            }
        }
        int times = map.get(deck[0]);
        for (int i = times; i > 1; i--) {
            boolean flag = true;
            for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
                Integer v = entry.getValue();
                if (v % times != 0) {
                    flag = false;
                    break;
                }
            }
            if(!flag){
                times--;
            }
        }
        return times > 1;
            }
}
```