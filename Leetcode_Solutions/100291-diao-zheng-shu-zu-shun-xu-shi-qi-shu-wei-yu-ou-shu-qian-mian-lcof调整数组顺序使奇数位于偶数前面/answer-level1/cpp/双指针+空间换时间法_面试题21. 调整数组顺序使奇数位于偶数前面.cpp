### 解题思路一 双指针 -- 同侧快慢指针
    /*
     * 方法1 同侧指针法
     * 双指针lo为交换指针，cur是遍历指针，
     * 他们从同一侧开始移动，
     * cur指针遍历数据，只有指向奇数时才做交换
     * lo在交换操作前，一直指向偶数左侧的数据
     * 这样保留左侧的偶数，等待右侧cur指向的奇数来交换
     * */
### 代码

```cpp
std::vector<int> exchange(std::vector<int> &nums) {
    // []的处理
    if (nums.empty()) {
        return nums;
    }

    // 双指针lo,cur同侧，指针lo慢，指针cur快
    // 根据两指针的移动差别，对数据进行交换
    int lo = -1, cur = 0;

    while (cur < nums.size()) {
        // 当快指针指向的数据是奇数时
        if (nums[cur] & 1) {
            // 慢指针右移
            ++lo;
            // 将lo和cur指向的数据交换
            // 当前面都是奇数时，lo和cur所指向的数据相同
            // 保证cur指向右侧的奇数(cur指向左侧的偶数无法进入)时，
            // lo能指向左侧的偶数(lo在加1前一直待在左侧偶数的左边等待)
            std::swap(nums[lo], nums[cur]);
        }
        // 当左侧是偶数时，一直右移
        ++cur;
    }

    return nums;
}
```

### 解题思路二 双指针 -- 两侧指针
    /*
     * 方法2 两侧指针法
     * 双指针low为左侧指针，high为右侧指针，
     * 两指针分别从左右两侧开始遍历，
     * 当左侧指针指向奇数时，low指针向右移动，
     * 当右侧指针指向偶数时，high指针向左移动，
     * 当low指向偶数，同时high指向奇数时，进行交换操作
     * */
### 代码

```cpp
std::vector<int> exchange2(std::vector<int> &nums) {
    // []的处理
    if (nums.empty()) {
        return nums;
    }

    // 双指针low,high不同侧，low在左侧，high在右侧
    // 双指针根据条件不断朝中间移动
    int low = 0, high = nums.size() - 1;

    while (low != high) {
        // 当左侧为奇数，low不断向右侧移动
        while (low < high && nums[low] & 1) {
            low++;
        }

        // 当右侧为偶数，high不断向左侧移动
        while (low < high && ~nums[high] & 1) {
            high--;
        }

        // 当两指针不移动时，表明low指向偶数，high指向奇数
        // 此时两指针指向的数据交换
        std::swap(nums[low], nums[high]);
    }

    return nums;
}
```

### 解题思路一 双指针 -- 空间换时间
    /*
     * 方法3 空间换时间
     * 增加数组arr，使用空间换时间
     * 先遍历数组nums将奇数取出存入arr中，
     * 再遍历一遍数据nums将偶数取出存入arr中
     * */
### 代码

```cpp
std::vector<int> exchange3(std::vector<int> &nums) {
    // []的处理
    if (nums.empty()) {
        return nums;
    }

    // WARNing : 不能初始化
    std::vector<int> arr;

    int i = 0;
    // 遍历第一遍，将奇数存在数组左侧
    for (i = 0; i < nums.size(); i++) {
        if ((nums[i] % 2) == 1) {
            arr.push_back(nums[i]);
        }
    }

    // 遍历第二遍，将偶数存在数组右侧
    for (i = 0; i < nums.size(); i++) {
        if ((nums[i] % 2) == 0) {
            arr.push_back(nums[i]);
        }
    }

    return arr;
}
```