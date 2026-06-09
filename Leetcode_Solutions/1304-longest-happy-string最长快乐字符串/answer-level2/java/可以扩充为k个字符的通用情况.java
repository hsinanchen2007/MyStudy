思路很简单，每次选择字符数最多并且连续的次数小于2（假设为a），选择后，需要将a的连续次数+1,将a的个数-1，剩余的b，c连续次数归0，个数保持不变。
```
public String longestDiverseString(int a, int b, int c) {
        StringBuilder s = new StringBuilder("");
        int[] count = new int[]{a, b, c};
        int[] sequence = new int[]{0, 0, 0};
        while (true) {
            int choice = -1;
            int max = 0;
            // 从备选字母中选一个最大的
            for (int i = 0; i < 3; i++) {
                if (sequence[i] < 2 && count[i] > max) {
                    choice = i;
                    max = count[i];
                }
            }

            // 没有选择，则退出循环
            if (choice == -1) {
                return s.toString();
            }

            // 将字符加入，同时个数-1
            s.append((char) ('a' + choice));
            count[choice] -= 1;

            // 计算连续字符个数，选取的字符数+1，其余字符数归0
            for (int i = 0; i < 3; i++) {
                if (i == choice) {
                    sequence[i]++;
                } else {
                    sequence[i] = 0;
                }
            }

        }
    }

```
