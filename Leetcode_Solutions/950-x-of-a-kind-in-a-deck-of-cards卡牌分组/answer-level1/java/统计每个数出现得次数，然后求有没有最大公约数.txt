### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int counter[] = new int[10000];//count
        for(int num: deck){
            counter[num] ++;
        }

        //求gcd
        int x = 0;
        for(int cnt: counter){
            if(cnt>0){
                x = gcd(x,cnt);
                if(x == 1){
                    return false;
                }
            }
        }
        return x>=2;


    }

    private int gcd(int a, int b){
        return b == 0? a: gcd(b,a %b);
    }
}
```