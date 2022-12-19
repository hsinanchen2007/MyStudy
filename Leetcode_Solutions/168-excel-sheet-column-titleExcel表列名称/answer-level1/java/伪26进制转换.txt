### 解题思路
伪26进制的特殊之处在于每一位上的最小值是1，而不是0.
因此首先需要从最低往最高位逐个保证都至少有1，然后再倒回来从最高位往最低位计算相应的值

### 代码

```java
class Solution {
    // 伪26进制，位数上最小值为1
    public String convertToTitle(int n) {
        int hbit = 0;
        // 确定最高位且确保每一位上都至少有1
        // 从最低位开始，每一位填1，n减去对应值
        long x = 1;
        while(n - x >= 0){
            n -= x;
            hbit++;
            x *= 26;
        }

        // 确定位数后new一个数组保存结果，最开始每一位上都是1
        int[] ans = new int[hbit];
        Arrays.fill(ans, 1);

        //从最高位开始计算
        x = pow(26, hbit - 1);
        for(int i = 0; i < hbit; i++){
            ans[i] += n / x;
            n -= (ans[i] - 1) * x;
            x /= 26;
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < hbit; i++){
            sb.append((char)('A' + ans[i] - 1));
        }

        return sb.toString();
    }

    private long pow(int base, int i){
        long ans = 1;
        while(i-- > 0){
            ans *= base;
        }
        return ans;
    }
}
```