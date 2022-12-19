### 解题思路
1. 把num转成数组, 对数组排降序.
2. 从左到右对比num和排序后的数组, 如果发现对位数字不同, 说明这个位子需要交换, 并且被交换的数字就是排序数组中该索引的数字.
3. 从后往前寻找该数字, 与当前位子交换后直接返回(同理, 可以拓展成限制k次交换).
4. 否则直接返回原数字.

![1.png](https://pic.leetcode-cn.com/c8ce695e6ea010b6725066061e7b079ae5c9f770d3bb0d463fe2d16841210ba5-1.png)

### 代码

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string str_num = to_string(num);
        vector<int> arr_num;
        for (auto i : str_num) {
            arr_num.push_back(i - '0');
        }
        sort(arr_num.begin(), arr_num.end(), [](int a, int b) {
            return a > b;
        });

        for (int i = 0; i < arr_num.size(); i++) {
            if (arr_num[i] == str_num[i] - '0') continue;
            int target = arr_num[i];
            for (int j = arr_num.size() - 1; j >= 0; j--) {
                if (str_num[j] - '0' == target) {
                    swap(str_num[i], str_num[j]);
                    return atoi(str_num.c_str());
                }
            }
        }

        return num;
    }
};
```