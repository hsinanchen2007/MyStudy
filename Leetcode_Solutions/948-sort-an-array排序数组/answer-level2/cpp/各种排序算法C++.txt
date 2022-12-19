### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // bubleSort(nums);
        //insertSort(nums);

        //selectSort(nums);
        //quickSort(nums, 0, nums.size()-1);
        //heapSort(nums);
        return CountSort(nums);
    }

    //1
    //冒泡排序 
    //最好已经有序O(N), 最差O(N^2),平均O(N^2) 稳定（不改变原来相等位置）
    //思想： N个数排序，N-1趟，每趟第一个和第二个比，后者大交互，第二个与第三个比。。。
    //每次在最后增加一个这趟找到的最大值，下趟减少一个比较次数。
    void bubleSort(vector<int>& nums) {
        for(int i = 1;i < nums.size(); i++) {//i表示趟数，共n-1趟
            bool swaped = false;
            for(int j = 0; j < nums.size() - i; j++) {//每趟减少1个。
                if(nums[j] > nums[j+1]) {//相等不交换，所以稳定
                    swap(nums[j+1], nums[j]);
                    swaped = true;
                }
            }
            if(!swaped) //加了这个才有最好情况
                break;
        }
    }
    //2
    //插入排序 
    //最好O(N)已有序， 最坏O(N^2),平均O(N^2) 稳定
    //思想：把第一个元素当做已排序数组，从1-N中依次选择元素从后往前插入到有序数组中 
    void insertSort(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) { //i表示当前要加入有序数组中的元素
            for(int j = i;j > 0 && nums[j] < nums[j-1]; j--) {//0到j-1表示有序数组，j表示当前要加入的元素。从后往前依次比较， 小于就交换
                swap(nums[j], nums[j-1]);
            }
        }
    }

    //3
    //选择排序
    //最好、最坏、平均都是O(N^2) 不稳定，比如2,4,2,1： 第一个2将和1交换
    //思想：总共N-1趟，每趟找出剩余元素中的最小值放到当前考虑的位置
    void selectSort(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++) {//i表示当前考虑位置最小值
            int min_index = i;//初始化当前i为最小
            for(int j = i+1; j < nums.size(); j++) {//依次与后面元素比较
                if(nums[j] < nums[min_index]) {
                    min_index = j;//更新最小下标
                }
            }
            swap(nums[i], nums[min_index]);//把最小值放在i的位置
        }
    }
    
    //4
    //快速排序
    //最好、平均都是O(NlogN), 最坏是一颗斜树O(N^2) 不稳定
    //思想: 以最后一个元素作为划分元素，大于等于它的放右边，小的放左边
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        //增加随机性，不然如果已经有序，取最左边，每次划分都只减少一个
        int m = l + (r - l) / 2;
        swap(nums[r], nums[m]);

        int t = l;//t表示最终划分元素应该在的位置
        for (int i = l; i < r; ++i) {//从从左到右扫描
            if (nums[i] < nums[r]) {//找打比划分元素小的
                swap(nums[t++], nums[i]);//t要么等于i，交互自身，要么比i位置的元素大
            }
        }
        swap(nums[t], nums[r]);//交互划分元素，现在划分元素放在t处
        quickSort(nums, l, t - 1);//排序t左边
        quickSort(nums, t + 1, r);//排序t右边
    }

    //5
    //归并排序
    //思路：有点类似选择排序，先划分到最小每组只有一个元素，然后合并这两个元素，选择小的放到辅助数组中。依次进行。
    //过程：大事化小，小事化了。先划分再合并
    //时间复杂度： nlogn
    //空间复杂度：O(N)
    void merge(vector<int> & a, vector<int>& auxi, const int lo, const int mid, const int hi) {
        for(int i = lo; i <= hi; i++) {
            auxi[i] = a[i];//辅助数组保存一下值
        }
        int i = lo;
        int j = mid + 1;
        //从auxi[lo, mid]及auxi[mid+1, hi]中选择小的放在a[lo, hi]中。
        for(int k = lo; k <= hi; k++) {
            if(i > mid) 
                a[k] = auxi[j++];
            else if(j > hi) 
                a[k] = auxi[i++];
            else if(auxi[i] < auxi[j]) 
                a[k] = auxi[i++];
            else 
                a[k] = auxi[j++];
        }
    }
    void mergeSort(vector<int>& a, vector<int>& auxi, const int lo, const int hi) {
        if(lo >= hi) return;//只剩一个，已经有序，不必再分
        int mid = lo+(hi-lo)/2;//注意溢出
        mergeSort(a, auxi, lo, mid);//划分到最小
        mergeSort(a, auxi, mid+1, hi);
        //[lo, mid]和[mid+1, hi]都排好序了，合并它们
        merge(a, auxi, lo, mid, hi);
    }

    //6
    //堆排序
    //思想：建立大顶堆，利用数组存储二叉树
    //最好、最坏、平均都是nlogn, 不稳定
    //给定一个元素，下层到已有大根堆
    void sink(vector<int> &a, int index, int size) {
        while(index * 2 + 1 < size) {//是否已经是叶子节点
            int j = index * 2 + 1;          
            if(j < size && j+1 < size && a[j+1] > a[j]) 
                j++;
            if(a[index] >= a[j]) break;
            swap(a[index], a[j]);
            index = j;
        }
    }
    //给定一个数组，建立大根堆
    void heapify(vector<int> &a) {
        int size = a.size();
        for(int i = size / 2 - 1; i >= 0; i--) {//size/2 -1 是最后一个非叶子节点，它以下都是叶子节点，不用下沉了
            sink(a, i, size);
        }
    }
    void heapSort(vector<int> &a) {
        int N = a.size();
        heapify(a);//建立大根堆
        while(N > 1) {
            swap(a[0], a[--N]);//选择最大元素（根）
            sink(a, 0, N);//修复堆
        }
    }

    //7
    //计数排序
    //时间复杂度: O(n+k) k为元素范围
    //空间复杂度: O(k)
    vector<int> CountSort(vector<int> &nums) {
        int max = nums[0];
        int min = nums[0];
        for(auto e : nums) {
            max = max > e ? max : e;
            min = min < e ? min : e;
        }
        int size = max - min + 1;
        vector<int> vcount(size, 0);
        for(auto e : nums) {
            vcount[e-min]++;//使用元素作为新数组索引
        }
        
        for(int i = 1; i < size; i++) {
            vcount[i] += vcount[i-1];//计算不大于当前元素的个数，即这个元素的最终位置
        }

        vector<int> res(nums.size(), 0);

        for(auto e : nums) {
            int index = --vcount[e-min];//重复元素递减
            res[index] = e;//放入最终返回数组
        }

        return res;

    }

};
```