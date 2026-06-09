### 解题思路
典型的栈的应用：顺序+大小；
i < j < k -> a[i] < a[k] < a[j]，由此如果按照中间的j的index进行遍历，需要知道前面尽可能小的值，而这个值只需要一个数组来保存就行，代表小于该index前面的最小；而后面的值不是最大，也不是最小，需要将所有信息存储；但是如果遍历j的index，如果能保证后面序列随时都可以取到里面的最小值（如果里面最小值都大于a[j]，说明a[j]不合理；）；如果该值小于a[j-1]及其前面所有的值，那它也没有必要继续保存了，直接pop掉就可以解决问题；
求**最值+大小关系** 并不需要保存里面的所有信息

### 代码

```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums)
{
    if (nums.size() < 3) {
        return false;
    }
    vector<int> preMin(nums.size(), 0);
    preMin[1] = nums[0];
    for (int i = 2; i < nums.size(); i++) {
        preMin[i] = min (preMin[i - 1], nums[i - 1]);
    }
    stack<int> postMinFirst;
    for (int i = nums.size() - 1; i > 0; i--) {
        if (postMinFirst.size() == 0) {
            postMinFirst.push(nums[i]);
            continue;
        }
        while (postMinFirst.size() != 0 && nums[i] > postMinFirst.top()) {
            int postMin = postMinFirst.top();
            if (postMin > preMin[i]) {
                return true;
            }
            postMinFirst.pop();
        }
        postMinFirst.push(nums[i]);
    }
    return false;
}
};
```