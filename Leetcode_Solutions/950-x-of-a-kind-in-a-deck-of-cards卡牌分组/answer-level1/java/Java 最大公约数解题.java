### 解题思路

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck.length < 2) return false;
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int num : deck){
            int i = map.getOrDefault(num,0);
            map.put(num,i+1);
        }
        Set<Integer> set = map.keySet();
        int g = 0;
        for(int num : set){
            if(g == 0) g = map.get(num);
            g = gcd(map.get(num),g);
        }
        if(g < 2) return false;
        return true;
    }
    public int gcd(int a,int b){
        return a == 0 ? b : gcd(b % a,a);
    }
}
```