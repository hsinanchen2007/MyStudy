### 思路
首先，$1 \leq n \leq 10^9，n$比较大，因此肯定不能暴力枚举每一行。那怎么办呢？又看到提示中的$1 \leq reservedSeats.length \leq min(10*n, 10^4)$ 这个条件，即已经被预约的作为最多就是$10^4$。那么，我们可以倒着思考，假设都没被预约，答案就是$2*n$（可以从图中很明显看出来，每行最多做两队4人家庭）。然后用$2*n$ - **被预约座位破坏的家庭数** 就是答案。

```java
 private boolean isOk(int l, int r, Set<Integer> colSet) {
        for (int i = l; i <= r; i++) {
            if (colSet.contains(i)) {
                return false;
            }
        }
        return true;
    }

    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int[] seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (!map.containsKey(row)) {
                map.put(row, new HashSet<>());
            }
            map.get(row).add(col);
        }

        int ans = 2 * n;
        for (Integer row : map.keySet()) {
            Set<Integer> colSet = map.get(row);
            int count = 0;
            if (isOk(2, 5, colSet)) {
                count++;
                if (isOk(6, 9, colSet)) {
                    count++;
                }
            } else {
                if (isOk(4, 7, colSet)) {
                    count++;
                } else {
                    if (isOk(6, 9, colSet)) {
                        count++;
                    }
                }
            }

            int diff = 2 - count;
            ans -= diff;
        }

        return ans;
    }
```