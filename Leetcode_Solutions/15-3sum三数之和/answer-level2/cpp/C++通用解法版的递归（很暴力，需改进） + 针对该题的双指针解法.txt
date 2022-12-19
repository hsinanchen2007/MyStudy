# 1.递归
### 递归的主要任务是把大问题分解成同类型的子问题，待每个子问题解决时，大问题也解决了

#### 在这题中，大问题是：从数组中找到3个元素，使它们之和等于target（题目中规定为0）
#### 那么子问题可以是这样 ： 从数组中选定一个数num1，在剩余数中找到两个元素，使它们之和等于tagget1 = target - num（题目中即为-num1）
#### 那么再将子问题问题分解：再从数组中选定一个数num2,在剩余数中找出一个元素，使它等于target2 = target1 - num2

###### 考虑到题目指出，同样的结果不做存储，那么我们还需先对原始数组排序。在取好num1之后，一般num2即取num1后面的数，但是当num1 == num2时，我们即可跳过该num2继续往后去num2,同时适用于num3的选择


```
<!-- 伪代码 -->
function 递归函数(给定数组nums, 几个数n， 数的目标和target):
    递归结束条件判断;
    for(n : nums) :
        递归函数(nums, n - 1, target - n);

function main :
    排序nums;
    递归函数(nums, 3, 0);



```


```
    void getResult(vector<int>& nums, vector<vector<int>>& result, vector<int>&arr, int numCount, int target, int begin) {
        // 1.递归结束条件
        if (numCount == 1) {
            // 在有序数组中查找指定数字，可以用二分查找
            int end = nums.size() - 1;
            int start = begin;
            int mid;
            while (start <= end) {
                mid = start + ((end - start) >> 1);
                if (nums[mid] == target) {
                    //找到满足条件的数，将结果压入result
                    arr.push_back(nums[mid]);
                    result.push_back(arr);
                    arr.pop_back();
                    return;
                }
                else if (nums[mid] < target)
                    start = mid + 1;
                else if (nums[mid] > target)
                    end = mid - 1;
            }
            //没有满足的数，直接返回
            return;
        }


        // 2.分解大问题为小问题
        for (int i = begin; i < nums.size(); i++) {
            //去重
            if(i - 1 >= begin && nums[i] == nums[i - 1])
                continue;

            if (i != begin)
                arr.pop_back();
            arr.push_back(nums[i]);
            getResult(nums, result, arr, numCount - 1, target - nums[i], i + 1);
        }
        if(!arr.empty())
            arr.pop_back();

    }               

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 1)
            return result;
        // 1.排序
        sort(nums.begin(), nums.end());

        vector<int> arr;    //arr 记录每次满足的3个数
        /*
        ** nums     : 给定的排序后数组
        ** result   : 存储所有满足三数之和等于target的结果
        ** arr      : 存储每次满足条件的三个数
        ** numCount : 当前是numCount个数相加      题目中默认为3
        ** target   : numCount个数加起来的目标和  题目中为0
        ** begin    : 从begin这个下标出开始取numCount中的第一个数  默认从下标0开始
        */
        getResult(nums, result, arr, 3, 0, 0);  
        return result;

    }
```
![image.png](https://pic.leetcode-cn.com/3727208cb6ecb04179208954c2fcb55f8249cce09de5931c2c5a9a55c62f4528-image.png)

# 2.循环 + 双指针
### 思路来源于[167. 两数之和 II - 输入有序数组](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/solution/liang-shu-zhi-he-ii-shu-ru-you-xu-shu-zu-by-leetco/)

##### 结合递归中分割子问题的思路，将问题分解成***子问题两数相加***时，即可用双指针来解题

```
    bool twoNumSum(vector<int>& nums, int begin, int& sec, int& thr, int target, vector<vector<int>>& result) {
        sec = begin;
        thr = nums.size() - 1;
        while (sec < thr) {
            int sum = nums[sec] + nums[thr];
            if (sum < target)
                sec++;
            else if (sum == target) {
                vector<int>temp = { nums[begin - 1], nums[sec], nums[thr] };
                result.push_back(temp);
                int temp1 = sec, temp2 = thr;
                //寻找其他可能存在的不同解
                while (sec < thr && nums[temp1] == nums[sec] && nums[temp2] == nums[thr]) {
                    sec++;
                    thr--;
                }
            }
            else if (sum > target)
                thr--;
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        if (nums.size() < 1)
            return result;
        // 1.排序
         sort(nums.begin(), nums.end());
         int firstIndex, secondIndex, threeIndex;
         int target = 0;
         for (firstIndex = 0; firstIndex < nums.size(); firstIndex++) {
             if(firstIndex - 1 >= 0 && nums[firstIndex] == nums[firstIndex - 1])
                 continue;
             // 将问题转换为求两数之和
             twoNumSum(nums, firstIndex + 1, secondIndex, threeIndex, target - nums[firstIndex], result);
         }
         return result;

    }
```
![image.png](https://pic.leetcode-cn.com/0ea9b1f1e99d334f5bbd09e1a8992c872caea9bc64b3e517131bfc42cbaa4668-image.png)

# 3.待更新, 看一下大佬们的代码，把递归优化一下，或者转换为动态规划
 

