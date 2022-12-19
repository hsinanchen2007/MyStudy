### 解题思路
用的最简单的思路，我们需要的找的数前面的正数一定连续，先用快排将数组排序，然后假设未出现的正整数为n=1,再用一次遍历，从不为0的地方开始找，如果该数不与后面的数相等，则将n加一，否则n不变，继续遍历下一个数，直到找到这个数或者遍历到倒数第二个数，由于循环中的条件要求进行前后数的判断，所以最后一位要单独判断。能使用该方法的原因就是因为在未出现我们所找的数之前的数要不全是不满足大于零条件的数，要不就全是连续的正整数。
![QQ图片20200327190732.png](https://pic.leetcode-cn.com/4211d3b76b062cddf87cd69f6266ede5ca04dc55af6ff708b86635e0a3fc0122-QQ%E5%9B%BE%E7%89%8720200327190732.png)

### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0) return 1;
        sort(nums.begin(),nums.end());
        int n=1;
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]>0){
                if(nums[i]==n&&nums[i+1]!=nums[i]){
                    n++;
                }
                else if(nums[i]==nums[i+1]){
                    continue;
                }
                else
                    break;
                
            }
        }
        if(n==nums[nums.size()-1]) n++;
        return n;
    }
};
```