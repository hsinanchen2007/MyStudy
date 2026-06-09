```Java []
class Solution {
    public int reverseBits(int num) {
        int[] binary = new int[32];
        int index = 31;
        while (num != 0) {
            binary[index--] = num % 2;
            num /= 2;
        }
        
        int ans = 0, sum = 0, pre = -1;
        for (int i = 0; i < binary.length; i++) {
            if (binary[i] == 1) sum++;
            else {
                sum = i - pre;
                pre = i;
            }
            ans = Math.max(ans, sum);
        }
        return ans;
    }
}
```
```Python3 []
class Solution:
    def reverseBits(self, num: int) -> int:
        chars = bin(num)[2:]
        chars = '0'*(32 - len(chars)) + chars
        ans, sums, pre = 0, 0, -1
        for i, v in enumerate(chars):
            if  v == '1':
                sums += 1
            else:
                sums = i - pre
                pre = i
            ans = max(ans, sums)
        return ans
```

