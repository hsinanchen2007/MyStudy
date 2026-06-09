### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static boolean hasGroupsSizeX(int[] deck) {
        if (deck == null || deck.length == 1) {
            return false;
        }
        Map<Integer,Integer> hashArray = new HashMap<>();
        for (int i = 0; i < deck.length; i++) {
            if (hashArray.containsKey(deck[i])) {
                hashArray.put(deck[i],hashArray.get(deck[i]) + 1);
            }else{
                hashArray.put(deck[i], 1);
            }
        }
        boolean res = isOkgroup(hashArray,hashArray.get(deck[0]));
        return res;
    }

    public static boolean isOkgroup(Map<Integer,Integer> map,int K) {
        Map<Integer,Integer> res = new HashMap<>();
        int gcd = K;
        for (Map.Entry<Integer,Integer> mapTmp: map.entrySet()) {
            gcd = getGcd(gcd,mapTmp.getValue());
            if (gcd < 2) {
                return false;
            }
        }
        return true;
    }
    //最大公约数牛逼的解法，更是关键点
    public static int getGcd(int a, int b) {
        return a % b == 0 ? b : getGcd(b, a % b);
    }
}
```