设置 result1 和 result2 和 num[i]   |   result1     result2
        0           0        0      |      0           0    
        0           0        1      |      1           0    
        1           0        0      |      1           0    
        1           0        1      |      0           1    
        0           1        0      |      0           1    
        0           1        1      |      0           0   

总共上面6中状态的来回变换，总之设置两个标志位 result1 和 result2 为了保证出现3次的数字会自相抵消

自己去用位运算组合相关状态，记得用 tmp 暂存 reuslt1 ，因为 result1 修改之后求 result2 还要用到 result1 修改前的值

C++代码如下

```
int singleNumber(vector<int>& nums) {
    int result1 = 0;
    int result2 = 0;
    int tmp = 0;
    for (int i = 0; i < int(nums.size()); i++) {
        tmp = result1;
        result1 = ~result2 & (result1 ^ nums[i]);
        result2 = (tmp & nums[i]) | (~tmp & ~nums[i] & result2);
    }
    return result1;
}
```
![image.png](https://pic.leetcode-cn.com/02c7158e7ec6cc38e2c1e7c94833710ec0c90e5ecbe4b7eae031b45c4b6ecd97-image.png)


