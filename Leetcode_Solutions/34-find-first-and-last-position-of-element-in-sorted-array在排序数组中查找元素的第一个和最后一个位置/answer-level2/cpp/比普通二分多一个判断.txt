### 解题思路
本质上就是多了一个下面的判断，找左端点的时候如下：
            if(nums[mid] == target){
                if(mid == l_bound || nums[mid-1] < target){
                    return mid;
                }else{
                    //nums[mid-1] == target
                    r = mid - 1;
                }
            }
右端点类似，代码见下图

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        vector<int> res = {-1,-1};
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                res[0] = Searchleft(nums, l, mid, target);
                res[1] = SearchRight(nums, mid, r, target);
                return res;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return res;
    }

    int Searchleft(vector<int>& nums, int l, int r, int target){
        int l_bound = l;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                if(mid == l_bound || nums[mid-1] < target){
                    return mid;
                }else{
                    //nums[mid-1] == target
                    r = mid - 1;
                }
            }else if(nums[mid] > target){
                r = mid -1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    int SearchRight(vector<int>& nums, int l, int r, int target){
        int len = r+1;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                if(mid == len-1 || nums[mid+1] > target){
                    return mid;
                }else{
                    //nums[mid+1] == target
                    l = mid + 1;
                }
            }else if(nums[mid] > target){
                r = mid - 1;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
};
```

### 结果
执行用时 : 8 ms , 在所有 C++ 提交中击败了 86.81% 的用户 
内存消耗 : 8.3 MB , 在所有 C++ 提交中击败了 100.00% 的用户