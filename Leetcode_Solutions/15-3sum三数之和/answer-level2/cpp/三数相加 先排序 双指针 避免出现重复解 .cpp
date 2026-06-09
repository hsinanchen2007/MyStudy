### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;
            while (front < back) {
                int sum = num[front] + num[back];
                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);
                    //第2个数重复  重复元素：跳过，避免出现重复解
                    while (front < back && num[front] == triplet[1]) front++;
                     //第3个数重复
                    while (front < back && num[back] == triplet[2]) back--;
                }
            }
            // 第1个数重复
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;
        }
        return res;
    }
};
```