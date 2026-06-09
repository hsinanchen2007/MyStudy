### 解题思路
最大公约数法求解
注意：每组牌面相同且都有X张牌，那么相同数字的牌可以为X、2X、...

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int[] count = new int[1000];
        for(int i: deck){
            count[i]++;
        }

        int r = -1;
        for(int i=0; i<1000; i++){
            if(count[i]>0){
                if(r==-1)
                    r = count[i];
                else
                    r = gcd(r,count[i]);                
            }
        }
        return r>=2;
    }

    public int gcd(int x, int y){
        return x==0 ? y: gcd(y%x, x);
    }
}
```