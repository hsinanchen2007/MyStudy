### 解题思路
快速排序

### 代码
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums,0,nums.size()-1);
        return nums[nums.size()-k];
    }
    //快速排序算法：递归
    void quickSort(vector<int>&arr,int low,int high){
        //low==high说明子序列只有一个数，分割结束
        if(low<high){
            //返回中间值的坐标，左边的全部小于中间值，右边的大于
            int pv=partition(arr,low,high);
            //对子序列继续分割中间值
            quickSort(arr,low,pv-1);
            quickSort(arr,pv+1,high);
        }
    }
    //分割数组，并返回枢轴坐标，枢轴左边小于枢轴值，右边得大于枢轴值
    int partition(vector<int> &arr,int low,int high){
        //取出第一个值，相当于形成一个空位
        int pv=arr[low];
        //当low==high说明已经找到中间数，坐标即为low
        while(low<high){
            //在右边找到比中间值小的值，并交换到左边的空位上
            while(low<high && arr[high]>=pv)high--;
            swap(arr,low,high);
            //在左边找到比中间值大的值，并交换到右边的空位上
            while(low<high && arr[low]<=pv)low++;
            swap(arr,low,high);
        }
        return low;
    }
    void swap(vector<int> &arr,int low,int high){
        //不能随便交换
        if(low<high){
            int temp=arr[low];
            arr[low]=arr[high];
            arr[high]=temp;
        }
    }
};