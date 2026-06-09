其实自己第一手，也是用的dfs + 记忆数组的方式来做的，也是通过的，不过看题目的意思，用dp问题，
也就是提示里面的 `dp[i] = 1 + max(dp[j])  i - d <= j <= i + d`, 约束条件
不过要注意需要从最低的柱子往高的柱子，来填充dp数组

```java
class Solution {
    public  int maxJumps(int[] arr, int d) {
        int[] dp = new int[arr.length];
        List<Pair> pairs = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            dp[i] = 1;
            pairs.add(new Pair(i, arr[i]));
        }
        int max = 0;
        pairs.sort((p1, p2) -> {
            if (p1.value == p2.value) {
                return 0;
            }
            if (p1.value > p2.value) {
                return 1;
            } else {
                return -1;
            }
        });
        for (Pair pair : pairs) {
            int i = pair.index;
            boolean left = true;
            int maxLeft = 0;
            for (int j = i - 1; j >= i - d && j >= 0; j--) {
                if (arr[j] >= arr[i]) {
                    break;
                }
                maxLeft = Math.max(maxLeft, dp[j]);
            }
            int maxRight = 0;
            for (int j = i + 1; j <= i + d && j < arr.length; j++) {
                if (arr[j] >= arr[i]) {
                    break;
                }
                maxLeft = Math.max(maxLeft, dp[j]);
            }
            dp[i] = 1 + Math.max(maxLeft, maxRight);
            max = Math.max(max, dp[i]);
        }
        return max;
    }
    class Pair {
        int index;
        int value;

        public Pair(int index, int value) {
            this.index = index;
            this.value = value;
        }

        public int getIndex() {
            return index;
        }

        public void setIndex(int index) {
            this.index = index;
        }

        public int getValue() {
            return value;
        }

        public void setValue(int value) {
            this.value = value;
        }
    }
}
```