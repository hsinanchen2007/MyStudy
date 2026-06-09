### 解题思路
遍历一遍

### 代码

```java
class Solution {

    public int[] divingBoard(int shorter, int longer, int k) {
        if (k == 0) {
            return new int[0];
        }
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> list = new ArrayList<>();
        for (int i=k; i>=0; i--) {
            int temp = shorter * i + longer * (k-i);
            if (!map.containsKey(temp)) {
                map.put(temp, 1);
                list.add(temp);
            }
        }
        int[] re = new int[list.size()];
        for (int i=0; i<list.size(); i++) {
            re[i] = list.get(i);
        }
        return re;
    }
}
```