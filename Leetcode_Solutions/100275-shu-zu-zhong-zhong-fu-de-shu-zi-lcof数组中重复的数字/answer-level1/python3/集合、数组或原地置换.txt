第一种方法：用集合
```python3 []
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        S = set()
        for n in nums:
            if n in S:
                return n
            S.add(n)
```
```cpp []
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set <int> S;
        for (auto i: nums) {
            if (!S.insert(i).second) {
                return i;
            }
        }
        return -1;
    }
};
```
```java []
class Solution {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> S = new HashSet<Integer>();
        for (int n: nums) {
            if (!S.add(n)) {
                return n;
            }
        }
        return -1;
    }
}
```

第二种方法：用数组标记
```python3 []
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        L = [False] * len(nums)
        for n in nums:
            if L[n]:
                return n
            L[n] = True
```
```c []
int findRepeatNumber(int* nums, int numsSize){
    bool *hash = (bool *) malloc(numsSize * sizeof(bool));
    memset(hash, 0, numsSize * sizeof(bool));
    for (int i = 0; i < numsSize; i++) {
        if (1 == hash[nums[i]]++) {
            return nums[i];
        }
    }
    return -1;
}
```
```cpp []
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector <bool> V(nums.size());
        for (auto n: nums) {
            if (V[n]) {
                return n;
            }
            V[n] = 1;
        }
        return -1;
    }
};
```

第三种方法：原地置换
```python3 []
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            while i != nums[i]:
                if nums[i] == nums[nums[i]]:
                    return nums[i]
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
```
```c []
int findRepeatNumber(int* nums, int numsSize){
    int n;
    for (int i = 0; i < numsSize; i++) {
        while (i != nums[i]) {
            n = nums[i];
            if (n == nums[n]) {
                return n;
            }
            nums[i] = nums[n];
            nums[n] = n;
        }
    }
    return -1;
}
```
```cpp []
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (i != nums[i]) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};
```
