
# solution 1

首先想到的是暴力的双重循环, 时间复杂度为o(n^2), 不能接受.

# solution 2

接着是对数组进行排序, 排序后从两端开始查找.
初始状态为left=0, right=n-1
num[left]+num[right] , if > target, right--
                     , if < target, left++
                     , if == target, return [left,right]

综合时间复杂度为o(nlogn), 可以接受.

但仔细一想, 这个算法似乎有点问题, 不过先实现了试试看. 没问题, 排序后这样肯定能找到结果的.

看了眼评论区, 这种方法可以叫做首尾递进查找.
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp = nums;
        std::sort(temp.begin(), temp.end());
        int left = 0, right = temp.size() - 1;
        while (left < right) {
            int sum = temp[left] + temp[right];
            if (sum == target) {
                break;
            }
            else if (sum > target) {
                right--;
            }
            else {
                left++;
            }
        }
        vector<int> result;
        vector<int>::iterator it = std::find(nums.begin(), nums.end(), temp[left]);
        int index1 = it - nums.begin();
        result.push_back(index1);
        it = std::find(nums.begin(), nums.end(), temp[right]);
        int index2 = it - nums.begin();
        if (index2 == index1)
            it = std::find(nums.begin() + index2 + 1, nums.end(), temp[right]);
        result.push_back(it - nums.begin());
        return result;
    }
};
```

# solution 3

这是受评论区启发的.
利用hashmap来做.

当确定一个数之后a之后, 他的另一半一定是target-a, 所以可以去查找这个数是否存在, 如果存在就是答案.
那查看是否存在最好的方法就是hashmap.

首先把数组转存到hashmap中去, 那这里有一个问题就是index怎么保存, 有重复数据时又怎么保存.
那我这里考虑在hashmap中不保存index, 只保存出现次数.
```
// solution 3: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> nums_map;
        for (int i = 0; i < nums.size(); ++i) {
            nums_map[nums[i]]++;
        }
        int nums1, nums2;
        for (int i = 0; i < nums.size(); ++i) {
            nums1 = nums[i];
            nums2 = target - nums[i];
            if (nums1 == nums2) {
                if (nums_map[nums2] > 1) break;
            }
            else {
                if (nums_map[nums2] > 0) break;
            }
        }
        
        vector<int> result;
        vector<int>::iterator it = std::find(nums.begin(), nums.end(), nums1);
        int index1 = it - nums.begin();
        result.push_back(index1);
        it = std::find(nums.begin(), nums.end(), nums2);
        int index2 = it - nums.begin();
        if (index2 == index1)
            it = std::find(nums.begin() + index2 + 1, nums.end(), nums2);
        result.push_back(it - nums.begin());
        return result;
    }
};
```

# solution 4

对于上面solution可以进行优化.
很明显的一点, 就是可以在将num转存为hashmap时, 可以一边转存, 一边查找. 这样也不用考虑是否存在相同数字的问题了.
那这时候转存可以保存index了, 随之而来的一个问题就是map中index那一项的默认值不能为0. 解决也很简单, 声明一个包含默认值的struct即可.
```
// solution 4: O(n)
class Solution {
public:
    struct DefaultIndex {
        int index = -1;
    };
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, DefaultIndex> nums_map;
        int i = 0;
        for (; i < nums.size(); ++i) {
            int num2 = target - nums[i];
            if (nums_map[num2].index != -1) { // find it
                break;
            }
            nums_map[nums[i]].index = i;
        }
        vector<int> result = {nums_map[target - nums[i]].index, i};
        return result;
    }
};
```