给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：

```
给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
```
说明:

你可以假设数组不可变。
**会多次调用 sumRange 方法。**

<hr>

##  解：单纯解法

```
class NumArray {
    vector<int> num;
public:
    NumArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            num.push_back(nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        int sum=0;
        for(int k=i;k<=j;k++)
        {
            sum+=num[k];
        }
        return sum;
    }
};
```

##  解法2：由于会多次调用所以应该采用拥有记忆方式的解法
数组num数据表示：第i位数据存放[0...i-1]的和
所以i到j的和可以表示位num[j+1]-num[i]

```
class NumArray {
    vector<int> num;
public:
    NumArray(vector<int>& nums) {
        int sum=0;
        num.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            num.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return num[j+1]-num[i];
    }
};
```

