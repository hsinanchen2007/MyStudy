### 解题思路
这道题的难点在于什么叫做下一个排列？下一个排列在数组上有什么特征？
如果能够回答这句话，那么算法就出来了。
我的思路是从多个case里面去寻找规律。
比如 51342(随便找的一个case)
51342 -> 51423 -> 51432 -> 52134 -> 52143
51342 -> 51423: 51保持不变，变了342
51423 -> 51432: 514保持不变，变了23
51432 -> 52134: 5保持不变，变了1432

(1) 这里需要发现规律，就是从右往左遍历的时候，可以如果发现出现了nums[i] < nums[i+1]
这个从i到最右边的子数组，通过排列可以找到下一个排列
比如51432，当i = 1时，出现 1 < 4，这个时候表示1432通过组合，存在比1432更大的数
那么数组其余的部分不用改变，只针对这个子数组进行调整即可

(2) 根据(1) 可以知道当前子数组的特点是: 除了最左边的元素，从右往左一直增大。
那么这个时候如果要增大子数组的值，那么必须将最左边的元素，替换成子数组中比这个元素大，并且最接近这个元素的元素
随后，除了最左边的元素，将余下的元素从到右按照升序排序，就得到了子数组的下一个排列。
比如51432: 子数组1432, 最接近元素1的为元素2。那么进行替换2341，然后对341进行升序排序。
子数组变为2134，最终结果为52134

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int target_idx = -1, len = nums.size();
        if(nums.size() <= 1) return;
        for(int i = len - 1; i >= 1; --i){
            if(nums[i] > nums[i-1]){
                target_idx = i-1;
                break;
            }
        }
        if(target_idx == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        //cout << "target_idx: " << target_idx << endl;
        findSwapTarget(nums, target_idx);
        sort(nums.begin() + target_idx + 1, nums.end());
    }

    void findSwapTarget(vector<int>& nums, int target_idx){
        int len = nums.size();
        int new_idx = len-1;
        for(int i = target_idx+1; i < len; ++i){
            if(nums[i] > nums[target_idx]){
                new_idx = i;
            }else{
                break;
            }
        }
        int tmp = nums[new_idx];
        nums[new_idx] = nums[target_idx];
        nums[target_idx] = tmp;
    }
};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 87.80% 的用户 
内存消耗 : 6.9 MB , 在所有 C++ 提交中击败了 100.00% 的用户