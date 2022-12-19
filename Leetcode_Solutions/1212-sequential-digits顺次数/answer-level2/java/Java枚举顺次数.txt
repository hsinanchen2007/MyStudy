### 解题思路
1.枚举low到high范围的所有位数的顺次数
2.筛选在low到high数值范围中的顺次数

### 代码

```java
class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> seqDigits = new ArrayList<>();
        int lowLen = (""+low).length();
        int highLen = (""+high).length();
        int digitCap = lowLen;
        // All digit capacity in range of low and high
        for(int f=digitCap; f <= highLen; f++) {
            // f-digit capacity sequentialDigits
            for(int i=1; i<=10-f; i++) {
                int seqDigit = 0;
                // ten, hundred, thousand...
                for(int j=0; j<f; j++) {
                    seqDigit += Math.pow(10, (f-j-1))*(i+j);
                }
                //correct digit
                if(low<=seqDigit && seqDigit<=high) {
                    seqDigits.add(seqDigit);
                }
            }
        }
        return seqDigits;
    }
}
```