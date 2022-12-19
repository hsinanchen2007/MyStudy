### 解题思路
就是一定要有2569中的一个，且347不能有，最简单的方法就是转成字符串，但这样内存和运行时间都~~

### 代码

```java
class Solution {
    public int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            String j = String.valueOf(i);
            if(j.contains("3")||j.contains("4")||j.contains("7"))
                continue;
            if(j.contains("2")||j.contains("5")||j.contains("6")||j.contains("9"))
                count++;
        }
        return count;
    }
}
```