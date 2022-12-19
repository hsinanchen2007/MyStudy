### 解题思路
直接暴力

### 代码

```java
class Solution {
        public int countLargestGroup(int n) {
        int[] ans = new int[37];
        while (n > 0) {
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0;
            int e = 0;
            int sum = 0;
            a = n % 10;
            b = (n / 10) % 10;
            c = (n / 100) % 10;
            d = (n / 1000);
            e = n / 10000;
            sum = a + b + c + d + e;
            ans[sum]++;
            n--;
        }
        int max = 0;
        for (int i = 0; i < ans.length; i++) {
            if (ans[i] > max)
                max = ans[i];
        }
        int num = 0;
        for (int i = 0; i < ans.length; i++) {
            if (ans[i] == max)
                num++;
        }
        return num;
    }
}
```