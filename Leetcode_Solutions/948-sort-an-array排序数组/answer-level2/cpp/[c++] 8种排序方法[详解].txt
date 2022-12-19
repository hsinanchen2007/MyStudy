8种排序方法,详解.代码来自[@da-li-wang](/u/da-li-wang/)有改动.
```
class Solution {
public:
    /**
     * 排序的本质就是消除逆序数，可以证明对于随机数组，逆序数是O(n^2)的，
     * 而如果采用“交换相邻元素”的办法来消除逆序，每次正好只消除一个，因此
     * 必须执行O(n^2)的交换次数，这就是为什么冒泡、插入等算法只能到平方
     * 级别的原因，反过来，基于交换元素的排序要想突破这个下界，必须执行一
     * 些比较，交换相隔比较远的元素，使得一次交换能消除多个逆序，希尔、快
     * 排、堆排等等算法都是交换比较远的元素，只不过规则各不同罢了.
     *
     * 稳定性是一个特别重要的评估标准.稳定的算法在排序的过程中不会改变元素
     * 彼此的位置的相对次序,反之不稳定的排序算法经常会改变这个次序.
     */


    /**
     * <计数排序>
     * 时间复杂度: 最好O(n) 最坏O(n) 平均O(n) 稳定
     * 空间复杂度: O(n)
     * 缺点: 当最大值最小值差距过大时,不适用计数排序,当元素不是整数值,不适用计数排序.
     */
    vector<int> bucketSort(vector<int> &nums) {
        if (nums.empty()) return {}; // 空数组直接返回
        // 最大值 最小值
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int n = high - low + 1; // 桶的大小(节省空间,若最小值大于0,则最小值前面的空间被浪费)
        vector<int> buckets(n);
        for (auto x : nums) ++buckets[x - low]; // 每个桶下标 + 最小值 = 原数 , 桶值代表有多少个相同的数
        vector<int> res;
        // 遍历每个桶,由小到大直接写入结果
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < buckets[i]; ++j) {
                res.push_back(i + low);
            }
        }
        return res;
    }

    /**
     * <归并排序>
     * 时间复杂度: 最好O(n*log(n)) 最坏O(n*log(n)) 平均O(n*log(n)) 稳定
     * 空间复杂度: O(n)
     */
    vector<int> mergeSort(vector<int> &nums, int l, int r) {
        if (l > r) return {}; // 左指针大于右指针,直接返回空
        if (l == r) return {nums[l]}; // 归并到单个数直接返回,不做排序
        vector<int> res; // 临时数组,返回排序好的部分数组
        int m = l + (r - l) / 2; // 二分
        auto ln = mergeSort(nums, l, m); // 左侧归并
        auto rn = mergeSort(nums, m + 1, r); // 右侧归并
        int i = 0;
        int j = 0;
        while (i < ln.size() && j < rn.size()) { // 只要有一个数组被遍历完,则跳出循环
            if (ln[i] <= rn[j]) {
                res.push_back(ln[i++]);
            } else {
                res.push_back(rn[j++]);
            }
        }
        while (i < ln.size()) res.push_back(ln[i++]); // 若右数组被遍历完,则说明左数组剩下的所有数都大于右数组,直接放在临时数组最后
        while (j < rn.size()) res.push_back(rn[j++]); // 同理
        return res;
    }


    /**
     * <快速排序>
     * 时间复杂度: 最好O(n*log(n)) 最坏O(n^2) 平均O(n*log(n)) 不稳定
     * 空间复杂度: O(log(n))
     * 特点: 本质是给基准数找其正确位置的过程.
     */
    void quickSort(vector<int> &nums, int l, int r) {
        // 右基准版
        if (l >= r) { return; } // 左右指针相遇
        // 增加随机性,若排序数组已排好序,不进行替换复杂度会为O(n^2),此时的基准数为nums[r]
        swap(nums[r], nums[rand() % (r - l + 1) + l]);
        int cur = l; // 最右侧节点应该在数组中的位置,相当于查找第k个数
        for (int i = l; i < r; i++) {
            // nums[cur]之前的数都小于等于nums[r],
            // 相当于只要小于nums[r],则交换当前数与nums[cur],cur++
            if (nums[i] < nums[r]) {
                swap(nums[cur++], nums[i]);
            }
        }
        // 此时cur所指的位置即为num[r]在数组中的对应位置
        // **若使用左基准,cur此时指的位置恰好是第一个大于(位置上讲)num[r]的位置,需将cur--然后再替换**
        swap(nums[cur], nums[r]);
        quickSort(nums, l, cur - 1);
        quickSort(nums, cur + 1, r);

//         左基准版
//        if (l >= r) return;
//        swap(nums[l], nums[rand() % (r - l + 1) + l]);
//        int t = l + 1;
//        for (int i = l + 1; i <= r; ++i) {
//            if (nums[i] < nums[l]) {
//                swap(nums[t++], nums[i]);
//            }
//        }
//        t--;
//        swap(nums[t], nums[l]);
//        quickSort(nums, l, t - 1);
//        quickSort(nums, t + 1, r);


    }

    /**
     * <三路快速排序>
     * 时间复杂度: 最好O(n*log(n)) 最坏O(n^2) 平均O(n*log(n)) 不稳定
     * 空间复杂度: O(log(n))
     * 特点: 适用于数组中存在大量重复的数.
         5   2   3   4   2   1   0      基准[2]
         ((0))   2   3   4   2   (1)   5
         0   ((2))   3   4   2   (1)   5
         0   (2)   (3)   4   2   (1)   5
         0   (2)   (1)   4   (2)   3   5
         0   1   (2)   (2)   (4)   3   5
     */
    void quickSortV2(vector<int> &nums, int l, int r) {
        if (l >= r) return; // 左右指针相遇
        int standard = nums[rand() % (r - l + 1) + l]; // 随机基准数
        int left = l; // 左指针
        int right = r; // 右指针
        /**
         * 三路快排与普通快排的区别是:
         * 普通快排左指针(cur)指的是<第一个大于基准数(位置上讲)>的坐标,
         * 三路快排左指针(left)指的是<第一个等于基准数>的坐标
         */
        for (int i = left; i <= right;) {
            if (nums[i] == standard) {
                ++i;
            } else if (nums[i] < standard) {
                swap(nums[i++], nums[left++]);
            } else {
                //由于num[right]没有被访问过,所以要进行一次比较,i不变
                swap(nums[i], nums[right--]);
            }
        }
        /**
         * 最后一步 i = right , nums[right] 与 基准值
         * nums[right] > 基准值 -> nums[right]与自己互换, right-- , i > right , 停止比较
         * nums[right] == 基准值 -> i++ , i > right , 停止比较
         * nums[right] < 基准值 -> nums[right]与nums[left]交换 , i++ , i > right , 停止比较
         * 综上 right 最后所指的位置为最后一个等于基准值的坐标,
         *     i 最后所指的是第一个大于(位置上讲)基准值的坐标
         */
        quickSortV2(nums, l, left - 1);
        quickSortV2(nums, right + 1, r);
    }


    /**
     * <插入排序>
     * 时间复杂度: 最好O(n) 最坏O(n^2) 平均O(n^2) 稳定
     * 空间复杂度: O(1)
     */
    void insertSort(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            // 从后向前遍历,若前后相邻为逆序,则交换.
            // 因为前部分数组已排好序,若前后相邻为顺序,则跳出循环.
            for (int j = i; j - 1 >= 0 && nums[j - 1] > nums[j]; j--) {
                swap(nums[j - 1], nums[j]);
            }
        }
    }


    /**
     * <希尔排序> / <缩小增量排序>
     * 时间复杂度: 平均O(n^1.3) 不稳定
     * 空间复杂度: O(1)
     * 特点: 缩小增量的插入排序
     */
    void shellSort(vector<int> &nums) {
        for (int gap = nums.size() / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < nums.size(); i++) {
                // 缩小增量插入排序
                for (int j = i; j - gap >= 0 && nums[j - gap] > nums[j]; j -= gap) {
                    swap(nums[j - gap], nums[j]);
                }
            }
        }
    }

    /**
     * <堆排序>
     * 时间复杂度: 最好O(n*log(n)) 最坏O(n*log(n)) 平均O(n*log(n)) 不稳定
     * 空间复杂度: O(1)
     */
    void heapSort(vector<int> &nums) {
        // 构建大顶堆,从第一个非叶子节点开始,向左依次进行下沉操作
        for (int i = nums.size() / 2; i >= 0; --i) {
            siftdown(nums, i, nums.size());
        }
        // 进行出堆操作,相当于pop()
        for (int i = nums.size() - 1; i > 0; --i) {
            swap(nums[0], nums[i]); // 出堆(将最大值放置数组尾,堆size - 1)
            siftdown(nums, 0, i); // 将根执行下沉操作
        }
    }

    void siftdown(vector<int> &nums, int root, int size) {
        /**
         * 构造大顶堆的下浮操作
         */
        while (2 * root + 1 < size) { // 当p存在孩子时
            int c1 = 2 * root + 1; // p节点的左孩子
            int c2 = 2 * root + 2; // p节点的右孩子
            int c = (c2 < size && nums[c2] > nums[c1]) ? c2 : c1; // c是值最大的孩子节点
            if (nums[c] > nums[root]) { // 若孩子节点大于父亲节点,交换位置
                swap(nums[c], nums[root]);
            } else {
                break; // 该点满足堆条件,又因为下方已经成堆,所以不必向下建堆
            }
            /**
             * 若此时节点不是最大值,则有可能也小于
             * <以该节点为根的下一个子堆>的孩子节点
             * 所以需要将该节点也进行一次下沉操作
             */
            root = c;
        }
    }


    /**
     * <冒泡排序>
     * 时间复杂度: 最好O(n) 最坏O(n^2) 平均O(n^2) 稳定
     * 空间复杂度: O(1)
        (5)   2   3   4   2   1   0
        2   (5)   3   4   2   1   0
        2   3   (5)   4   2   1   0
        2   3   4   (5)   2   1   0
        2   2   3   4   (5)   1   0
        1   2   2   3   4   (5)   0
        0   1   2   2   3   4   (5)
     */
    void bubbleSort(vector<int> &nums) {
        // nums[i] 表示每次比较时 nums[0 ~ i-1] 中的最大值
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }


    /**
     * <选择排序>
     * 时间复杂度: 最好O(n^2) 最坏O(n^2) 平均O(n^2) 稳定
     * 空间复杂度: O(1)
     */
    void selectSort(vector<int> &nums) {
        /**
         * 寻找第一小的数,寻找第二小的数 ......
         */
        for (int i = 0; i < nums.size(); i++) {
            int min = i;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
            swap(nums[i], nums[min]);
        }
    }

    vector<int> sortArray(vector<int> &nums) {
        return bucketSort(nums);
    }
};
```
