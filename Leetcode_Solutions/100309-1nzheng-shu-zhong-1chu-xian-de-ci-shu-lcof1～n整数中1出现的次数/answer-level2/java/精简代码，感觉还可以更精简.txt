思想仍然是 个 十 百 千 位计数。
总感觉计算公式还可以更精简一些，希望有大神给点建议
```
class Solution {
    public int countDigitOne(int n) {
        // 假设 n == 1234
        // 个位：1234 / 10 * 1 + min(4 + 1, 2) - 1
        // 十位：1234 / 100 * 10 + min(34 + 1, 20) - 10
        // 百位：1234 / 1000 * 100 + min(234 + 1, 200) - 100
        // 千位：1234 / 10000 * 1000 + min(1234 + 1, 2000) - 1000
        // 因 1234 / 10000 == 0，故 break
        // 加了 max 防止计数变负数
        
        long dig = 10; // 每一轮的除数
        long comp = 2; // 每一轮 min 中的比较数
        int cnt = 0; // 计数
        
        while(true){
            cnt += n / dig * (dig / 10) + Math.max(Math.min(n % dig + 1, comp) - dig / 10, 0);
            if(n / dig == 0) break;
            dig *= 10;
            comp *= 10;
        }
        return cnt;
    }
}
```
