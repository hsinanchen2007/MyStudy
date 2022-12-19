### 解题思路
8ms战胜了96.45%的用户,从首尾向中间查找，需要排序,但由于c++无法直接记录索引的排序,所以这里还排序了2次,如果有更好的记录排序索引的方式欢迎交流
### 代码

```cpp
class Solution {
public:
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> sortNums(nums);
    sort(sortNums.begin(), sortNums.end(), [](int x1, int x2) -> bool {
        return x1 < x2;
    }); // 对数组进行排序
    //记录下排序号的索引
    vector<int> idx(nums.size());
    for (int i = 0; i != idx.size(); ++i)
        idx[i] = i;
    sort(idx.begin(), idx.end(),
         [&nums](int i1, int i2) { return nums[i1] < nums[i2]; });

    int head = 0;
    int tail = sortNums.size() - 1;
    int flag = 0; //定义结果变量
    vector<int> result;

    while (flag == 0 && head != tail)
    {
        if (sortNums[head] + sortNums[tail] == target)
        {
            flag++;
        }

        if (sortNums[head] + sortNums[tail] > target)
            tail--;

        if (sortNums[head] + sortNums[tail] < target)
        {
            head++;
            tail < sortNums.size() - 1 ? tail++ : sortNums.size() - 1;
        }
    }

    if (head == tail)
    {
        result.push_back(-1); //未能找到
    }
    else
    {
        head = idx[head];
        tail = idx[tail];
        result.push_back(head);
        result.push_back(tail);
    }
    return result;
}
};
```