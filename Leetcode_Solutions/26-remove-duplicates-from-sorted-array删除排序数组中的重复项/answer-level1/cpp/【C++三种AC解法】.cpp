#### 方法一：常规交换，遇到重复数据就移到末尾，O(n^2)
```
int removeDuplicates(vector<int>& nums) {
    int ret = nums.size();
    if (ret < 2)
        return ret;
    for (int i = 1; i < ret;) {
        if (nums[i] == nums[i - 1]) {
            for (int j = i; j < ret - 1; ++j) {
                swap(nums[j], nums[j + 1]);
            }
            --ret;
        } else {
            ++i;
        }
    }
    return ret;
}
```
#### 方法二：两次单独for循环，第一次计算长度并标记重复项为x，第二次交换重复项，O(n)
```
int removeDuplicates(vector<int>& nums) {
    int s = nums.size();
    int ret = s;
    if (ret < 2) return ret;
    
    int x = 0;//升序还是降序
    if (nums[0] <= nums[ret - 1]) x = nums[0] - 1;
    else x = nums[0] + 1;

    for (int i = 1, pre = 0; i < s; ++i) {
        if (nums[i] == nums[pre]) {
            --ret;
            nums[i] = x;
        } else {
            pre = i;
        }
    }

    for (int i = 1, xp = -1; i < s; ++i) {
        if (nums[i] != x && xp > 0) {
            swap(nums[i], nums[xp++]);
        } else if (nums[i] == x && nums[i] != nums[i - 1]) {
            xp = i;
        }
    }
    return ret;
}
```
#### 方法三：“双指针”，将rgt处的非重复数据 覆盖到 lft处的重复数据处 O(n)
```
int removeDuplicates(vector<int>& nums) {
    int s = nums.size();
    if (s < 2)
        return s;
    int lft = 0, rgt = 0;
    while(rgt++ < s - 1) {
        if (nums[rgt] != nums[lft]) {
            nums[++lft] = nums[rgt];
        }
    }
    return lft + 1;
}
```
