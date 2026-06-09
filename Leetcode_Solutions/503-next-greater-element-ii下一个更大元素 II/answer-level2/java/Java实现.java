不才，才4ms：

```java []
class Solution {
        public int[] nextGreaterElements(int[] nums) {
            if (nums == null) {
                return null;
            }

            final int LEN = nums.length;
            if (LEN == 0) {
                return nums;
            }

            int[] ret = new int[LEN];
            Arrays.fill(ret, -2);

            for (int i = LEN - 1; i >= 0; --i) {
                int d = nums[i];
                for (int j = 1; j < LEN; ) {
                    int index = (i + j) % LEN;
                    if (d < nums[index]) {
                        ret[i] = index;
                        break;
                    } else {
                        int e = ret[index];
                        if (e == -2) {
                            j++;
                        } else if (e == -1) {
                            ret[i] = -1;
                            break;
                        } else {
                            j = (e > i) ? (e - i) : (e + LEN - i);
                        }
                    }
                }

                if (ret[i] == -2) {
                    ret[i] = -1;
                }
            }

            for (int i = 0; i < LEN; ++i) {
                int d = ret[i];
                if (d != -1) {
                    ret[i] = nums[d];
                }
            }

            return ret;
        }
    }
```
