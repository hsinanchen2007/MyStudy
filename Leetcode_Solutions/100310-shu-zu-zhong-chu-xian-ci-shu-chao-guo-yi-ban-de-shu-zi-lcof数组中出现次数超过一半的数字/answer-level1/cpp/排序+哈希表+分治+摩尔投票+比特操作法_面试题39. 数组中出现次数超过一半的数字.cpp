### 解题思路一 排序法

    /*
     * 方法一 排序法
     *
     * 先将数字排序，再取中间值
     * */

### 代码

```cpp
int majorityElement2(std::vector<int> &nums) {
    assert(nums.size()>0);
    std::sort(nums.begin(), nums.end());

    return nums[nums.size()/2];
}
```

### 解题思路二 哈希表法

    /*
     * 方法二 哈希表法
     *
     * 使用unordered_map实现哈希表映射，
     * 它是C++的STL中的的hash表实现函数
     * */

### 代码

```cpp
int majorityElement(std::vector<int> &nums) {
    assert(nums.size()>0);
    std::unordered_map<int, int> unmap;
    for(auto it : nums){
        unmap[it]++;
        if(unmap[it] > nums.size()/2){
            return it;
        }
    }

    return 0;
}
```

### 解题思路三 分治法
    /*
     * 方法三 分治法
     *
     * 使用经典的分治算法递归求解，直到所有的子问题都是长度为 1 的数组。
     * 由于传输子数组需要额外的时间和空间，
     * 所以我们实际上只传输子区间的左右指针 left 和 right 表示相应区间的左右下标。
     * 长度为 1 的子数组中唯一的数显然是众数，直接返回即可。
     * 如果回溯后某区间的长度大于 1 ，我们必须将左右子区间的值合并。
     * 如果它们的众数相同，那么显然这一段区间的众数是它们相同的值。
     * 否则，我们需要比较两个众数在整个区间内出现的次数来决定该区间的众数。
     * */

### 代码

```cpp
int majority(std::vector<int> &nums, int left, int right) {
    if(left == right){
        return nums[left];
    }

    // 数组中点
    int mid = left + (right - left)/2;
    // 继续划分左边求值
    int leftmaj = majority(nums, left, mid);
    // 继续划分右边求值
    int rightmaj = majority(nums, mid+1, right);

    // 划分到一个数，都相同则返回该数
    if(leftmaj == rightmaj){
        return leftmaj;
    }

    // 计算它们的个数，并返回相应的数
    return std::count(nums.begin()+left, nums.begin()+right+1, leftmaj) > std::count(nums.begin()+1, nums.begin()+right+1, rightmaj) ? leftmaj : rightmaj;
}
```

### 解题思路四 摩尔投票法
    /*
     * 方法四 摩尔投票法
     *
     * 我们假设这样一个场景，在一个游戏中，分了若干个队伍，
     * 有一个队伍的人数超过了半数。所有人的战力都相同，
     * 不同队伍的两个人遇到就是同归于尽，同一个队伍的人遇到当然互不伤害。
     * 这样经过充分时间的游戏后，最后的结果是确定的，
     * 一定是超过半数的那个队伍留在了最后。
     * 而对于这道题，我们只需要利用上边的思想，
     * 把数组的每个数都看做队伍编号，然后模拟游戏过程即可。
     * */
### 代码

```cpp
int majorityElement4(std::vector<int> &nums) {
    assert(!nums.empty());

    // count计入当前队伍剩余人数
    // majority计入当前队伍人数
    int count = 0, majority = 0;
    for(auto num : nums){
        // 当队伍人数为0时，记录下次遇到的队伍号
        if(!count){
            majority = num;
        }

        // 判断是同队伍还是不同队伍
        if(num == majority){
            // 同队伍，队员增加
            count += 1;
        } else{
            // 不同队伍，互相抵消
            count -= 1;
        }
    }

    return majority;
}
```

### 解题思路三 比特操作法

    /*
     * 方法五 比特操作法
     *
     * 5 5 2 1 2 2 2 都写成 2 进制
     * 1 0 1
     * 1 0 1
     * 0 1 0
     * 0 0 1
     * 0 1 0
     * 0 1 0
     * 0 1 0
     *
     * 由于 2 是超过半数的数，它的二进制是 010，
     * 所以对于从右边数第一列一定是 0 超过半数，
     * 从右边数第二列一定是 1 超过半数，
     * 从右边数第三列一定是 0 超过半数。
     * 然后每一列超过半数的 0,1,0 用 10进制表示就是 2 。
     * 所以我们只需要统计每一列超过半数的数，0 或者 1，
     * 然后这些超过半数的二进制位组成一个数字，就是我们要找的数。
     * 可以只统计 1 的个数，让每一位开始默认为 0，
     * 如果发现某一列的 1 的个数超过半数，就将当前位改为 1。
     * */
### 代码

```cpp
int majorityElement5(std::vector<int> &nums) {
    assert(!nums.empty());

    int majority = 0;
    for(unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1){
        int bits = 0;
        for(auto num : nums){
            if(num & mask){
                bits++;
            }
        }
        if(bits > nums.size()/2){
            majority |= mask;
        }
    }
    
    return majority;
}
```