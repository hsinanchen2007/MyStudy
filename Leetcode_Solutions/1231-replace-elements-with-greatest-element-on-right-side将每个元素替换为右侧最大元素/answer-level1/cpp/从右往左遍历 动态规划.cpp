### 解题思路
采用动态规划的思路
从右往左遍历数组，用变量 `max` 存储当前右侧最大元素的值（`max` 初始化为-1）
- 当 `arr[i]` 的值 大于 `max` 时，需要将 `arr[i]` 用它右边最大的元素 `max`替换 ，并且 `arr[i]`成为新的最大的值。也就是说，需要交换 arr[i] 和 `max` 的值
- 当 `arr[i]` 的值小于等于 `max` 时，只需要将 `arr[i]` 用它右边最大的元素 `max`替换，`max`仍然是当前最大的值

![截屏2020-01-09下午9.42.30.png](https://pic.leetcode-cn.com/7d7a297411f6aa7ca8023280994e6e3839b218c83418b81f78cff8cf930f83be-%E6%88%AA%E5%B1%8F2020-01-09%E4%B8%8B%E5%8D%889.42.30.png)

### 代码

```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = -1;
        for(int i = arr.size() - 1; i >= 0; --i){
            if(arr[i] > max){
                swap(arr[i], max);
            }else{
                arr[i] = max;
            }
        }
        return arr;
    }
};
```