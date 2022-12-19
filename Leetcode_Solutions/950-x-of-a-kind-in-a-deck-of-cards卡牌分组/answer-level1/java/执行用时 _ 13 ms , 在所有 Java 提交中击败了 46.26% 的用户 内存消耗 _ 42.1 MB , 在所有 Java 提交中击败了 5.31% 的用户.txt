### 解题思路
参考了官方题解，利用map集合来求解

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck.length<=1) return false;
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i = 0;i<deck.length;i++) {
                map.put(deck[i],map.getOrDefault(deck[i],0)+1);
        }
        int min = map.get(deck[0]);
        for(int i:map.keySet()) {
            if(min==map.get(i)) {
                continue;
            } else {
                min = gcd(min,map.get(i)); 
            }
        }

        return min>=2;
        
    }

    public int gcd(int x,int y) {
        return x==0?y:gcd(y%x,x);
    }
}
```