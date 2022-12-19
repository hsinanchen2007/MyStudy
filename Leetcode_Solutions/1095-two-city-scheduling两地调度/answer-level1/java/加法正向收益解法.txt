### 解题思路
首先将二维数组按照差值从小到大排序，然后按照差值从最大到最小进行筛选，每次都选最小值进行相加，这里有个前提条件是该市的人员还未满的情况。如果一旦某个市人员已满，之后的就全部相加的另外一个市上。根据加法的正收益原理，其费用一定会是最小的。

### 代码

```java
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        quickSort(costs, 0, costs.length - 1);
        int n = costs.length / 2;
        int aNum = 0;
        int bNum = 0;
        int sum = 0;
        for (int i = costs.length - 1; i >=0; --i) {
            int[] oneCost = costs[i];
            if (oneCost[0] > oneCost[1]) {
                if (bNum < n) {
                    bNum++;
                    sum += oneCost[1];
                } else {
                    aNum++;
                    sum += oneCost[0];
                }

            } else {
                if (aNum < n) {
                    aNum++;
                    sum += oneCost[0];
                } else {
                    bNum++;
                    sum += oneCost[1];
                }

            }
        }
        return sum;
    }

    public void quickSort(int[][] arr, int low, int high) {
        int p, l, h;
        int[] temp;

        if (low >= high) {
            return;
        }

        l = low;
        h = high;
        p = arr[l][0] - arr[l][1] >= 0 ? arr[l][0] - arr[l][1] : arr[l][1] - arr[l][0];

        while (l < h) {

            while ((arr[h][0] - arr[h][1] >= 0 ? arr[h][0] - arr[h][1] : arr[h][1] - arr[h][0]) >= p && l < h) {
                h--;
            }

            while ((arr[l][0] - arr[l][1] >= 0 ? arr[l][0] - arr[l][1] : arr[l][1] - arr[l][0]) <= p && l < h) {
                l++;
            }

            temp = arr[h];
            arr[h] = arr[l];
            arr[l] = temp;
        }
        int[] tempOne = arr[low];
        arr[low] = arr[l];
        arr[l] = tempOne;
        quickSort(arr, low, l - 1);
        quickSort(arr, l + 1, high);
    }
}
```