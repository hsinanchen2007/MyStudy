```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums == null) return null;
        List<List<Integer>> res = new ArrayList<>();
        if (nums.length < 3) return res;

        int minValue = Integer.MAX_VALUE;
        int maxValue = Integer.MIN_VALUE;
        // negSize：负数的数量
        // posSize：正数的数量
        // zeroSize：0的数量
        int negSize = 0, posSize = 0, zeroSize = 0;
        for (int v : nums) {
            if (v < minValue) {
                minValue = v;
            }
            if (v > maxValue) {
                maxValue = v;
            }
            if (v > 0) {
                posSize++;
            } else if (v < 0) {
                negSize++;
            } else {
                zeroSize++;
            }
        }
        if (zeroSize >= 3) { // 超过3个0
            res.add(Arrays.asList(0, 0, 0));
        }
        // 如果没有负数或没有正数
        if (negSize == 0 || posSize == 0) return res;

        // 排除掉边界不可能凑成0的数（过大或过小的数）
        if ((minValue << 1) + maxValue > 0) { // [-3, -2, 0, 2, 5, 6, 7, 8, 9]
            maxValue = -minValue << 1;
        } else if ((maxValue << 1) + minValue < 0) { // [-9, -8, -7, -6, -5, -2, 0, 2, 3]
            minValue = -maxValue << 1;
        }

        // 存放每个数字v出现的次数，v对应下标为v - minValue
        int[] sizes = new int[maxValue - minValue + 1];
        int[] poses = new int[posSize]; // 存放所有的正数（已去重）
        posSize = 0;
        int[] negs = new int[negSize]; // 存放所有的负数（已去重）
        negSize = 0;
        for (int v : nums) {
            // 排除掉边界不可能凑成0的数（过大或过小的数）
            if (v < minValue || v > maxValue) continue;
            if (sizes[v - minValue]++ != 0) continue;
            if (v > 0) {
                poses[posSize++] = v;
            } else if (v < 0) {
                negs[negSize++] = v;
            }
        }
        // 只排序非0部分
        Arrays.sort(poses, 0, posSize);
        // 只排序非0部分
        Arrays.sort(negs, 0, negSize);

        int posBegin = 0;
        int nv;
        // 遍历负数数组（从绝对值最小的开始遍历）
        for (int ni = negSize - 1; ni >= 0; ni--) {
            nv = negs[ni];
            // 负数绝对值的一半
            int minPv = -nv >> 1;
            // 跳过 < minPv的正数
            // 如果 < minPv的正数可以和nv凑成0，会在遍历到 > minPv的正数时，倒回去找 < minPv的正数
            while (posBegin < posSize && poses[posBegin] < minPv) {
                posBegin++;
            }
            for (int pi = posBegin; pi < posSize; pi++) {
                int pv = poses[pi];
                int remain = -nv - pv; // 0 - nv - pv
                if (remain == nv) { // 还差一个nv，就凑够0
                    if (sizes[nv - minValue] > 1) {
                        res.add(Arrays.asList(nv, nv, pv));
                    }
                } else if (remain == pv) { // 还差一个pv，就凑够0
                    if (sizes[pv - minValue] > 1) {
                        res.add(Arrays.asList(nv, pv, pv));
                    }
                } else if (remain > nv && remain < pv) {
                    if (sizes[remain - minValue] > 0) { // 还差一个remain，就凑够0
                        res.add(Arrays.asList(nv, remain, pv));
                    }
                } else if (remain < nv) break; // 寻找绝对值更大的负数
            }
        }
        return res;
    }
}
```
