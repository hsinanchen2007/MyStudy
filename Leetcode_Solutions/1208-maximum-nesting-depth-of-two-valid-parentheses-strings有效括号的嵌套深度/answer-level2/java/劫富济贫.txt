### 解题思路

谁少就给谁，谁多就抢谁

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int [] ret = new int[seq.length()];
        ret[0] = 0;
        int countA = 1;
        int countB = 0;
        for (int i = 1 ; i < seq.length(); i++) {
            if (seq.charAt(i) == '(') {
                if (countB < countA) {
                    ret[i] = 1;
                    countB++;
                } else {
                    ret[i] = 0;
                    countA++;
                }
            } else {
                if (countA > countB) {
                    countA--;
                    ret[i] = 0;
                } else {
                    countB--;
                    ret[i] = 1;
                }
            }
        }
        return ret;
    }
}
```