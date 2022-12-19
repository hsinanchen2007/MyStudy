### 解题思路
不复杂，直接看代码吧

### 代码

```java
class Solution {
    public int calPoints(String[] ops) {
        int[] score = new int[ops.length]; // 有效的分数（非0）
        int idx = 0; // 有效分数的下标

        for (String op : ops) {
            switch (op) {
                case "C":
                    // 前一个成绩清零
                    score[-- idx] = 0;
                    break;
                case "D":
                    // 前一个成绩X2
                    score[idx] = score[idx - 1] * 2;
                    idx ++;
                    break;
                case "+":
                    // 前2个成绩相加
                    score[idx] = score[idx - 1] + score[idx - 2];
                    idx++;
                    break;
                default:
                    // 都是数字
                    score[idx ++] = Integer.valueOf(op);
            }
        }

        int ans = 0;

        idx --;
        while (idx >= 0) {
            ans += score[idx--];
        }

        return ans;
    }
}


```