### 解题思路

1. 首先假设猜中Bulls为0，全部猜中Cows，
2. 遍历两个字符串，如果位置和数字都一致，Bulls++、Cows--，同时记录字母情况在table上
3. 遍历table，只要table上有正数，就是没有猜中Cows
4. 输出结果

注：因为如果猜中位置和数字，在table上值会抵消，如果没有猜中Cows，对应的位即为负值

### 代码

```java
class Solution {
    public String getHint(String secret, String guess) {
        int a = 0;
        int b = secret.length();
        int[] table = new int[10];
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == guess.charAt(i)) {
                a += 1;
                b -= 1;
            }
            table[secret.charAt(i) - '0']++;
            table[guess.charAt(i) - '0']--;
        }
        for (int j : table) {
            if (j > 0) {
                b-=j;
            }
        }
        return a + "A" + b + "B";
    }
}
```