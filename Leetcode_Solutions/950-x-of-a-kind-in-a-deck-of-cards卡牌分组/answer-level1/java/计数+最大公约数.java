### 解题思路
计数，求最大公约数，最后return 最大公约数大于1

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck.length < 1)return false;
        Map<Integer, Integer> map = new HashMap<>();
        for(int card : deck){
            if(map.containsKey(card)){
                map.put(card, map.get(card)+1);
            }else {
                map.put(card, 1);
            }
        }
        int last = 0;
        for(int v : map.values()){
            if(last == 0){
                last = v;
            }else {
                if(v != last ) {
                	last = gcd(v, last);
                }
            }
            if(last == 1)return false;
        }
        return last > 1;

    }
	
	public int gcd(int a, int b) {
		if(a < b) {
			int t = a;
			a = b;
			b = t;
		}
		int t = a % b;
		if(t == 0 || t == b)return b;
		return gcd(b, t);
	}
}
```