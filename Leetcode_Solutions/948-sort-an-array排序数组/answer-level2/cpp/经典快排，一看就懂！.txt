### 解题思路
1. 整个过程参考https://www.***.org/quick-sort/
2. 快排的思路就是先找一个pivot，把小于pivot的数全部移到前面，大于pivot的数全部移到后面去，这也导致了快排是不稳定的。
2. 这个过程我放在了partition函数，这里只需要注意i和j两个变量
3. **i代表小于pivot的数的下标，j表示当前正在遍历的数的下标**
4. i的初始位置在low-1，每当出现一个小于pivot的数，i就+1，并且把这个数放在nums[i]的位置
5. 最后把pivot放在i+1的位置，这时它左边的数全比它小，右边的数全比它大
6. 递归运算，这样我们就能得到一个新的nums数组啦  ：）
![image.png](https://pic.leetcode-cn.com/e00e2c4e385e4690eb1bde854205806d99c4e500d6e28362a1a360ba67fb6faf-image.png)

### 代码

```cpp
class Solution {
private:
    void quick_sort(vector<int>& nums,int low,int high)
    {
        if(low>=high) return;//先判断跳出条件，不写的话会一直运行报错
        int pi=partition(nums,low,high);//调用partition函数，得到pi的值
        quick_sort(nums,pi+1,high);//递归
        quick_sort(nums,low,pi-1);
    }
    int partition(vector<int>& nums,int low,int high)
    {
        int pivot=nums[high];//这里取high和low都可以，如果用low注意后面的代码也要改
        int i=low-1;//第一次运行这里是-1，注意不要越界
        for(int j=low;j<high;j++)//用j遍历整个数组，除了我们设定的pivot所在的位置
        {
            if(nums[j]<pivot)//正在遍历的数小于pivot
            {
                i++;//先++再转换，不会越界
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[high]);//把pivot移到中间，此时nums【i+1】是个大于pivot的数，直接移到最后
        return i+1;
    }   
public:
    vector<int> sortArray(vector<int>& nums) {
        int len=nums.size();
        quick_sort(nums,0,len-1);//nums的下标从0到len-1
        return nums;
    }
    
};
```
如果觉得有帮助的话，就给我点个赞，有问题或者建议也可以提出来（每天都会看）
艾薇波弟让我看到你的双手好吗！