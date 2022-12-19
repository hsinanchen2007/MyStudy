### 解题思路 双指针法
    /*
     * 双指针法
     *
     * 设置双指针small,big，分别初始化指向1和2,它们都是向右侧移动。
     * 因为是连续有序序列的和为target，即small与big之间数字的临时和，
     * 如果临时和大于target，就将small右移，将临时和减去之前的small值，
     * 继续与target比较，如果仍然大于target，则small继续右移，临时和继续减small值；
     * 如果临时和小于target，就将big右移，将临时和增加更新后的big值，
     * 继续与target比较，如果仍然小于target，则big继续右移，临时和继续加big值，
     * 直到(small, big)之间的临时和等于target，则将该段数字组合为数组存储起来，
     * 在small小于mid的情况下，big继续右移，继续上面的步骤，
     * 直到找到所有的和等于target的子数组(因为到mid后面两个数的和一定大于target)。
     * */
### 代码
```cpp
std::vector<std::vector<int>> findContinuousSequence(int target) {
    if(target < 3){
        return {};
    }

    std::vector<std::vector<int>> ans;
    std::vector<int> temp;

    // 初始化两指针分别为1和2
    int small = 1, big = 2;
    // 当前临时和为3
    int tempSum = small + big;

    // 循环终止条件
    int mid = (1 + target) / 2;

    // small小于mid时，遍历继续
    while (small < mid){
        // 临时和等于target
        if(tempSum == target){
            // 将(small, big)之间的数字组合为子数组
            temp = subSequence(small, big);
            ans.push_back(temp);

            // 当找到前面的子数组后，
            // 增加big，继续查询后面的数组
            big++;
            tempSum += big;
        }else if(tempSum > target){
            // 如果临时和大于target则small右移，
            // 同时减去旧的small值
            tempSum -= small;
            small++;
        }else{
            // 如果临时和小于target则big右移，
            // 同时加上更新后的big的值
            big++;
            tempSum += big;
        }
    }

    return ans;
}

    // 将一段数字组合为数组
std::vector<int> subSequence(int small, int big) {
    std::vector<int> temp;
    for(int i = small; i <= big; i++){
        temp.push_back(i);
    }

    return temp;
}
```