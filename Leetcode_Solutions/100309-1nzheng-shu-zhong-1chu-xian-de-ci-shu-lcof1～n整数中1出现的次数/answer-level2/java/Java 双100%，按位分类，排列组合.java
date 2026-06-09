按位遍历n，将第k位固定为1，计算此时高位（k位左侧）和低位（k位右侧）的排列组合，并将所有位的排列组合相加

```
class Solution {
    public int countDigitOne(int n) {
        // 计算n有几位
        int bits = 0; int temp = n;
        while(temp > 0){
            temp /= 10;
            bits++;
        }
        
        // 遍历位，当k位为1，计算高位和低位共有多少种排列组合，计入总数sum
        int sum = 0;
        for(int k = 1; k <= bits; k++){
            int high = n / (int)Math.pow(10, k);
            int low = n - n / (int)Math.pow(10, k - 1) * (int)Math.pow(10, k - 1);
            int cur = (n - high * (int)Math.pow(10, k) - low) / (int)Math.pow(10, k - 1);

            // 根据第k位的值分类，计算公式见代码，还算清晰吧
            if(cur == 0)    sum += (high + 1 - 1) * (int)Math.pow(10, k - 1);
            else if(cur == 1)   sum += 1 * (low + 1) + (high + 1 - 1) * (int)Math.pow(10, k - 1);
            else if(cur > 1)    sum += (high + 1) * (int)Math.pow(10, k - 1);
        }

        return sum;
    }
}
```
