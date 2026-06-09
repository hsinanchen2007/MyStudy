详解在代码里,第一次写C++题解,有不足的地方希望大家提出来~
```
class Solution {
public:
    int findBestValue(vector<int> &arr, int target) {

        sort(arr.begin(), arr.end()); //将数组排序,以便创造前缀和数组 查找对应index
        vector<int> prefixArray = vector<int>(arr.size()); // 前缀和数组
        prefixArray[0] = arr[0];

        int right = arr[0];//二分最大值
        int left = 0;//二分最小值

        for (int i = 1; i < arr.size(); i++) {
            right = max(right, arr[i]);
            prefixArray[i] = prefixArray[i - 1] + arr[i];
        }

        int sum = INT_MAX; //当前最接近target数组和
        int value = INT_MAX;
        while (right >= left) {
            int mid = (right + left) >> 1;
            int index = findIndex(arr, mid); // 查找坐标
            int tmpSum = 0;
            if (index == -1) {
                tmpSum = arr.size() * mid;
            } else {
                tmpSum = prefixArray[index] + (arr.size() - 1 - index) * mid;
            }

            // 若当前value与target差值更小, 更新sum和value
            if (abs(tmpSum - target) <= abs(sum - target)) {
                if (abs(tmpSum - target) == abs(sum - target)) {
                    value = min(mid, value);
                } else {
                    value = mid;
                }
                sum = tmpSum;
            }
            // 进行二分
            if (tmpSum - target > 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return value;
    }

    /**
     * 查找存在于数组的,
     * 当前恰好大于等于当前value的,
     * 前一个数字坐标.
     * 例如 [1,2,4] 3 => 1
     * 更新后数组和 = 前缀和[index] + ( 数组长度 - 1 - index ) * value
     * index == -1 时,数组和正好为 数组长度*value
     */
    int findIndex(vector<int> &arr, int t) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= t) {
                return i - 1;
            }
        }
        return 0;
    }
};
```
