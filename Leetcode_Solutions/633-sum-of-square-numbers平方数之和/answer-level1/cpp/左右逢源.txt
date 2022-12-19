## 问题描述
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。

**示例1**:

		输入: 5
		输出: True
		解释: 1 * 1 + 2 * 2 = 5

 

**示例2**:

		输入: 3
		输出: False
		
[平方数之和](https://leetcode-cn.com/problems/sum-of-square-numbers/ "平方数之和")

## 解决方法
### 左右逢源

- 既然是两个数的平方和相加，那么根据三角形两边之和大于第三边，两个数都会比其平方根小

- 双指针，当两数平方小于目标，`left++`

- 两数平方和大于目标，`right--`


```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        int right=sqrt(c);
        //注意题目要求是非负整数，所以也可以是零
        int left=0;
        while(left<=right){
            if(pow(left,2)+pow(right,2)==c)return true;
            else if(pow(left,2)+pow(right,2)<c)left++;
            else if(pow(left,2)+pow(right,2)>c)right--;
        }
        return false;
    }
};
```

个人网站：[liyiping](https://liyiping.cn)