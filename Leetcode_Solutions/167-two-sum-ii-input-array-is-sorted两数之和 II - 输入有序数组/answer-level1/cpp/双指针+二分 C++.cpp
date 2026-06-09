解法：
1、使用map，和两数之和1一样
2、二分查找
3、双指针。初始化一个指向头，一个指向尾。夹逼遍历。

```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //二分查找法
        // for (int i = 0; i< numbers.size() - 1; i++) {
            // int index = findIndex(target - numbers[i], numbers, i+1);
            // if (index > 0) {
            //     return {i+1, index+1};
            // }
        // }
        
        //双指针法
        int l = 0;
        int r = numbers.size()-1;
        while(l < r) {
            int n = numbers[l] + numbers[r];
            if (n == target) {
                return {l+1, r+1};
            } else if (n > target) {
                r--;
            } else {
                l++;
            }
        }
        
        
        return {};
    }
    

		//二分查找法
    int findIndex(int num, vector<int>& numbers, int l) {
        int r = numbers.size() - 1;
        while (r != l) {
            int m = (r + l)/2;
            int n = numbers[m];
            if (n == num) {
                return m;
            } else if (n > num) {
                r = m;
            } else {
                l = m+1;
            }
        }
        if (numbers[r] == num) {
            return r;
        } else {
            return -1;
        }
    }
};
```