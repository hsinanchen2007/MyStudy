java 最搓实现

```
class Solution {
    public int maximum69Number (int num) {
        String numStr = String.valueOf(num);
        String newStr = "";
        for (int i=0; i<numStr.length(); i++) {
            if (numStr.charAt(i) == '6') {
                newStr = numStr.substring(0, i) + '9' + numStr.substring(i+1);
                return Integer.valueOf(newStr);
            }
        }
        return num;
    }
}
```