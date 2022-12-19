### 解法一 摩尔投票法
1. 感觉摩尔投票有点减治的思想，将大的问题逐渐变小：如在`[1,2,1,1]`中找主要元素，根据[摩尔投票](https://leetcode-cn.com/problems/majority-element/solution/tu-jie-mo-er-tou-piao-fa-python-go-by-jalan/)。第一位和第二位不相同，那么相当于会变成在`[1,1]`中寻找主要元素
2. **看代码能懂**

### 解法一 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, major;
        for(int n : nums){
            if(cnt == 0){
                major = n;
                cnt ++;
            }
            else{
                if(major == n) cnt ++;
                else cnt --;
            }
        }
        return major;
    }
};
```

### 解法二 位运算
1. 构造ans使得它是主要元素。
2. 由于主要元素是**数组中多一半**的数，那么这个主要元素的**每位二进制**也是数组每个元素二进制数中多一半的数
3. 统计每位数字的第`i`位二进制，假如第`i`位为`1`比较多，那么将`ans`的第`i`位置为`1`，否则为`0`


### 解法二 代码
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        //统计每位数字的第i位二进制
        for(int i = 0; i < 32; i++){
            int cnt = 0;
            for(int j = 0; j < nums.size(); j++){
                //如果第i位为1
                if(nums[j] & (1 << i)) cnt++;
            }
            //如果所有数字的二进制数中，第i位1比0多
            if(cnt > nums.size() / 2) ans ^= (1 << i);
        }
        return ans;
    }
};
```


### 解法三 分治
[题解](https://leetcode-cn.com/problems/majority-element/solution/fen-zhi-suan-fa-by-user2511z/)

### 解法三 代码
```cpp
class Solution {
public:

    int majority_judge(vector<int>& nums, int num, int left, int right){
        int count = 0;
        for(int i=left;i<=right;i++){
            if(nums[i] == num)
                count ++;
        }
        return count; 
    }

    int helper(vector<int>& nums, int left, int right){
        if(left == right) return nums[left];
        else{
            int mid = (left + right) >> 1;
            int left_majority = helper(nums, left, mid);
            int right_majority = helper(nums, mid+1, right);
            int left_majority_count = majority_judge(nums, left_majority, left, right);
            int right_majority_count = majority_judge(nums, right_majority, left, right);
            return left_majority_count > right_majority_count ? left_majority : right_majority;
        }
    }

    int majorityElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int result = helper(nums, left, right);
        return result;
    }
};
```
