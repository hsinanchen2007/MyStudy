```
class Solution {
    public int findComplement(int num) {
        String s = Integer.toBinaryString(num);
        return (1 << s.length()) - 1 - num;        
    }
}
```
