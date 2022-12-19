### 解题思路
递归

### 代码
![image.png](https://pic.leetcode-cn.com/f47f39b2618cf9b8470b86270bb2d75608cecea1d8e2f666684012aa45ce1507-image.png)

```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        if(num==1) return 1;
        if(num%2==0) return numberOfSteps(num/2)+1;
        return numberOfSteps(num-1)+1;
    }
};
```