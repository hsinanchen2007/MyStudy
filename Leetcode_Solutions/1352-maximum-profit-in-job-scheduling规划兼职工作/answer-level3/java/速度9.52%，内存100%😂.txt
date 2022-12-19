
感觉快排可能还能优化
```
class Solution {
    private void swap(int[] arr, int i, int j) {
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }
    private void sort(int[] startTime, int[] endTime, int[] profit) {
        quickSort(startTime, endTime, profit, 0, startTime.length - 1);
    }
    private void quickSort(int[] startTime, int[] endTime, int[] profit, int left, int right) {
        if (left >= right) {
            return;
        }
        int l = left;
        int r = right;
        boolean dir = true;
        int p = startTime[l];
        while (l < r) {
            if (dir) {
                while (l < r && p < startTime[r]) {
                    r--;
                }
                if (l < r) {
                    startTime[l] = startTime[r];
                    swap(endTime, l, r);
                    swap(profit, l, r);
                    l++;
                    dir = false;
                }

            } else {
                while (l < r && startTime[l] < p) {
                    l++;
                }
                if (l < r) {
                    startTime[r] = startTime[l];
                    swap(endTime, l, r);
                    swap(profit, l, r);
                    r--;
                    dir = true;
                }
            }
        }
        startTime[l] = p;
        quickSort(startTime, endTime, profit, left, l-1);
        quickSort(startTime, endTime, profit, l+1, right);
    }

    private int foundStart(int[] startTime, int endTime, int left, int right) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (startTime[mid] < endTime) {
                left = mid + 1;
            } else {
                if (mid == 0 || startTime[mid - 1] < endTime) {
                    return mid;
                } else {
                    right = mid - 1;
                }
            }
        }
        return left;
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {

        sort(startTime, endTime, profit);

        int[] totalProfit = Arrays.copyOf(profit, profit.length);
        int lastJ = 0;
        int lastI = 0;
        for (int i = 0; i < startTime.length; i++) {
            // 二分优化
            int j = foundStart(startTime, endTime[i], i, startTime.length - 1);
            if (j == startTime.length - 1 && startTime[j] < endTime[i]) {
                continue;
            }
            // 费用与起始时间优化
            if (lastI > 0 && j >= lastJ && totalProfit[i] <= totalProfit[lastI]) {
                continue;
            }
            if (totalProfit[i] > totalProfit[lastI]) {
                lastJ = j;
                lastI = i;
            }

            for (; j < startTime.length; j++) {
                int pro = totalProfit[i] + profit[j];
                if (pro > totalProfit[j]) {
                    totalProfit[j] = pro;
                }
            }
        }
        int max = 0;
        for (int pro : totalProfit) {
            if (pro > max) {
                max = pro;
            }
        }

        return max;
    }

}
```