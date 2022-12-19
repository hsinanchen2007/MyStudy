我的想法是数组是按照旋转点升序，那我做一个新的逻辑地址映射到原地址，使得他在数组在逻辑地址上是完全升序的
比如：[4,5,6,7,0,1,2]这么一串数组逻辑地址即是以0这个元素的地址作为起始地址，7元素的地址作为末尾地址



```cpp
int real(int pos, int offset, int size) { // 更具逻辑地址找出真是的地址
    return (pos + offset) % size;
}

int search(vector<int> &nums, int target) {
    // 二分
    const int N = nums.size();
    const int offset = (min_element(nums.begin(), nums.end()) - nums.begin()); 
    int i = 0, j = N - 1;
    // 逻辑上做一个映射, 线性映射
    while (i <= j) {
        int med = (i + j) / 2;
        int real_med = real(med, offset, N);
        if (nums[real_med] < target) {
            i = med + 1;
        } else if (nums[real_med] > target) {
            j = med - 1;
        } else {
            return real_med;
        }
    }
    return -1;
}
```
