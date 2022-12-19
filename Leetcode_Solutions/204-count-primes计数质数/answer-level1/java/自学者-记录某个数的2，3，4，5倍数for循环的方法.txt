### 解题思路
* 很精妙的布尔数组变量用法，一开始初始化为true，把每个数的倍数赋值为false，剩下的就是个数
* for (int j = 2 * i; j < n; j += i) {}
### 代码

```java
class Solution {
    public int countPrimes(int n) {
       boolean[] isPrim = new boolean[n];
    // 将数组都初始化为 true
    Arrays.fill(isPrim, true);

    for (int i = 2; i < n; i++) {
         // System.out.printf("i:%d\n",i);  
        if (isPrim[i]) {
            // i 的倍数不可能是素数了
            for (int j = 2 * i; j < n; j += i) {
                // System.out.printf("j:%d\n",j);                
                isPrim[j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrim[i]) {
           count++; 
        } 
    }
    return count;  
    }
    
}
```