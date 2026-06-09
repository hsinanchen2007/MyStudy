## vector或deque的pop_back()并不真正从容器中移走元素，那是出于性能的考虑，因为有可能pop_back()后又立即push_back。
## 且容器类在实现的时候增长空间一般都留有余量，这样就不会push_back的时候反复new。
## 理论上这种方法是不可取的，因为这样的操作涉及到了违法访问内存，但是作为一种耍赖皮的解法还是很有意思的。
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size() -1;
        while(k > 0)
        {
            nums.pop_back();
            nums.insert(nums.begin() ,nums[n]);
            k--;
        }
    }
};
```
