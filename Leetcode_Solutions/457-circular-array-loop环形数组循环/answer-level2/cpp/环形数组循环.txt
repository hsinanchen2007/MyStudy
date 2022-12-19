## 问题描述

给定一个含有正整数和负整数的环形数组 nums。 如果某个索引中的数 k 为正数，则向前移动 k 个索引。相反，如果是负数 (-k)，则向后移动 k 个索引。因为数组是环形的，所以可以假设最后一个元素的下一个元素是第一个元素，而第一个元素的前一个元素是最后一个元素。

确定 nums 中是否存在循环（或周期）。循环必须在相同的索引处开始和结束并且循环长度 > 1。此外，一个循环中的所有运动都必须沿着同一方向进行。换句话说，一个循环中不能同时包括向前的运动和向后的运动。

![](https://pic.leetcode-cn.com/f5f081cf75e688c455859e20c2211161400ca83ad08f75de7397d63b2fe73cee.png)

[环形数组循环](https://leetcode-cn.com/problems/circular-array-loop/ "环形数组循环")

## 解决方法

### 双指针

- 定义两个指针，`fast`和`slow`，`fast`指针用来向后移动，`slow`指针用来指向当前循环的首地址

- `fast`从当前`slow`开始，向后移动，同时记录下`fast`走过的位置

	只要当前`fast`指向的位置的值和`slow`指向位置的值符号不同，说明不符合条件，立即`break`
	
	当前`fast`指向的位置和`fast`即将指向的位置索引相同，说明不符合条件，`break`
	
- 只要找到一个循环就返回`true`,否则返回`false`

```cpp
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int slow=0;
        int size=(int)nums.size();
        vector<int>visited(size,0),t(size,0);
        for(;slow<size;slow++){
            visited=t;
            int fast=((slow+nums[slow])%size+size)%size;
            while(!visited[fast]){
                if(nums[fast]*nums[slow]<0)break;//不是同一个方向
                visited[fast]=1;
                fast=((fast+nums[fast])%size+size)%size;
                if(visited[fast] && fast!=((fast+nums[fast])%size+size)%size)return true;
            }

        }
        return false;
    }
};
```

My Site: [https://liyiping.cn](https://liyiping.cn)