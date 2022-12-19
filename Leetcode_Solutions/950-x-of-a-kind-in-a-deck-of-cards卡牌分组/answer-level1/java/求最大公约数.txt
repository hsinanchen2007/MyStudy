### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck.length < 2) return false;
        int[] count = new int[10000];
        for(int i=0;i< deck.length;i++){
            count[deck[i]]++;
        }

        int  g = -1;
        for(int c : count){
            if(c == 0) continue;
            g=g>0? gcd(g,c):c;
            if(g == 1) break;
        }   
        return g>1;
    }
    public int gcd(int x,int y){
        if(y == 0){
            return x;
        }
         return gcd(y,x%y);
    }
}
```