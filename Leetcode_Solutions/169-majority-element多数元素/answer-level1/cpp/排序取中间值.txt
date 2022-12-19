### 解题思路
1. 暴力破解法：
遍历然后记录每个num的count，返回最大的即可；
2. 由于题意为包含超过半数以上的值，所以排序后的数组中中间位置一定是所需要的值；
排序然后返回中间值即可

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //暴力破解法即可，使用map存储各个值出现的次数，返回最大即可
    /*    unordered_map <int, int> temp;
        int result = 0;
        int max = 0;
        for(int num : nums) {
            ++temp[num];
            if(temp[num]>max){
                result = num;
                max = temp[num];
            }
        }
        return result;
    */
        sort(nums.begin(),nums.end());
        int len = nums.size();
        return nums[len/2];
    }
};
```