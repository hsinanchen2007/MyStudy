### 解题思路
统计每个数出现的次数，求出这数列中最大公因数，根据题意，若能被分组，每个数都应该是X的倍数，则两两数之间的最大公因数不能为1;

### 代码

```java
class Solution {
       public boolean hasGroupsSizeX(int[] deck) {
        HashMap<Integer, Integer> map = new HashMap();
        int deckLength = deck.length;
        if(deckLength == 1) return false;
        for (int i = 0; i < deckLength; i++) {
            if(map.containsKey(deck[i])) {
                map.put(deck[i], map.get(deck[i])+1);
            } else {
                map.put(deck[i], 1);
            }
        }
        int length = map.size();
        if(length == 1) return true;
        int[] ints = new int[length];
        int i = 0;
        for (Map.Entry<Integer, Integer> elem : map.entrySet()) {
            int value = elem.getValue();
            if(value == 1) return false;
            ints[i] = value;
            i++;
        }
        if(length == 2 && gcd(ints[0], ints[1]) == 1) return false;
        for (int j = 2; j < length; j++) {
            if(gcd(ints[j],gcd(ints[j-1],ints[j-2])) == 1) {
                return false;
            }
        }
        return true;
    }

    public int gcd(int a, int b){
        return b == 0 ? a:gcd(b, a%b);
    }
}
```