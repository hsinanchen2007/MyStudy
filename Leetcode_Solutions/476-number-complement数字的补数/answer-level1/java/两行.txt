num二进制共有(Math.log10(num)/Math.log10(2) + 1)位，这些位上全部放1，变为((int)(Math.pow(2,bin) - 1))，同num异或即可。
```
class Solution {
    public int findComplement(int num) {
        int bin = (int) (Math.log10(num)/Math.log10(2) + 1);
        return num^((int)(Math.pow(2,bin) - 1));
    }
}
```
