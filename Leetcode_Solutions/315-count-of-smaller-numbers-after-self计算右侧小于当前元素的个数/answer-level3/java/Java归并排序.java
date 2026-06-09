### 解题思路
right队列出列时值加1，positions记录索引，最后排序后的结果是索引的排序。
比如5、2、6、1的坐标是0、1、2、3，正常值排序后的结果是1、2、5、6，对应的坐标排序就是3、1、0、2。

### 代码

```java

/**
 * Solution
 *
 * @author jianghe
 * @since 2020-04-02
 */
class Solution {
    private int[] record;

    public List<Integer> countSmaller(int[] nums) {
        record = new int[nums.length];
        int[] positions = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            positions[i] = i;
        }
        mergeSort(0, nums.length - 1, positions, nums);
        List<Integer> res = new ArrayList<>();
        for (int num : record) {
            res.add(num);
        }
        return res;
    }

    private void mergeSort(int left, int right, int[] position, int[] nums) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(left, mid, position, nums);
        mergeSort(mid + 1, right, position, nums);
        merge(left, mid, right, position, nums);
    }

    private void merge(int left, int mid, int right, int[] positions, int[] nums) {
        int[] temp = new int[right - left + 1];
        int k = 0;
        int l = left;
        int r = mid + 1;
        while (l <= mid && r <= right) {
            if (nums[positions[l]] <= nums[positions[r]]) {
                // left出列
                record[positions[l]] += r - (mid + 1);
                temp[k++] = positions[l++];
            } else {
                // right出列
                temp[k++] = positions[r++];
            }
        }
        while (l <= mid) {
            record[positions[l]] += r - (mid + 1);
            temp[k++] = positions[l++];
        }
        while (r <= right) {
            temp[k++] = positions[r++];
        }
        System.arraycopy(temp, 0, positions, left, temp.length);
    }
}
```