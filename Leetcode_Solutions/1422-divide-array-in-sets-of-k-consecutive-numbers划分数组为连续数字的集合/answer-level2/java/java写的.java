### 解题思路
用hashmap存储,每k个一组说明每组开头的数的值一定比后面的数小,最后判断map里的值是否都为空

### 代码

```java
class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
      Map<Integer, Integer> map = new HashMap();
        for (int i : nums) {
            if (map.containsKey(i)) {
                map.put(i, map.get(i) + 1);
            } else {
                map.put(i, 1);
            }
        }
        List<Integer> list = new ArrayList(map.keySet());
        Collections.sort(list);
        // System.out.println(list.toString());
        for (int i = 0; i <= list.size() - k; i++) {
            if (map.get(list.get(i)) == 0) {
                continue;
            }
            int cur = map.get(list.get(i));
            map.put(list.get(i), 0);
            int currentIndex = list.get(i);
            for (int j = 1; j < k; j++) {
                if (map.get(list.get(i + j)) < cur || list.get(j + i) - currentIndex != 1) {
                    // System.out.println(map.get(list.get(i+j))+" "+(i+j)+" ");
                    return false;
                } else {
                    map.put(list.get(i + j), map.get(list.get(i + j)) - cur);
                }
                currentIndex = list.get(j + i);
            }
        }
        for(int i:map.values()){
            if(i!=0){
                return false;
            }
        }
        return true;

    }
}
```