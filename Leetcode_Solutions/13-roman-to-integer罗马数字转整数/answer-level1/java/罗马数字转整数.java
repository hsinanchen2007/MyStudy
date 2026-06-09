执行用时 : 5 ms , 在所有 Java 提交中击败了 90.54% 的用户
内存消耗 : 36.5 MB , 在所有 Java 提交中击败了 96.30% 的用户

### 解题思路
同样没得别的想法，纯粹是从最高位开始遍历，每当遇到I(1)、X(10)、C(100)的时候，需要判断一下，如果后面接着的是V/X、L/C、D/M的时候，是减去对应的值，其他情况，都是加上就好了。

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            char cN;
            switch(c) {
                case 'I': // 遇到 I 的时候，判断I的下一位，如果是V/X，就-1，其余的，都+1
                    if(i < s.length() - 1) {
                        cN = s.charAt(i+1);
                        if(cN == 'V' || cN == 'X') {
                            sum--;
                        } else {
                            sum++;
                        }
                    } else {
                        sum++;
                    }
                    break;
                case 'V':
                    sum += 5;
                    break;
                case 'X':
                    if(i < s.length() - 1) {
                        cN = s.charAt(i+1);
                        if(cN == 'L' || cN == 'C') {
                            sum -= 10;
                        } else {
                            sum += 10;
                        }
                    } else {
                        sum += 10;
                    }
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'C':
                    if(i < s.length() - 1) {
                        cN = s.charAt(i+1);
                        if(cN == 'D' || cN == 'M') {
                            sum -= 100;
                        } else {
                            sum += 100;
                        }
                    } else {
                        sum += 100;
                    }
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'M':
                    sum += 1000;
                    break;
            }
        }
        return sum;
    }
}
```