
## 思路
用数组num[i]记录每个学生分配的糖果数，首先每个学生分配一个糖果，然后每个分两次遍历：
- 从左向右：如果当前学生评分高于左边，则更新当前学生糖果数：num[i] = num[i-1] + 1，完成一次遍历后，每个评分高的学生都比左边相邻评分低的学生分得更多糖果。
- 从右向左：如果当前学生评分高于右边，为了使当前学生同时比左边评分低的学分也分得更多糖果，所以更新当前学生糖果数为：max(num[i]，num[i+1]+1)

最后遍历num[i]，统计每个学生糖果数。

## 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> num(size, 1);
        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i-1]) {
                num[i] = num[i-1] + 1;
            }
        }
        for (int i = size-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                num[i] = max(num[i], num[i+1] + 1);
            }
        }
        int sum = 0;
        for (int i : num) {
            sum += i;
        }
        return sum;
    }
};
```
