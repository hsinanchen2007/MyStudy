### 解题思路
在LeetCode测试用例中,耗时显示为:插入>堆排序>归并排序>快排
对于归并排序和堆排序不甚了解的同学,可以去看看这位up([正月点灯笼](https://space.bilibili.com/24014925))的解读,很是清晰
[归并](https://www.bilibili.com/video/BV1Ax411U7Xx/?spm_id_from=333.788.videocard.0)
[堆排序](https://www.bilibili.com/video/BV1Eb41147dK)

### 代码

```java
 /**
    * 插入排序
    * @param nums
    * @return
    */
    public int[] insertSort(int[] nums) {
        int len = nums.length;
        for (int i = 1; i < len; i++) {
            int currNum = nums[i];
            int j = i - 1;
            while(j>=0 && nums[j] >= currNum){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = currNum;
        }
        return nums;
    }

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /**
     * 快排
     * 执行用时 :5 ms, 在所有 Java 提交中击败了97.87%的用户
     * 内存消耗 :47.6 MB, 在所有 Java 提交中击败了7.38%的用户
     * 快速排序
     * @param nums
     * @param low
     * @param high
     */
    public static void quickSort(int[] nums,int low,int high){
        int i = low;
        int j = high;
        int tmp;
        if(i<j){
            tmp = nums[low];
            while(i<j){
                //从右向左找打一个数小于tmp,放在tmp的左边
                while(i<j && nums[j] > tmp) --j;
                if(i<j){
                    nums[i] = nums[j];
                    ++i;
                }
                //从左向右找到一个数大于tmp
                while(i<j && nums[i] < tmp) ++i;
                if(i<j){
                    nums[j] = nums[i];
                    --j;
                }
            }
            nums[i] = tmp;
            quickSort(nums, low, i-1);//对左边进行排序
            quickSort(nums, i+1, high);
        }
    }

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    /**
     * 堆排序
     * 堆化过程:(假设对索引为i的节点进行堆化)
     * 其左孩子节点在数组中的索引:2*i+1
     * 其右孩子节点在数组中的索引:2*i+2
     * 从这三个节点中选出最大的值的节点放到索引i的位置
     *
     * @param nums
     */
    public static void heapSort(int[] nums,int n){
        buildHeap(nums,n);
        for (int i = n-1; i >= 0 ; i--) {
            //将最后一个节点和根节点交换,起到排序的效果
            swap(nums,i,0);
            //将除了有序序列之外的剩下的所有节点再次堆化
            heapify(nums,i,0);//i=n-1,正好将最后一个节点排除在堆化过程之外
        }
    }

    /**
     *
     * @param tree 节点数组
     * @param n 树中有多少个节点
     * @param i 当前对那个节点做堆化操作
     */
    public static void heapify(int[] tree,int n,int i){
        if(i >= n){
            return;
        }
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex= 2 * i + 2;
        int maxValueIndex = i;

        //两个if语句找到三个节点中值最大的那个索引
        if(leftChildIndex <n && tree[leftChildIndex] > tree[maxValueIndex]){
            maxValueIndex = leftChildIndex;
        }
        if(rightChildIndex < n && tree[rightChildIndex] > tree[maxValueIndex]){
            maxValueIndex = rightChildIndex;
        }

        //交换最大值和当前堆化节点的位置
        if(maxValueIndex != i){
            swap(tree,maxValueIndex,i);
            heapify(tree,n,maxValueIndex);
        }
    }

    public static void buildHeap(int[] tree,int n){
        int lastNode = tree.length-1;
        int lastNodeParent = (lastNode - 1) / 2;
        //从最后一个节点的父节点开始堆化
        for (int i = lastNodeParent; i >=0 ; i--) {
            heapify(tree,n,i);
        }
    }


    /**
     * 交换值的位置
     * @param nums
     * @param i
     * @param j
     */
    public static void swap(int[] nums,int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/**
     * 分治
     * @param nums
     * @param L
     * @param R
     */
    public static void mergeSort(int[] nums,int L,int R){
        if(L == R) {
            return;//递归终止条件
        }
        int M = (L + R)/2;
        mergeSort(nums,L,M);
        mergeSort(nums,M + 1,R);
        //合并两边已经有序的子数组
        merge(nums,L,M+1,R);

    }

    /**
     * 将两个有序子数组合并
     * @param nums
     * @param L
     * @param M
     * @param R
     */
    public static void merge(int[] nums,int L,int M,int R){
        int leftSize = M - L;
        int rightSize = R - M + 1;
        int[] left = new int[leftSize];
        int[] right = new int[rightSize];

        //将原数组拆成两个部分,装入到两个数组中去
        //1.将左半部分放到left数组中
        for (int i = L; i < M; i++) {
            left[i-L] = nums[i];
        }
        //2.将左半部分放到right数组中
        for (int i = M; i <= R; i++) {
            right[i-M] = nums[i];
        }

        //3.依次比较两个数组中的元素,将较小的那个元素填到数组中去
        int i = 0;
        int j = 0;
        int k = L;
        while(i < leftSize && j < rightSize){
            if(left[i] < right[j]){
                nums[k] = left[i];
                k++;
                i++;
            }else{
                nums[k] = right[j];
                k++;
                j++;
            }
        }
        //4.将剩下的元素填入到数组中去
        while(i < leftSize){
            nums[k] = left[i];
            k++;
            i++;
        }
        while(j < rightSize){
            nums[k] = right[j];
            k++;
            j++;
        }

    }