史上最菜java 2ms

```
class Solution {
    public int findComplement(int num) {
        String res = Integer.toBinaryString(num);
        StringBuilder builder = new StringBuilder();
        builder.append("0");

        for (int i=1; i<res.length();i++) {
            if (res.charAt(i) == '0') {
                builder.append("1");
            }else {
                builder.append("0");
            }
        }
        return Integer.valueOf(builder.toString(),2);
    }
}
```