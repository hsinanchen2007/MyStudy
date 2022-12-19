### 解题思路
从“1”开始逐个计算至第n项。
想要求出下一项只需遍历一次当前项

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        String answer = "1";

        // 从第一项计算至第n项
        for (int i = 1; i < n; i++) {
            StringBuilder stringBuilder = new StringBuilder();
            char hold = answer.charAt(0);
            int count = 0;
            // 遍历当前项求出下一项
            for (int j = 0; j < answer.length(); j++) {
                if (answer.charAt(j) == hold) {
                    count++;
                } else {
                    stringBuilder.append(count).append(hold);
                    hold = answer.charAt(j);
                    count = 1;
                }
            }
            stringBuilder.append(count).append(hold);
            answer = stringBuilder.toString();
        }

        return answer;
    }
}
```