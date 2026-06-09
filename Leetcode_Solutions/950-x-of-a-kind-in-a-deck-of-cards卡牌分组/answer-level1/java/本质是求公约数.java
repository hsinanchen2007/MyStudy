### 解题思路
> 出了两次错，然后想明白了，一会看看大家的解法，是不是我搞复杂了。。。
1. 算出每张牌的数量
2. 拿出最小数量的进行分解质因数
3. 求公约数是否存在

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < deck.length; i++) {
            Integer n = map.get(deck[i]);
            n = n == null ? 1 : n + 1;
            map.put(deck[i], n);
        }
        int min = Integer.MAX_VALUE;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            min = Math.min(min,entry.getValue());
        }
        // 分解质因数 min
        Set<Integer> prime = new HashSet<>();
        for (int i = min; i > 1; i--) {
            if (min % i == 0){
                prime.add(i);
            }
        }
        // 求公约数
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            Iterator<Integer> iterator = prime.iterator();
            boolean flag = false;
            while (iterator.hasNext()){
                Integer next = iterator.next();
                if (entry.getValue() % next == 0){
                    flag = true;
                }else {
                    iterator.remove();
                }
            }
            if (!flag){
                return false;
            }
        }
        return true;
    }
}
```