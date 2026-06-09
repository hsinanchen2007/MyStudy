### 解题思路
如果仅仅是1和2构建的字符串 理想状态下`f(n) = f(n - 1) + f(n - 2), 其中f(1) = 1, f(2) = 2`
但当出现0和大于27的情况 我们需要进行额外处理 相当于遇到一个节点  节点前和节点后的可能性相乘就是到结果
1. 出现0相当于和前一个字符串绑定了  且必须是1或2  此时相当于减去了2个字符 
    所以是发现下一个字符是0的时候, 我们就需要进行计算当前的可能性
2. 当出现大于27的情况 我们也需要当前的可能性 然后乘上之前的结果


### 代码

```java
class Solution {
    public int numDecodings(String s) {
        int ans = 1;
        int len = s.length();
        // 当可以组成两个字符的时候  那么共有 1 2 3 5 8...种解码方法
        int[] arr = new int[len + 1];
        arr[0] = 1; arr[1] = 1;
        for (int i = 2; i <= len; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        int index = 0;
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == '0') return 0;
            if (i < len - 1 && s.charAt(i + 1) == '0') {
                if (s.charAt(i) > '2') return 0;
                // 需要锁定当前值 这两个必须是在一起的 相当于减少2个
                i++;
                ans *= arr[index];
                index = 0;
                continue;
            }
            // 更新当前的可能性
            index++;
            if (s.charAt(i) > '2' || (i < len - 1 && s.charAt(i) > '1' && s.charAt(i + 1) > '6')) {
                ans *= arr[index];
                index = 0;
            }
        }
        return ans * arr[index];
    }
}
```