### 解题思路
题目和26题不同的地方在于，26题最后只保留1个重复元素，这道题保留2个重复元素。
做这种题目，要求O(1)额外空间，原地修改数组，那么我们必然要使用两个指针。
我们用两个指针的时候，脑海中要有两个数组，虽然他们都是用一份空间。
回忆26题目解法：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/liang-ge-zhi-zhen-by-chengm15/
核心思想是建立两个指针，new_idx表示新数组，old_idx表示旧数组。
一旦出现nums[new_idx] != nums[old_idx]，说明这时新数组中可以插入新的元素。++new_idx;nums[new_idx]=nums[old_idx];
否则++old_idx;
比如[0,0,1,1,1,2],用这个方法走一遍会发现old_idx >= new_idx;
因为一旦出现nums[new_idx] == nums[old_idx]会率先执行++old_idx;

说回这道题，我一开始也采用了相似的解法：
1. 先找出新数组的长度，这个参考函数findNewLen，思想：使用一个滑窗，窗内的元素都相同。然后 new_len += min(2, window_size)，这样可以得到返回值

2. 和26题目方法类似，一旦出现nums[new_idx] != nums[old_idx]。
    - 进行判断，如果nums[new_idx] != nums[new_idx+1]，说明nums[new_idx]只出现了一次，++new_idx; 
        - 接下来判断如果nums[old_idx] == nums[old_idx+1]，那么说明新的元素存在至少2个重复, 那么执行nums[new_idx] = nums[old_idx]; ++old_idx; nums[new_idx+1] = nums[old_idx]; ++old_idx;
        - 否则nums[old_idx]只有一个元素, 那么执行nums[new_idx] = nums[old_idx]; ++old_idx;即可
    - 如果nums[new_idx] == nums[new_idx+1]，说明nums[new_idx]出现了2次，new_idx+=2;
        - 接下来的判断nums[old_idx] == nums[old_idx+1]和上面一样

3. 这样的方法对于大多数情况是ok的，但是无法处理[1,1,1,2,3]
    - 因为按照2中的方法, new_idx = 0, old_idx = 3时，会触发nums[new_idx] != nums[old_idx]。然后按照2的方法，new_idx = 2, old_idx = 4, 数组变为[1,1,2,2,3]。这个时候就会出问题，我们对比输入nums = [1,1,1,2,3], 结果应该是[1,1,2,3]，而现在[1,1,2,2,3], new_idx = 2，那么未处理的部分还有[2,2,3]，返回结果会变成[1,1,2,2]。错误的原因是1.虽然old_idx >= new_idx，但是赋值nums[new_idx] = nums[old_idx]，会影响改变数字的个数，并且这个信息是还没有使用过的。下面的error代码就是用了这种做法，fail在[1,1,1,2,3]

4. 后来将赋值改为swap就可以解决3中的问题。对于[1,1,1,2,3]：
    - 使用赋值:  [1,1,2,2,3] new_idx = 2, old_idx = 4，//下一次循环，nums[new_idx] != nums[new_idx+1]会出错，因为将2的数目改成2个。26题解的方法不会错，是因为不存在判断nums[new_idx] != nums[new_idx+1]，并且new_idx永远是被覆盖。而这道题要使用new_idx+1的信息.
    - 使用swap: [1,1,2,1,3] new_idx = 2, old_idx = 4，可以避免错误，因为元素为某个值的数目永远不变，变的只是位置。

### error代码
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2){
            return nums.size();
        }
        int new_len = findNewLen(nums);
        //cout << "new_len: " << new_len << endl;
        int new_idx = 0, old_idx = nums[0] == nums[1]? 2: 1;
        //whether new_idx/old_idx has repeat element
        while(new_idx < new_len && old_idx < nums.size()){
            int target = nums[new_idx];
            findDiffEleIdx(nums, old_idx, target);
            if(old_idx >= nums.size()){
                return new_len;
            }
            if(new_idx + 1 < new_len && nums[new_idx] == nums[new_idx+1]){
                new_idx += 2;
                if(old_idx+1 < nums.size() && nums[old_idx] == nums[old_idx+1]){
                    nums[new_idx] = nums[old_idx]; ++old_idx;
                    nums[new_idx+1] = nums[old_idx]; ++old_idx;
                }else{
                    nums[new_idx] = nums[old_idx]; ++old_idx;
                }
            }else{
                new_idx += 1;
                if(old_idx+1 < nums.size() && nums[old_idx] == nums[old_idx+1]){
                    nums[new_idx] = nums[old_idx]; ++old_idx;
                    nums[new_idx+1] = nums[old_idx]; ++old_idx;
                }else{
                    nums[new_idx] = nums[old_idx]; ++old_idx;
                }
            }
        }
        return new_len;
    }

    void findDiffEleIdx(vector<int>& nums, int &old_idx, int target){
        //cout << "target: " << target << " start old_idx: " << old_idx;
        while(old_idx < nums.size() && nums[old_idx] == target){
            ++old_idx;
        }
        //cout << " end old_idx: " << old_idx << endl;
        return;
    }

    int findNewLen(vector<int> &nums){
        int new_len = 0;
        int l = 0, r = 0;
        while(r < nums.size()){
            while(r < nums.size() && nums[l] == nums[r]){
                ++r;
            }
            new_len += min(2, r-l);
            l = r;
        }
        return new_len;
    }
};
```


### PASS代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2){
            return nums.size();
        }
        int new_len = findNewLen(nums);
        //cout << "new_len: " << new_len << endl;
        int new_idx = 0, old_idx = nums[0] == nums[1]? 2: 1;
        //whether new_idx/old_idx has repeat element
        while(new_idx < new_len && old_idx < nums.size()){
            int target = nums[new_idx];
            findDiffEleIdx(nums, old_idx, target);
            if(old_idx >= nums.size()){
                return new_len;
            }
            if(new_idx + 1 < new_len && nums[new_idx] == nums[new_idx+1]){
                new_idx += 2;
                if(old_idx+1 < nums.size() && nums[old_idx] == nums[old_idx+1]){
                    swap(nums, new_idx, old_idx); ++old_idx;
                    swap(nums, new_idx+1, old_idx); ++old_idx;
                }else{
                    swap(nums, new_idx, old_idx); ++old_idx;
                }
            }else{
                new_idx += 1;
                if(old_idx+1 < nums.size() && nums[old_idx] == nums[old_idx+1]){
                    swap(nums, new_idx, old_idx); ++old_idx;
                    swap(nums, new_idx+1, old_idx); ++old_idx;
                }else{
                    swap(nums, new_idx, old_idx); ++old_idx;
                }
            }
        }
        return new_len;
    }

    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void findDiffEleIdx(vector<int>& nums, int &old_idx, int target){
        //cout << "target: " << target << " start old_idx: " << old_idx;
        while(old_idx < nums.size() && nums[old_idx] == target){
            ++old_idx;
        }
        //cout << " end old_idx: " << old_idx << endl;
        return;
    }

    int findNewLen(vector<int> &nums){
        int new_len = 0;
        int l = 0, r = 0;
        while(r < nums.size()){
            while(r < nums.size() && nums[l] == nums[r]){
                ++r;
            }
            new_len += min(2, r-l);
            l = r;
        }
        return new_len;
    }
};
```

### 结果
执行用时 : 8 ms , 在所有 C++ 提交中击败了 90.39% 的用户 
内存消耗 : 6.5 MB , 在所有 C++ 提交中击败了 100.00% 的用户