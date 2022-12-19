### 解题思路
2个思路：
1.暴力破解
2.单调栈

1.暴力破解
1）先计算最小值前缀minnums
2）两重遍历：
当nums[j]为最小值时，则j前面没有更小的数，说明不存在i，因此需要continue；
当nums[j]不为最小值时，则j前面一定存在更小的数，说明存在i，因此只需要在后续遍历中找到一个数nums[k]>minnums[j] &&nums[k]<nums[j]

```cpp
class Solution {
public:
    bool find132pattern(vector<int> &nums)
    {
        vector<int> minnums = vector<int>(nums.size(),INT32_MAX);
        int minvalue = INT32_MAX;

        for(int i = 0;i<minnums.size();i++){
            minvalue = min(minvalue,nums[i]);
            minnums[i] = minvalue;
        }

        for(int j = 0;j<nums.size();j++){
            if(nums[j]<=minnums[j]){
                continue;
            }

            for(int k = j+1;k<nums.size();k++){
                if(nums[k]<nums[j] && nums[k]>minnums[j]){
                    return true;
                }
            }
        }

        return false;

    }
};
```

2.单调栈
1）先计算最小值前缀minnums
2）从后向前维持1个单调递减栈，使栈中序列均大于minnums[j]；（minnums从左向右是递减序列，因此从右向左栈中序列会不断弹出）
3）单调递减栈的原因：
栈中所有元素都小于minnums[j]
**nums[j]>栈顶时，直接返回true，只有小于栈顶时，才能入栈，因此一定是单调递减栈**

### 代码

```cpp
class Solution {
public:
    bool find132pattern(vector<int> &nums)
    {
        vector<int> minnums = vector<int>(nums.size(), INT32_MAX);
        deque<int> buff;
        int minvalue = INT32_MAX;

        for (int i = 0; i < minnums.size(); i++) {
            minvalue = min(minvalue, nums[i]);
            minnums[i] = minvalue;
        }

        for (int j = nums.size() - 1; j >= 0; j--) {
            if (nums[j] > minnums[j]) {
                while (!buff.empty() && buff.front() <= minnums[j]) {
                    buff.pop_front();
                }

                if (!buff.empty() && buff.front() < nums[j]) {
                    return true;
                }
            }

            buff.push_front(nums[j]);
        }

        return false;
    }
};
```