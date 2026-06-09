### 解题思路
    /*
     * 桶排序
     *
     * 本题要求O(n)的时间复杂度和O(1)的空间复杂度，
     * 与41题相同可以使用交换数据的桶排序解决，
     * 因为1<= a[i] <= n，所以满足不用任何额外空间，
     * 所以遍历原数组时，当数值与索引不对应时，
     * 就交换该值与该值对应索引存储的值，
     * 数组重排完毕后，再遍历一次，返回不在对应索引上的数
     * */
### 代码

```cpp
std::vector<int> findDuplicates(std::vector<int> &nums) {
    if(nums.empty()){
        return {};
    }

    std::vector<int> res;
    int m = nums.size();

    // 将与索引不对应的值交换
    for(int i = 0; i < m; i++){
        while (i != nums[i]-1 && nums[i] != nums[nums[i] - 1]){
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for(int i = 0; i < m; i++){
        // 将与索引不对应的值返回
        if(i != nums[i] - 1){
            res.push_back(nums[i]);
        }
    }

    return res;
}
```