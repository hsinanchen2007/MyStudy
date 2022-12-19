### 解题思路
此处撰写解题思路
先记录下每个数字有多少个，然后找出这些个数个数大于0的数字个数的公因数，公因数大于1则可以分组，不然不能分组。
### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int[] poke = new int[10000];
        for(int i : deck)
            poke[i]++;
        int tag = -1;
        for(int i = 0; i < 10000; i++){
            if(poke[i] > 0){
                if(tag == -1)
                    tag = poke[i];
                else{
                    tag = gcd(tag,poke[i]);
                }
            }
        }
        return tag >= 2;
    }

    private int gcd(int a, int b){
        return a == 0 ? b : gcd(b % a, a);
    }
}
```