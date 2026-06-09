### 解题思路
观察排序 可以知道如下规律
前面(n-1)!的答案都是1开头的
前面(n-2)!是2作为第二位的 其中n>2的时候
那么我们只需将k不断的取余即可
    从 k % (n - 1) 开始 取第k % (n - 1)数
为了避免取到相同的数字  构建一个1-n的数组  每取一个数字就将其置为0
这样是为了保证取到最小的第k % (n - 1)数

还可以优化的地方在于 计算multi的时候  将每一步结果存到数组里
### 代码

```java
class Solution {
    public String getPermutation(int n, int k) {
        // 前面(n-1)!的答案都是1开头的
        // 前面(n-2)!是2作为第二位的 其中n>2的时候
        // k % (n - 1) 就是不断取余(count)的过程
        int multi = 1;
        int[] tmp = new int[n];
        for (int i = 0; i < n; i++) tmp[i] = i + 1;
        for (int i = 2; i < n; i++) multi *= i;
        StringBuilder sb = new StringBuilder();
        for (int i = n; i > 0; i--) {
            // k - 1的原因是第k个元素的下标k -1
            int count = (k - 1) / multi;
            // 减去对应的已排序的格式 剩下表示当前位数的第n位
            k -= (count * multi);
            if (i > 1) multi /= (i - 1);
            int num = -1;
            for (int j = 0; j < n; j++) {
                if (tmp[j] == 0) continue;
                num++;
                if (num == count) {count = tmp[j]; tmp[j] = 0; break;}
            }
            // 每次取最小的第count个数
            sb.append(count);
        }
        return sb.toString();
    }
}
```