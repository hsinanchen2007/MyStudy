![ED637522-AB5C-4EC0-B9BB-3B439D9FD9AA.png](https://pic.leetcode-cn.com/c0442a47bd241e0b3432ff752e014185a1a9e57b0f38598076488f4daa307228-ED637522-AB5C-4EC0-B9BB-3B439D9FD9AA.png)


### 法1，先定位一个与 target 相同的数作为基准数，在通过基准数前后遍历得到开始与结束位置

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if(!nums.size()) return res;   // 特判

        // 先用二分法找到第一个与 target 相等的元素作为基准（benchmark）
        int benchmark;
        // 设立一个标识位，在二分法的 while 循环结束后，根据这个标识位判断是否找到了第一个与 target 相等的元素
        // --- 找到了，flag = true ，此时直接退出 while 循环，后面就要通过基准定位开始与结束位置
        // --- 没找到，循环也正常结束了，此时 flag = false ，要注意 left = right 这个位置还没有判断
        bool flag = false;
        int left = 0, mid, right = nums.size() - 1;
        while(left < right & !flag) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                benchmark = mid;
                flag = true;   // 退出循环
            }
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        // 根据上面的 flag 值
        // --- flag = true，说明二分法中找到了第一个与 target 相等的元素，且它的位置是 benchmark
        // --- 这时，遍历 benchmark 的前后，找到与 target 相等的元素的开始位置与结束位置
        if(flag) {
            int tmp = benchmark;
            bool lFlag = true, rFlag = true;

            while(tmp > 0 && lFlag) if(nums[--tmp] != target) lFlag = false;
            if(lFlag) res[0] = tmp;
            else res[0] = ++tmp;   // 开始位置

            tmp = benchmark;
            while(tmp < nums.size() - 1 && rFlag) if(nums[++tmp] != target) rFlag = false;
            if(rFlag) res[1] = tmp;
            else res[1] = --tmp;   // 结束位置
        }
        // --- flag = false，说明二分法中没找到第一个与 target 相等的元素，且 left = right 这个位置还没有判断
        // --- 这时，判断 left 位置的元素是否等于 target，若等于，则开始位置和结束位置都是 left
        else {
            if(nums[left] == target) {
                res[0] = left;
                res[1] = left;
            }
        }
        return res;
    }
};
```

### 法2，两次二分搜索，直接定位到开始与结束位置

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if(!nums.size()) return res;   // 特判

        // 找开始位置
        int left = 0, mid, right = nums.size() - 1;
        while(left < right) {
            mid = left + (right - left) / 2;
            // 若 mid 值小于 target，则开始位置一定在区间 [mid + 1, right] 内
            if(nums[mid] < target) left = mid + 1;
            // 否则，nums[mid] >= target，开始位置一定在区间 [left, mid] 内
            else right = mid;
        }
        // 在数组中 target 有可能不存在，故开始位置有可能不存在，这里要判断一下
        // 若存在，则赋值给开始位置
        if(nums[left] == target) res[0] = left;
        // 若真不存在，直接返回没找到即可        
        else return res;
        
        // 找结束位置
        left = 0;
        right = nums.size() - 1;
        while(left < right) {
            mid = left + (right - left + 1) / 2;
            // 若 mid 值大于 target，则结束位置一定在区间 [left, mid - 1] 内
            if(nums[mid] > target) right = mid - 1;
            // 否则，nums[mid] <= target，结束位置一定在区间 [mid, right] 内
            else left = mid;
        }
        // 代码跑到这里，说明开始位置存在，那么结束位置一定存在，直接赋值即可
        res[1] = left;

        return res;
    }
};
```