# 算法一：遍历数组找最小值
```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int ans = numbers[0];
        for (int i = 0; i < n; i++) {
            ans = min(ans,numbers[i]);
        }
        return ans;
    }
};
```
时间复杂度：$O(n)$
空间复杂度：$O(1)$

# 算法二：使用归并排序的思想
```cpp
class Solution {
public:
    int dfs(vector<int>& nums,int left,int right) {
        if (left > right) {
            return INT_MAX;
        }
        if (left == right) {
            return nums[left];
        }
        int mid = left + right >> 1;
        int l = dfs(nums,left,mid);
        int r = dfs(nums,mid + 1,right);
        return (l > r)?r:l;
    }
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        return dfs(numbers,0,n - 1);
    }
};
```
时间复杂度：$O(\log n)$
空间复杂度：$O(1)$