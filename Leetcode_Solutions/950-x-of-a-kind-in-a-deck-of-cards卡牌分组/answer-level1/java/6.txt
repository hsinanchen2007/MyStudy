### 解题思路
求所有数出现次数的公约数

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int L=deck.length;
        int fac[]=new int[10000];
        for(int i=0;i<L;i++){
            fac[deck[i]]++;
        }
        int g=-1;
        for(int j=0;j<10000;j++){
            if(g==-1)
            g=fac[j];
            else
            g=gcd(g,fac[j]);
        }
   return g>=2;
    
}
static int gcd(int a,int b){
            return b==0?a:gcd(b,a%b);
        }
}
```