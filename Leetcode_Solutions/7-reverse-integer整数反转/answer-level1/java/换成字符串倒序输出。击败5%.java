### 解题思路
我的第二道题

### 代码

```java
class Solution {
    public int reverse(int x) {
        boolean nega = false;
        if (x < 0) {
            nega = true;
            x *= -1;
        }
        String s = "" + x;
        char[] arr = s.toCharArray();
        StringBuilder sb = new StringBuilder();
        for(int i = arr.length - 1; i >= 0; i--) {
            sb.append(arr[i]);
        }
        try {
            int result = Integer.parseInt(new String(sb));
            if (nega) {
                result *= -1;
            }
            return result;
        } catch (NumberFormatException e){
            return 0;
        }
    }
}
```