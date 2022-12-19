```cpp
// 1. sort O(nlogn)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        return nums[nums.size()>>1];
    }   
};


// //2. map O(n) + O(n)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
        
//         unordered_map<int, int> m;
//         for (int v : nums) {
//             m[v]++;
//             if ( m[v]<<1 > nums.size())
//                 return v;
//         }
//         throw invalid_argument("no solution");
//     }   
// };



// //3. 该数字出现都次数总和大于其他所有数字加起来！！！  O(n)
// class Solution {

// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         int result = nums[0];
//         int count = 1;
//         for (int i = 1; i < n; i++) {
//             if (nums[i] == result)
//                 count ++;
//             else if (count == 0) {
//                 result = nums[i];
//                 count = 1;
//             }
//             else
//                 count --;
//         }
//         return result;


//     }
// };




//// 4. partition 做法在 leetcode 上超时  O(n)
// class Solution {
// private:
//     int partition(vector<int> & nums, int l, int r) {
//         int base, i, j;
//         base = nums[l];
//         i = l; j = r;
//         while (i < j) {
//             while (i < j && nums[j] <= base)
//                 j --;
//             while (i < j && nums[i] >= base)
//                 i ++;
//             if (i < j)
//                 swap(nums[i], nums[j]);
//         }
//         swap(nums[l], nums[i]);
//         return i;
//     }

// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         int mid = n >> 1;
//         int start = 0, end = n-1;
//         //partition 返回一个已经处于正确位置上到数到索引，左边都小于这个数，右边都大于这个数
//         int index = partition(nums, 0, n-1);
//         while (index != mid) {
//             if (index > mid){
//                 end = index - 1;
//                 index = partition(nums, start, end);
//             }
//             else {
//                 start = index+1;
//                 index = partition(nums, start, end);
//             }
//         }
//         return nums[index];

//     }
// };
```