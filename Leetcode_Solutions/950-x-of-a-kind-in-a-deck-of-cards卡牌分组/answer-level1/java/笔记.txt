### 解题思路

首先将每种卡牌的数量，统计出来，
然后看每种卡牌的数量，之间是否存在公约数。


### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck.length==0) return false;
        if(deck.length==1) return false;

        int [] count=new int [10000];

        for (int i:deck){
            count[i]++;
        }
        int gcd=count[deck[0]];
        for (int i:count){
           if(i>0){
              gcd=gcd(gcd,i); //最大公约数
              if(gcd<2){
                  return false;
              }
           }
        }


        return true;
    }
 
    int gcd(int a,int b){
        return a%b==0?b:gcd(b,a%b);
    }
}
```