### 思路
1. 与 `std::lower_bound` 一样的功能，**返回第一个大于等于目标值的索引**

2. 左闭右开区间，划分之后的自区间也是左闭右开

3. 所以初始化就感觉写 `for` 循环一样，`int beg = 0;` `int end = nums.size();`

4. 循环的条件和划分的判断都是 < 

5. 划分时，因为左闭右开的区间，`beg` 自然挪到 `mid + 1` ，而 `end` 挪到 `mid` 

6. 这样操作的目的都是把已经判断过的 `mid` 排除在外

7. 返回值无论是 `beg` 还是 `end` 都是一样的，会找到同一个索引

8. 即**第一个大于等于目标值的索引**

9. 最后根据需求来应用，比如这道题需要判断返回的索引是否越界，是否与目标值相等

### 答题
```C++
int lowerbound(vector<int>& nums, int target)
{
    int beg = 0;
    int end = nums.size();
    while (beg < end)
    {
        int mid = beg + (end - beg) / 2;
        if (nums[mid] < target)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return beg;
}

int search(vector<int>& nums, int target) 
{
    int ans = lowerbound(nums, target);
    return (ans == nums.size() || nums[ans] != target) ? -1 : ans;
}
```


### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)