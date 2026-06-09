
```
// O(1) in place . 需要额外空间的是 out of place 或者 None place, 稳定排序
    vector<int> sortArray(vector<int>& nums) {

        int size = nums.size();
        // 冒泡1
        // bubbleSort1(nums, size);
        // 冒泡2 (针对本来全有序的优化))
        // bubbleSort2(nums, size);
        // 冒泡3 (部分有序优化))
        // bubbleSort3(nums, size);

        // 选择排序
        // selectionSort(nums, size);
        // 堆排序
        heapSort(nums, size);

        return nums;
    }

    // ----------------------- 冒泡排序 -----------------
    // 第一种:每次都会有一个最大值放最后，所以每次外循环会-1，
    // 时间复杂度：O(n^2) ,空间复杂度O(1)
    // 5,2,3,1
    void bubbleSort1(vector<int>& nums, int size) {
        for (int end = size -1; end > 0; end --) {
            // begin=1 是拿到当前的  再去拿它前面的一个（begin-1）
            for (int begin = 1; begin <= end; begin ++) {
                if (nums[begin] < nums[begin-1]) {  // 这里 != 是稳定排序 (相等就不用交换)
                    int tmp = nums[begin];
                    nums[begin] = nums[begin-1];
                    nums[begin-1] = tmp;
                }
            }
        }
    }

   // 第二种: 在1的基础上进行优化，也就是如果本来就是有序的，就不用在判断
   // 最好时间复杂度: O(n)
    void bubbleSort2(vector<int>& nums, int size) {
        for (int end = size - 1; end > 0; end --) {
            bool sorted = true;
            for (int begin = 1; begin <= end; begin ++) {
                if (nums[begin] < nums[begin-1]) {
                    int tmp = nums[begin];
                    nums[begin] = nums[begin-1];
                    nums[begin-1] = tmp;
                    sorted = false;
                }
            }

            if (sorted) break;
        }
    }

    // 第三种: 在2的基础上优化， 就是有可能后面一段就是有序的， 外循环就可以直接减少判断
    // 最坏和平均时间复杂度是O(n^2), 最好O(n) ,空间复杂度O(1)
    // 如： 3，7，2，8，9，10  （后面8 9 10已经有序，所有判断就到index=2就行）
    void bubbleSort3(vector<int>& nums, int size) {
        for (int end = size - 1; end > 0; end --) {
            // sortedIndex =1或0，-1都行，用于记住最后一次替换的index。（-- <=0 就行不满足上面条件）
            int sortedIndex = 1;
            for (int begin = 1; begin <= end; begin ++) {
                if (nums[begin] < nums[begin-1]) {
                    int tmp = nums[begin];
                    nums[begin] = nums[begin-1];
                    nums[begin-1] = tmp;
                    sortedIndex = begin;
                }
            }
            end = sortedIndex;
        }
    }

    // ----------------------- 选择排序 -----------------
    // 选择排序和冒泡的比较就是 拿到最大值和尾部元素交换，外循序--
    //  最好坏平均都是O(n^2), 空间复杂度O(1), 稳定排序
    // 5,3,3,2,1 > 1,3,3,2,5 > 1,2,3,3,5
    void selectionSort(vector<int>& nums, int size) {
        for (int end = size-1; end > 0; end --) {
            int maxIndex = 0;
            for (int begin = 1; begin <= end; begin ++) {
                if (nums[maxIndex] < nums[begin]) {
                    maxIndex = begin;
                }
            }

            int tmp = nums[maxIndex];
            nums[maxIndex] = nums[end];
            nums[end] = tmp;
        }
    }

     // ----------------------- 堆排序 -----------------
     // 在选择排序的基础上优化，也是找到最大值，可以利用二叉堆 也就是大顶堆来实现
     void heapSort(vector<int>& nums, int size) {
         // 建堆（把原来的数组变成大顶堆的数组）
         // (size >> 1)-1：最后一个非叶子节点
         for (int i = (size >> 1)-1; i >= 0; i --) {
             siftDown(nums, size, i);
         }

         while (size >1 ) {
             // 交换堆顶和尾部元素
            swap(nums, 0, --size);  

            // 恢复堆
            siftDown(nums, size, 0);
         }
     }

     void swap(vector<int>& nums, int v1, int v2) {
         int tmp = nums[v1];
         nums[v1] = nums[v2];
         nums[v2] = tmp;
     }

     void siftDown(vector<int>& nums, int size, int index){
         int elemet = nums[index];
         int half = size >> 1;  
        
        // 必须是叶子节点才行  1.只有左  2.左右都有
         while (index < half) {
             // 左子节点
             int leftChildIndex = (index << 1) +1;
             // 右子节点
             int rightChildIndex = leftChildIndex+1;

            // rightChildIndex < size: 有右子节点
            if (rightChildIndex < size && nums[leftChildIndex] < nums[rightChildIndex]) {
                leftChildIndex = rightChildIndex;
            }
            
            // 左右子节点的值本来就小于它 就直接break 
            if (elemet >= nums[leftChildIndex]) break;

            nums[index] = nums[leftChildIndex];
            nums[leftChildIndex] = elemet;
            index = leftChildIndex;
         }

         nums[index] = elemet;
     }
```
