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
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }

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

    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int t = l;
        for (int i = l; i < r; ++i) {
            if (nums[i] < nums[r]) {
                swap(nums[t++], nums[i]);
            }
        }
        swap(nums[t], nums[r]);
        quickSort(nums, l, t - 1);
        quickSort(nums, t + 1, r);
    }
    

};
```