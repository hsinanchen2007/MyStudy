### 解题思路
说实话，我这是实在不会做才用的Math库函数，传入的参数n和打印的最大位数有关，而且我们可以发现，10的n次方，都是我们需要打印出来的上界(取不到)。
ps:双100%
### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int size = (int)Math.pow(10,n);
        int[] result = new int[size-1];

        for(int i = 1;i < size;i++)
            result[i-1] = i;

        return result;

    }
}
```