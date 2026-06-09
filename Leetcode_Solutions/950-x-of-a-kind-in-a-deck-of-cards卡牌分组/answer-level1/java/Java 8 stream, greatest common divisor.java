### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        //边界
        if(deck.length < 2) {
            return false;
        }

        //初始化
        Map<Integer, Integer> map = new HashMap();

        //主逻辑
        for(int i:deck) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        
        int x = map.values().stream().reduce((a,b)->gcd(a,b)).get();
        return x >= 2;
    }

    private int gcd(int a, int b) {
        return a%b == 0 ? b:gcd(b, a%b);
    }
}
```