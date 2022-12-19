### 解题思路
    /*
     * 排序法
     *
     * 定义一种排序规则，假设对于两个数m和n，如果 mn < nm，则认为m小于n，
     * 相反如果 nm < mn，则认为n < m（这里的小于是人为定义的小于，不是数学意义上的）。
     * 又因为直接拼接数字，可能会使拼接的数字溢出，因此将nums中的数转化为字符串，
     * 在对字符串拼接进行比较: s1 + s2 < s2 + s1。利用该小于的比较规则，
     * 将字符串数组重新排序后，拼接字符串数组中的字符串即可。
     * */
### 代码

```cpp
public:
std::string minNumber(std::vector<int> &nums) {
    if (nums.empty()) {
        return "";
    }

    // 存储数字转化后的字符串
    std::vector<std::string> numStr;
    // 结果字符串
    std::string resStr;

    // 将数组中的数转化为字符串
    for (int num : nums) {
        numStr.push_back(std::to_string(num));
    }

    // 对字符串数组中的字符串按照拼接比较规则进行排序
    std::sort(numStr.begin(), numStr.end(), compare);

    // 拼接最终的字符串结果
    for (std::string s : numStr) {
        resStr += s;
    }

    return resStr;
}

private:
static bool compare(std::string &s1, std::string &s2) {
    // 小于的字符串拼接规则
    return (s1 + s2 < s2 + s1);
}
```