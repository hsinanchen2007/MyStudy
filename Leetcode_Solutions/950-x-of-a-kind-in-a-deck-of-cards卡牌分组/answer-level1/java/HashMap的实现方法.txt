### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        HashMap<Integer, Integer> HashMap = new HashMap<>();

        for (int i1 : deck) {
            if (!HashMap.containsKey(i1)) {
                int value=1;
                HashMap.put(i1,value);
            }else HashMap.put(i1,HashMap.get(i1)+1);
        }
        int flag=HashMap.get(deck[0]);
        for(int i2 :deck)flag=gcd(flag,HashMap.get(i2));
        if (flag==1)return false;
        return  flag>=2;
    }
    public int gcd(int x, int y) {
        return x == 0 ? y : gcd(y%x, x);
    }
}
```