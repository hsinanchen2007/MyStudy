### 解题思路

![image.png](https://pic.leetcode-cn.com/e05bf39b3760a6704f27a870f2532481f2ccf260926919fae8dced1cbfdc0b1d-image.png)

由于题目中说不能超车, 则距离终点越近的车肯定越先到达

思路如下:

1. 排序 我这里使用的是归并排序
2. 遍历, 检查下一辆车是否可能和前一辆车一个车队

### 代码

```java
class Solution {
   public int carFleet(int target, int[] position, int[] speed) {
        if (position.length <= 1) {
            return position.length;
        }
        HashMap<Integer, Integer> map = new HashMap<>(position.length);
        for (int i = 0; i < position.length; i++) {
            map.put(position[i], speed[i]);
        }
        int[] aux = new int[position.length];
        sort(position, aux, 0, position.length - 1);

        double maxTime = (double) (target - position[0]) / map.get(position[0]);
        int max = 1;
        for (int s : position) {
            int len = target - s;
            double time = (double) len / map.get(s);
            if (time > maxTime) {
                maxTime = time;
                max++;
            }
        }

        return max;
    }


    /**
     * 这里使用 merge sort
     */
    public static void sort(int[] a, int[] aux, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        int mid = (lo + hi) / 2;
        sort(a, aux, lo, mid);
        sort(a, aux, mid + 1, hi);
        merge(a, aux, lo, mid, hi);
    }

    private static void merge(int[] a, int[] aux, int lo, int mid, int hi) {
        // 1. 复制到辅助数组中
        System.arraycopy(a, lo, aux, lo, hi - lo + 1);
        // 2. 归并
        int i = lo;
        int j = lo;
        int k = mid + 1;
        while (i <= hi) {
            if (j > mid) {
                a[i++] = aux[k++];
            } else if (k > hi) {
                a[i++] = aux[j++];
            } else if (aux[j] < aux[k]) {
                a[i++] = aux[k++];
            } else if (aux[k] < aux[j]) {
                a[i++] = aux[j++];
            }
        }
    }
}
```