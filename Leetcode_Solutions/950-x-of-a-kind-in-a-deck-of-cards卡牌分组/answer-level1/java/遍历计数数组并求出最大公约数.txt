### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
  int len = deck.length;
        if (len < 2) {
            return false;
        }

        // 计数数组，10000 是根据题目给出的数值范围定的
        int[] cnt = new int[10000];
        for (int num : deck) {
            cnt[num]++;
        }

        // 先得到第 1 个数的个数，以避免在循环中赋值
        int x = cnt[deck[0]];

        for (int i = 0; i < 10000; i++) {
            if (cnt[i] == 1) {
                return false;
            }

            if (cnt[i] > 1) {
                x = gcd(x, cnt[i]);

                // 这里做判断可以提前终止运行，也可以等到最后再做，各有优劣，任选其一
                if (x == 1) {
                    return false;
                }
       }
        }
        return true;
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        // int[] deck = new int[]{1, 2, 3, 4, 4, 3, 2, 1};
        // int[] deck = new int[]{1, 1, 1, 2, 2, 2, 3, 3};
        // int[] deck = new int[]{1};
        // int[] deck = new int[]{1, 1};
        int[] deck = new int[]{0, 0, 1, 1, 1, 1, 2, 2, 3, 4};
        // boolean res = solution.hasGroupsSizeX(deck);
        // System.out.println(res);
        System.out.println(solution.gcd(2, 8));

    }
}
```