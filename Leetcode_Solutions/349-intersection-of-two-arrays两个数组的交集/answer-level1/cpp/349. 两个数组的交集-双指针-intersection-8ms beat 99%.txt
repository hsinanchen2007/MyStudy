
先排序，nums1 是钥匙，nums2 是门，数字匹配上了，说明配对，加入返回值。

```cpp
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    vector<int> res;
    while (i < nums1.size() && j < nums2.size()) { // nums1 拿自己的钥匙去开 nums2 中的门。
        if (nums1[i] < nums2[j]) {
            ++i;
        } else {
            // if (nums1[i] == nums2[j]) { // 如果下面的 if 写成左边这样，那就是 350 的答案了。
            if (nums1[i] == nums2[j] && (res.empty() || res.back() != nums1[i])) {
                res.push_back(nums1[i++]);
            }
            j++;
        }
    }
    return res;
}
```
