```
class Solution {
    /*冒泡排序*/
    public int[] sortArray(int[] nums) {
        if (nums.length == 0)
            return nums;
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = 0; j < nums.length - i - 1; j++) {
                if (nums[j + 1] < nums[j]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        return nums;
    }
    /*选择排序*/
    public int[] sortArray(int[] nums) {
        if (nums.length == 0)
            return nums;
        for (int i = 0; i < nums.length - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
        }
        return nums;
    }
    /*插入排序*/
    public int[] sortArray(int[] nums) {
        if (nums.length == 0)
            return nums;
        for (int i = 0; i < nums.length - 1; i++) {
            int pre = i;
            int cur = nums[i + 1];
            while (pre >= 0 && cur < nums[pre]) {
                nums[pre + 1] = nums[pre];
                pre--;
            }
            nums[pre + 1] = cur;
        }
        return nums;
    }
    /*希尔排序*/
    public int[] sortArray(int[] nums) {
        int len = nums.length;
        if (len == 0)
            return nums;
        int gap = len / 2;
        while (gap > 0) {
            for (int i = gap; i < len; i++) {
                int cur = nums[i];
                int preIndex = i - gap;
                while (preIndex >= 0 && cur < nums[preIndex]) {
                    nums[preIndex + gap] = nums[preIndex];
                    preIndex -= gap;
                }
                nums[preIndex + gap] = cur;
            }
            gap /= 2;
        }
        return nums;
    }
    /*归并排序*/
    public int[] sortArray(int[] nums) {
        int len = nums.length;
        if (len < 2)
            return nums;
        int mid = len / 2;
        int[] left = Arrays.copyOfRange(nums, 0, mid);
        int[] right = Arrays.copyOfRange(nums, mid, len);
        return merge(sortArray(left), sortArray(right));
    }
    public int[] merge(int[] left, int[] right) {
        int[] res = new int[left.length + right.length];
        for (int index = 0, i = 0, j = 0; index < res.length; index++) {
            if (i >= left.length)
                res[index] = right[j++];
            else if (j >= right.length)
                res[index] = left[i++];
            else if (left[i] < right[j])
                res[index] = left[i++];
            else
                res[index] = right[j++];
        }
        return res;
    }
    /*快速排序*/
    public int[] sortArray(int[] nums) {
        if (nums.length == 0)
            return nums;
        quickSort(nums, 0, nums.length - 1);
        return nums;
    }
    public void quickSort(int[] nums, int l, int r) {
        if (l < r) {
            int i = l, j = r, x = nums[l];
            while (i < j) {
                while (i < j && nums[j] >= x) j--;
                if (i < j)
                    nums[i++] = nums[j];
                while (i < j && nums[i] < x) i++;
                if (i < j)
                    nums[j--] = nums[i];
            }
            nums[i] = x;
            quickSort(nums, l, i - 1);
            quickSort(nums, i + 1, r);
        }
        else
            return ;
    }
    /*堆排序*/
    public int[] sortArray(int[] nums) {
        if (nums.length == 0)
            return nums;
        HeapSort(nums, nums.length);
        return nums;
    }
    /*
	@param arr 待调整的数组
	@param i 待调整的结点的下标
	@param length 数组的长度
    */
    public void HeapAdjust(int arr[], int i, int length) {
        // 调整i位置的结点
        // 先保存当前结点的下标
        int max = i;
        // 当前结点左右孩子结点的下标
        int lchild = i * 2 + 1;
        int rchild = i * 2 + 2;
        if (lchild < length && arr[lchild] > arr[max]) {
            max = lchild;
        }
        if (rchild < length && arr[rchild] > arr[max]) {
            max = rchild;
        }
        // 若i处的值比其左右孩子结点的值小，就将其和最大值进行交换
        if (max != i) {
            int temp;
            temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
            // 递归
            HeapAdjust(arr, max, length);
        }
    }
    // 堆排序
    public void HeapSort(int arr[], int length) {
        // 初始化堆
        // length / 2 - 1是二叉树中最后一个非叶子结点的序号
        for (int i = length / 2 - 1; i >= 0; i--) {
            HeapAdjust(arr, i, length);
        }
        // 交换堆顶元素和最后一个元素
        for (int i = length - 1; i >= 0; i--) {
            int temp;
            temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            HeapAdjust(arr, 0, i);
        }
    }
}
```
