### 解题思路
这道题如果没有重复元素，和33题一样
33题解：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/zai-shu-zu-zhong-ren-yi-wei-zhi-kan-yi-dao-yi-ding/

这个卡了我很久，希望可以想出纯粹O(logn)的复杂度的算法，但是发现是不可能的，因为可能会出现A[l] == A[r] == A[mid]的情况，这个时候，你没法二分了。

因此，这道题目一定要配合O(n)的解法去做。这道题和33题的关键区别在于A[mid] == A[r]的情况讨论:
先说左半部分和右半部分的定义: [4,5,6,1,2,3]，[4,5,6]为左半部分，[1,2,3]为右半部分
if(A[mid] > target){
    // 说明我们希望找到数组中更小的数，与target进行对比
    if(A[mid] == A[r]){
        //mid既有可能在左半部分，也有可能在右半部分
        //既然找更小的数，那么无论在左还是右，大多数情况向左遍历
        int i = mid;
        //一旦出现了数值的变化，就立刻跳出，避免过度的遍历
        for(; i >= l; --i){
            if(A[i] == target) return true;
            if(A[i] < A[mid]){ // A[i] < A[mid] = A[r]
                // 如果出现了数值减小，说明mid一定不在左半部分，因为左半部分的最小值都大于等于右半部分的最大值
                r = mid-1; break;
            }
            if(A[i] > A[mid]){
                //向左走应该要减小，但是出现了增大的情况，说明是在锚点处，即A[i] 为最大值, A[mid]为最小值，最小值都比target大，说明不存在
                return false;
            }
        }
        if(l > i) l = mid+1; // 从mid到l，都没有找到target，说明不在左半部分
    }
}
用同样的方法分析A[mid] < target的情况即可。
这道题考验思维深度，算是senior medium!

### 代码

```cpp
class Solution {
public:
    bool search(vector<int>& A, int target) {
        int l = 0, r = A.size() - 1;
        while(l <= r){
            int mid = (l+r)/2;
            //cout << "l: " << l << " r: " << r << " mid: " << mid << endl;
            if(A[mid] == target){
                return true;
            }else if(A[mid] > target){
                if(A[mid] > A[r]){
                    //[l, mid] is sorted
                    if(A[r] < target){
                        r = mid-1;
                    }else if(A[r] == target){
                        return true;
                    }else{
                        //A[r] > target
                        l = mid+1;
                    }
                }else if(A[mid] < A[r]){
                    // [mid, r] is sorted
                    r = mid-1;
                }else{
                    // A[r] == A[mid]
                    int i = mid;
                    for(; i >= l; --i){
                        if(A[i] == target){
                            return true;
                        }
                        if(A[i] > A[mid]){
                            // A[i] is the largest val, A[i+1] is the smallest val
                            return false;
                        }else if(A[i] < A[mid]){
                            // mid must be right half
                            r = mid - 1; break;
                        }
                    }
                    if(l > i) l = mid + 1;// [l, mid] do not have target
                }
            }else{
                //A[mid] < target
                if(A[mid] > A[r]){
                    l = mid+1;
                }else if(A[mid] < A[r]){
                    if(A[r] == target){
                        return true;
                    }else if(A[r] > target){
                        l = mid+1;
                    }else{
                        // A[r] < target;
                        r = mid-1;
                    }
                }else{
                    //A[mid] == A[r]
                    int i = mid;
                    for(; i <= r; ++i){
                        if(A[i] == target){
                            return true;
                        }
                        if(A[i] < A[mid]){
                            // A[i-1] is the largest val and A[i] is the smallest val
                            return false;
                        }else if(A[i] > A[mid]){
                            // mid must be in left half
                            l = mid + 1; break;
                        }
                    }
                    if(r < i) r = mid-1;//[mid,r] do not have target
                }
            }
        }
        return false;
    }
};
```


### 结果
执行用时 : 8 ms , 在所有 C++ 提交中击败了 68.90% 的用户 
内存消耗 : 6.6 MB , 在所有 C++ 提交中击败了 100.00% 的用户