### 解题思路
1.暴力的想法先记录下当前位置，然后找下一个然后找最大的距离即可

### 代码

```java
class Solution {
 public int binaryGap(int N) {
            String binary = Integer.toBinaryString(N);
            System.out.println(binary);
            char[] chars = binary.toCharArray();
            int len = chars.length;
            int ans = 0;
            for (int i = 0; i < len ; i++) {
                if (chars[i] == '1'){
                    for (int j = i+1; j < len; j++) {
                        if (chars[j] == '1'){
                            ans = Math.max(j-i, ans);
                            break;
                        }
                    }
                }
            }
            return ans;
        }
}
```