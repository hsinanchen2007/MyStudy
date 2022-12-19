### 解题思路
依次扫描字符串，并用两个计数器记录A和L的数量，其中对于L计数器，因为需要是连续计数，所以如果碰到A和P，则需要重置L计数器。
当A计数器 > 1 时，直接返回false。当L计数器 > 2 时，直接返回false。
都扫描结束，则返回true。

### 代码

```java
class Solution {
    public boolean checkRecord(String s) {
        int countA = 0;
        int countL = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'P') {
                countL = 0;
            } else {
                if (c == 'A') {
                    countA++;
                    if (countA > 1) {
                        return false;
                    };
                    countL = 0;
                } else if (c == 'L'){
                    countL++;
                    if (countL > 2) {
                        return false;
                    };
                };
            };
        };
        return true;
    }
}
```