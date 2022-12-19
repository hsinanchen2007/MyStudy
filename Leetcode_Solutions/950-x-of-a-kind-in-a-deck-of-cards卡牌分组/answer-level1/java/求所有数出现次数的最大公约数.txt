### 解题思路
求所有数出现次数的最大公约数

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        // 求每个数字出现的次数，根据题目，最大数不超过10000
        int[] counter = new int[10000];
        for (int num: deck) {
            counter[num]++;
        }

        // 迭代求多个数的最大公约数
        int x = 0;
        for(int cnt: counter) {
            if (cnt > 0) {
                x = gcd(x, cnt); 
                //如果两个数最大公约数是1，则直接退出
                if (x == 1) { 
                    return false;
                }
            }
        }
        return x >= 2;
    }
    
    // 辗转相除法
    private int gcd (int a, int b) {
        return b == 0? a: gcd(b, a % b);
    }
}
```