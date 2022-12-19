### 桶思想：
- 定义一排桶 `int arr[101]` , 其中 `arr[i]` 里存放数字 n 出现的次数
- 遍历 `nums`，初始化桶数组 `arr`
- 累加处理桶数组`arr` ， 使得 `arr[i]` 表示比 `i` 小的数字的个数
- 最后遍历 `nums` ，取出对应桶里的结果即可。

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int arr[101];
        memset(arr, 0, sizeof(arr));
        // 初始化计数桶
        for (auto i : nums) {
            arr[i] ++;
        }
        // 累加处理计数桶，使得 arr[i] 表示比 i 小的数字的个数
        int cnt = 0;
        for (int i = 0; i <= 100; i ++) {
            int temp = arr[i];
            arr[i] = cnt;
            cnt += temp;
        }
        vector<int> ret;
        // 遍历 nums，取出对应桶 arr[i] 里的结果即可
        for (int i : nums) {
            ret.push_back(arr[i]);
        }
        return ret;
    }
};
```

### 最后

感谢您的观看！

欢迎大家留言，一起讨论交流。