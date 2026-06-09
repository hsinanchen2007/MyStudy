    // 快找工作了，基础知识打实一点
    // 冒泡，快排，归并，shell，计数，堆，插入，折半插入排序
    // 双端起泡，快排 + 荷兰国旗
    // 冒泡/归并/插入/折半插入是稳定的算法（相同关键字排序后次序不变）
    public class N29 {
        // 排序数组
        public static void main(String[] args) {
            int[] nums = {5,4,3,2,1,0};
            //int[] res = sortArray(nums);
            //int[] res = sortArray1(nums);
            //int[] res = sortArray2(nums);
            //int[] res = sortArray3(nums);
            //int[] res = sortArray4(nums);
            //int[] res = sortArray5(nums);
            //int[] res = sortArray6(nums);
            //int[] res = sortArray7(nums);
            //int[] res = sortArray8(nums);
            //int[] res = sortArray9(nums);
            int[] res = sortArray10(nums);
            System.out.println(Arrays.toString(res));
        }

        // 冒泡排序加速  双端起泡排序（超时）
        public static int[] sortArray10(int[] nums) {
            for(int left = 0, right = nums.length - 1;left < right;left++,right--) {
                for(int i = left;i < right;i++) {       // 最大的落到right处
                    if(nums[i] > nums[i + 1]) {
                        int temp = nums[i];
                        nums[i] = nums[i + 1];
                        nums[i + 1] = temp;
                    }
                }
                for(int i = right - 1;i > left;i--) {  // 最小的落到left处
                    if(nums[i] < nums[i - 1]) {
                        int temp = nums[i];
                        nums[i] = nums[i - 1];
                        nums[i - 1] = temp;
                    }
                }
            }
            return nums;
        }

        // 加速快排    快排 + 荷兰国旗
        public static int[] sortArray9(int[] nums) {
            quickSort3(nums, 0, nums.length - 1);
            return nums;
        }
        
        public static void quickSort3(int[] nums, int start, int end) {
            if(end - start <= 0) {
                return;
            }
            int flag = nums[end], less = start - 1, more = end + 1;
            for(int i = start;i < more;i++) {
                if(nums[i] == flag) {
                    continue;
                }else if(nums[i] < flag) {
                    int temp = nums[i];
                    nums[i] = nums[++less];
                    nums[less] = temp;
                }else {
                    int temp = nums[i];
                    nums[i] = nums[--more];
                    nums[more] = temp;
                    i--;
                }
            }
            quickSort3(nums, start, less);
            quickSort3(nums, more, end);
        }

        // 快排 + 第二种partition
        public static int[] sortArray8(int[] nums) {
            quickSort2(nums, 0, nums.length - 1);
            return nums;
        }

        public static void quickSort2(int[] nums, int start, int end) {
            if(end - start <= 0) {
                return;
            }
            int flag = nums[end], less = start - 1;
            for(int i = start;i <= end; i++) {      // partition第二种写法
                if(nums[i] < flag) {
                    int temp = nums[i];
                    nums[i] = nums[less + 1];
                    nums[++less] = temp;
                }
            }
            int temp = nums[end];
            nums[end] = nums[++less];
            nums[less] = temp;
            //System.out.println(Arrays.toString(nums));
            quickSort2(nums, start, less - 1);
            quickSort2(nums, less + 1, end);
        }

        // 插入排序优化 + 二分查找
        public static int[] sortArray7(int[] nums) {
            for(int i = 1;i < nums.length;i++) {
                int left = 0, right = i;
                while(left < right) {
                    int mid = left + (right - left) / 2;
                    if(nums[mid] < nums[i]) {
                        left = mid + 1;
                    }else{
                        right = mid;
                    }
                }
                for(int j = i - 1;j >= left;j--) { // 不交换覆盖也可以
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
            return nums;
        }

        // 堆排序  heapify + heapInsert
        // (i - 1) / 2 即为根节点
        // 左孩子：i * 2 + 1            右孩子：i * 2 + 2
        public static int[] sortArray6(int[] nums) {
            if(nums.length <= 1) {
                return nums;
            }
            for(int i = 0;i < nums.length;i++) {
                // heapInsert 建立大根堆
                for(int j = i;j - 1 >= 0 && nums[(j - 1) / 2] < nums[j];j = (j - 1) / 2) {
                    int temp = nums[(j - 1) / 2];    // 根节点
                    nums[(j - 1) / 2] = nums[j];
                    nums[j] = temp;
                }
            }
            for(int i = nums.length - 1;i > 0;i--) {
                int temp = nums[i];
                nums[i] = nums[0];
                nums[0] = temp;
                // heapify，可递归可迭代，选最大的孩子节点（不越界），如果比根大就交换
                int j = 0;
                while(j * 2 + 1 < i) {
                    int index = j * 2 + 2 < i && nums[j * 2 + 2] > nums[j * 2 + 1] ? j * 2 + 2 : j * 2 + 1;
                    if(nums[index] > nums[j]) {
                        int t = nums[j];
                        nums[j] = nums[index];
                        nums[index] = t;
                    }else {
                        break;  // 孩子节点最大的都比根小，说明已经调整为大根堆了
                    }
                    j = index;
                }
            }
            return nums;
        }

        // shell sort 希尔排序
        // 是插入排序的加强版，gap = n / 2, n / 4 ,,, 1
        public static int[] sortArray5(int[] nums) {
            for(int gap = nums.length / 2;gap >= 1;gap /= 2) {
                for(int i = 0;i < nums.length;i++) {   // 将每个数都在组内插入排序
                    // 不同组在不同组里面排序
                    for(int j = i;j - gap >= 0 && nums[j] < nums[j - gap];j = j - gap) {
                        int temp = nums[j - 1];
                        nums[j - 1] = nums[j];
                        nums[j] = temp;
                    }
                }
            }
            return nums;
        }

        // 插入排序（还可以优化为折半插入排序）
        public static int[] sortArray4(int[] nums) {
            for(int i = 1;i < nums.length;i++) {
                for(int j = i;j > 0 && nums[j] < nums[j - 1];j--) {
                    int temp = nums[j - 1];
                    nums[j - 1] = nums[j];
                    nums[j] = temp;
                }
            }
            return nums;
        }

        // 计数排序
        // -50000 <= nums[i] <= 50000
        public static int[] sortArray3(int[] nums) {
            int[] bucket = new int[100001];
            for(int i = 0;i < nums.length;i++) {
                bucket[nums[i] + 50000]++;
            }
            int index = 0;
            for(int i = 0;i < bucket.length;i++) {
                while(bucket[i]-- != 0) {
                    nums[index++] = i - 50000;
                }
            }
            return nums;
        }

        // 快排
        public static int[] sortArray2(int[] nums) {
            quickSort(nums, 0, nums.length - 1);
            return nums;
        }

        public static void quickSort(int[] nums, int start, int end) {
            if(end - start <= 0) {   // 返回条件注意一下
                return;
            }
            int p = start, q = end, flag = nums[end];
            while(p < q) {
                while(p < q && nums[p] < flag) {p++;}
                while(p < q && nums[q] >= flag) {q--;}
                if(p < q) {
                    int temp = nums[p];
                    nums[p] = nums[q];
                    nums[q] = temp;
                }
            }
            int temp = nums[p];
            nums[p] = flag;
            nums[end] = temp;
            quickSort(nums, start, p - 1);
            quickSort(nums, p + 1, end);
        }

        // 归并
        public static int[] sortArray1(int[] nums) {
            mergeSort(nums, 0, nums.length - 1);
            return nums;
        }

        public static void mergeSort(int[] nums, int start, int end) {
            if(end - start < 1) {
                return;
            }
            int mid = start + (end - start) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            // merge two part
            int[] arr = new int[end - start + 1];
            int p = start, q = mid + 1, index = 0;
            while(p <= mid || q <= end) {
                int left = p <= mid ? nums[p] : Integer.MAX_VALUE;
                int right = q <= end ? nums[q] : Integer.MAX_VALUE;
                arr[index++] = left < right ? left : right;
                if(left < right) {
                    p++;
                }else {
                    q++;
                }
            }
            for(int i = start;i <= end;i++) {
                nums[i] = arr[i - start];
            }
        }

        // 冒泡（超时）
        public static int[] sortArray(int[] nums) {
            for(int end = nums.length - 1;end > 0;end--) {
                for(int j = 0;j < end;j++) {
                    if(nums[j] > nums[j + 1]) {
                        int temp = nums[j];
                        nums[j] = nums[j + 1];
                        nums[j + 1] = temp;
                    }
                }
            }
            return nums;
        }

    }
