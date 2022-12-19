### 解题思路
两种思路，暴力法直接求i到j的和，或者前缀和法利用前j+1的和-前i的和，NumArray函数是为了将输入矩阵进行存储方便调用，sumRange函数可直接调用。注意前缀和法为了使用前j+1的和-前i的和，应输入第一项为0，这样前i项才不包括nums[i]，否则第一项时需要单独写。

### 代码

```cpp []
class NumArray {
public:
    vector<int> num;              //暴力法 直接求i到j的和
    NumArray(vector<int>& nums) {              //两次输入 这一步为了将第一次的输入存储在计算机中
        for(int i=0;i<nums.size();i++)
        {
            num.push_back(nums[i]);
        }
    }
    
    int sumRange(int i, int j) {       //第二次输入 确保在数组已存在在计算机中时调用函数计算
        int sum=0;
        for(int k=i;k<=j;k++)
        {
            sum+=num[k];
        }
        return sum;
    }


    vector<int> num;
    NumArray(vector<int>& nums) {                 //前缀和法 可以直接将和存储成数组
        int sum=0;
        num.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            num.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {           //第i到j则为j+1个-i个（第一个为0，方便（0，0）的求和
        return num[j+1]-num[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```
```python []
class NumArray: 
    def __init__(self, nums: List[int]):
        self.num=[0]
        s=0
        
        for i in range(0,len(nums)):
            s+=nums[i]
            self.num.append(s)

    def sumRange(self, i: int, j: int) -> int:
        return self.num[j+1]-self.num[i]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
```

