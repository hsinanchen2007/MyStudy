### 解题思路
一轮遍历我想了很久，觉得只有两个指针去做。
回忆之前两个指针的做法，都是有序数组下进行的，因此一直想不通。
直到我突然想到nums[l] < nums[r] 那么只有3种情况 0 < 1, 1 < 2, 0 < 2

于是乎，我就想到全部的情况全部列出来也只有9种，因此我就使用了如下方法。

一旦nums[l]与nums[r] 有一个是2或者0的情况很简答，如果是2，那么一定放到右边，并且--r，同理0一定放到左边

难点在nums[l]与nums[r]都为1，这个时候深入去想，两端都是1
如果中间全都是1，那就可以停了
如果中间有0，那么要和l进行交换，然后l++
如果中间有2，那么要和r进行交换，然后r--
这样就可以保证范围逐步缩小

并且以此遍历就可以完成

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int l = 0, r = nums.size() - 1;
        while(l < r){
            if(nums[l] == 0 && nums[r] == 0){
                ++l;
            }else if(nums[l] == 0 && nums[r] == 1){
                ++l;
            }else if(nums[l] == 0 && nums[r] == 2){
                --r; ++l;
            }else if(nums[l] == 1 && nums[r] == 0){
                swap(nums, l, r); ++l;
            }else if(nums[l] == 1 && nums[r] == 1){
                int k = l+1;
                for(; k < r; ++k){
                    if(nums[k] == 0){
                        swap(nums, l, k);
                        ++l; 
                        break;
                    }else if(nums[k] == 2){
                        swap(nums, k, r);
                        --r;
                        break;
                    }
                }
                if(k >= r) break;
            }else if(nums[l] == 1 && nums[r] == 2){
                --r;
            }else if(nums[l] == 2 && nums[r] == 0){
                swap(nums, l, r); --r; ++l;
            }else if(nums[l] == 2 && nums[r] == 1){
                swap(nums, l, r); --r;
            }else if(nums[l] == 2 && nums[r] == 2){
                --r;
            }
        }
    }

    void swap(vector<int>& nums, int l, int r){
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
    }
};
```

### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 6.5 MB , 在所有 C++ 提交中击败了 100.00% 的用户