### 解题思路
统计每个数字的个数，求最大公约数，如果最大公约数大于等于2，则可以分组。（辗转相除法求最大公约数的细节不记得了，从百度抄的）

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int i = 0; i < deck.length; i++) {
            if(countMap.containsKey(deck[i])){
                countMap.put(deck[i], countMap.get(deck[i])+1);
            } else {
                countMap.put(deck[i], 1);
            }
        }
        int maxGongYueShu = 0;
        for (Integer count : countMap.values()) {
            if(maxGongYueShu == 0){
                maxGongYueShu = count;
                continue;
            }
            maxGongYueShu = gongyueshu(maxGongYueShu, count);
        }
        if(maxGongYueShu < 2){
            return false;
        }
        return true;
    }

    int gongyueshu(int m,int n){
        int rem;
        while(n > 0){
            rem = m % n;
            m = n;
            n = rem;
        }
        return m;
    }
}
```