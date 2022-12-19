```
class Solution {
    private int[] tempAtMostNGivenDigitSet;
    private int[] tempAtMostNGivenDigitSetDp;
 public int lowerBoundFirst(int[] nums, int target) {
        int low = 0;
        int high = nums.length;
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    public int atMostNGivenDigitSet(String[] D, int N) {
        tempAtMostNGivenDigitSet = new int[15];
        tempAtMostNGivenDigitSetDp = new int[15];
        int pos = 0;

        while (N != 0) {
            tempAtMostNGivenDigitSet[pos++] = N % 10;
            N /= 10;
        }
        int[] DD  = new int[D.length];
        for (int i = 0; i < D.length; i++) {
            DD[i] = D[i].charAt(0) - '0';
        }
        Arrays.fill(tempAtMostNGivenDigitSetDp, -1);
        return dfs(pos - 1, true, DD, true);
    }

    private int dfs(int pos, boolean limit, int[] D, boolean lead) {
        if (pos == -1 ) return lead ? 0 : 1;
        if (!lead && !limit && tempAtMostNGivenDigitSetDp[pos] != -1) {
            return tempAtMostNGivenDigitSetDp[pos];
        }
        int up;
        if (limit) {
            int index = lowerBoundFirst(D, tempAtMostNGivenDigitSet[pos]);

            if (index == D.length) {
                up = D.length - 1;
            } else if (D[index] == tempAtMostNGivenDigitSet[pos]) {
                up = index;
            } else {
                if (index == 0) {
                    up = -1;

                } else {
                    up = index - 1;
                }
            }

        } else {
            up = D.length - 1;
        }
        int tmp = 0;
        for (int i = 0; i <= up; i++) {
            tmp += dfs(pos - 1, limit && tempAtMostNGivenDigitSet[pos] == D[i], D, false);
        }
        if (lead) {
            tmp += dfs(pos - 1, false, D, true);
        }
        if (!limit && !lead) tempAtMostNGivenDigitSetDp[pos] = tmp;
        return tmp;
    }
}
```
