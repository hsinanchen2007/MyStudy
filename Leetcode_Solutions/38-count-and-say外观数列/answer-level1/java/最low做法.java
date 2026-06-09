### 解题思路
n = 1 时，直接返回1
for循环，定义i从2一直到达n，在n时拼出的字符串即为结果
循环里面对上一次的结果s进行遍历计数统计和拼装
逻辑有点绕，但是思路理通了难点也还好

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String s = "1";
        if (n == 1) {
            return s;
        }
        for (int i = 2; i <= n; i++) {
            String result = "";
            int t = 0;
            Character number = null;
            for (int j = 0; j < s.length(); j++) {
                if (number == null) {
                    number = s.charAt(j);
                    t++;
                } else {
                    if (s.charAt(j) == number) {
                        t++;
                    } else {
                        result = result + t + String.valueOf(number);
                        number = s.charAt(j);
                        t = 1;
                    }
                }
            }
            s = result + t + String.valueOf(number);
        }
        return s;
    }
}
```