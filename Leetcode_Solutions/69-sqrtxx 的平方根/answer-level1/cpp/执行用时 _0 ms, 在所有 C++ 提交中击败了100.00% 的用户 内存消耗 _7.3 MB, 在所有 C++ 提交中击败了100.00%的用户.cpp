### 解题思路
此处撰写解题思路
二分查找法
### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
       if(x<2)  //对0,1进行特殊照顾
        return x/1;

int left=1,right=x/2+1;//因为2以上的x的一定小于x/2+1的乘积
while(left<right-1)//保持，left的乘积永远小于x，right的乘积永远大于x，当他俩临近时left即为所求
{
    int mid=(left+right)/2;
    if(x/mid==mid)
        return mid;//如果遇到整除或者比整除多一个不超过mid的x，如9/3==3   11/3===3
    if(x/mid >mid)//保持mid，因为mid可能为解
        left=mid;
    if(x/mid <mid)
        right=mid;
}
    return left;返回左边界
    }
};
```