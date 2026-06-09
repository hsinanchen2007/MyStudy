能满足题目O(1)要求并且我了解一点的就是异或
答案：
```
class Solution {
    public int singleNumber(int[] nums) {
        // 异或
        int a = nums[0];
        for (int i = 1;i<nums.length;i++){
            a =a^nums[i];
        }
        return a;
    }
}
```
# 解析
异或的规则 1^0=0^1=1;0^0=1^1=0;
相同的数异或为0，全部异或运算一遍，最后剩下的值就是只有一个的值
以题目nums={4,1,2,1,2}为例可以计算出来
```
4 = 0100
1 = 0001
2 = 0010
```

