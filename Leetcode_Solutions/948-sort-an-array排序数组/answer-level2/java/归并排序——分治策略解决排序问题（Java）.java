### 解题思路
执行用时 :7 ms, 在所有 Java 提交中击败了91.07%的用户
内存消耗 :47.6 MB, 在所有 Java 提交中击败了7.38%的用户

采用归并排序算法
- 先分解，再归并
一次归并只能处理两个有序序列，所以需要将序列不断划分为更小的序列，当递归到最小的时候，每个小序列里只有一个元素，一定是有序的，所以可以进行归并。然后，因为这个归并之后的序列也是有序的了，所以可以和其它有序序列再进行归并，直到结束所有递归。

代码分析：
- 三个指针：low：前面序列的指针，mid：两个序列的分界线，high：后面序列的指针
结束条件：
- 因为不断递归划分，所以low、mid和hight指针在不断变化
- 但low应该始终在high的左面
- 所以，当low >= high的时候，就代表递归到最后一层，直接返回
递归：
- 先递归划分前面序列（每次都递归前面的序列，直到递归到最底层，深度优先）
- 然后当其中一个序列的前面序列递归返回后，我们就递归它后面的序列
- 当前面和后面都递归到最底层返回的时候（一定是一个有序序列），我们就将它们进行归并
归并（二路归并）：
- 先创建一个临时数组temp，用于存放归并之后的序列
- 设定两个指针，最初位置分别为两个已经排序序列的起始位置
- 比较两个指针所指向的元素，选择相对小的元素放入到 temp 中，并移动指针到下一位置
- 重复执行步骤3，直到其中一个指针达到序列尾部
- 最后将另一个序列剩余的元素，直接全部放入temp中
- 再将temp同步到原数组中即可（注意放置的位置）
重复上述操作，直到所有递归结束

解析：[归并排序](https://blog.csdn.net/weixin_42193813/article/details/105192050)

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        mergeSort(nums, 0, nums.length - 1);
        return nums;
    }
    private static void mergeSort(int[] array, int low, int high) {
        int mid = (high + low) / 2;
        if (low >= high) {
            return;
        }
        mergeSort(array, low, mid); // 递归前面的
        mergeSort(array, mid +1, high); // 递归后面的
        merge(array, low, mid, high); // 归并
    }
    private static void merge(int[] array, int low, int mid, int high) {
        // 创建一个临时数组，用于存放归并之后的结果
        int temp[] = new int[high - low + 1];
        int index = 0; // 临时数组的索引
        int i = low; // 前面数组的索引
        int j = mid + 1; // 后面数组的索引
        while (i <= mid && j <= high) {
            if (array[i] <= array[j]) {
                temp[index] = array[i];
                i++;
                index++;
            } else {
                temp[index] = array[j];
                j++;
                index++;
            }
        }
        // 将剩余的数组直接放入临时数组
        while (j <= high) {
            temp[index] = array[j];
            j++;
            index++;
        }
        while (i <= mid) {
            temp[index] = array[i];
            i++;
            index++;
        }
        // 把临时数组存入原数组
        System.arraycopy(temp, 0, array, low, temp.length);
    }
}
```