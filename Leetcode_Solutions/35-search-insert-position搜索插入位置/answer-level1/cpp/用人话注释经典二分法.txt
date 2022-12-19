![image.png](https://pic.leetcode-cn.com/406548448c64b015f8faebe266c8685a52e75a37cdf5933ff5e0478e6b47190e-image.png)

### 解题思路
二分法就是不断缩小可能区间，也就是排除法，把不可能的排除，留下可能的。当可能的区间被排除到长度为1的时候，就可以单独讨论了。
比如说本题最后为什么返回left？为什么不是left-1？为什么不是left+1？说实话最开始我是结合具体例子一个一个讨论的，最后发现不管nums[left]和target什么关系，都是应该返回left。于是得到了比较简洁的代码。
### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        if(target>nums[right]) return right+1;
        if(target<nums[left]) return left;
//还是那句话，能多讨论点就多讨论点。不要为了追求代码简洁华丽，搞得很难懂，或者把自己搞晕，没必要。
        while(left<right){// 注意不要加等号，这样while循环退出的时候就锁定了一个值,nums[left],方便讨论，
// 否则的话就是三个值，还可能会遇到越界等问题，就很烦
            int mid = left+(right-left)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid]<target){// target在右边，让left往右走，否则让right往左走。
                left = mid + 1;
            }else{
                right = mid;// 注意不要写mid-1，写mid就够了，多缩一个不如少缩一个，安全。
            }
        }
        return left;
    }
};
```
（有收获的话，求个赞行吗）