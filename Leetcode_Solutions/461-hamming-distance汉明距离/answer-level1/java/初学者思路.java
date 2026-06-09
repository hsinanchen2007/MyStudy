### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     public int hammingDistance(int x, int y) {
        StringBuffer stringBufferX = new StringBuffer();
        StringBuffer stringBufferY = new StringBuffer();

        while (x > 0) {
            stringBufferX.append(x % 2);
            x = x / 2;
        }

        while (y > 0) {
            stringBufferY.append(y % 2);
            y = y / 2;
        }
        System.out.println(stringBufferX.toString());
        System.out.println(stringBufferY.toString());
        StringBuffer reverseX = stringBufferX.reverse();
        StringBuffer reverseY = stringBufferY.reverse();

        if (reverseX.length() > reverseY.length()) {
            int delt = reverseX.length() - reverseY.length();
            while (delt > 0) {
                reverseY.insert(0, "0");
                delt--;
            }
        } else if (reverseX.length() < reverseY.length()) {
            int delt = reverseY.length() - reverseX.length();
            while (delt > 0) {
                reverseX.insert(0, "0");
                delt--;
            }
        }

        int count = 0;
        for (int i = 0; i < reverseX.length(); i++) {
            if (reverseX.charAt(i) != reverseY.charAt(i)) {
                count++;
            }
        }
        return count;
    }
}
```