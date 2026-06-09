### 解题思路


### 代码

```cpp
class NumArray {
public: //前缀和很快。。但是动态规划吗、、、、其实前缀和也是一种dp。  dp就是储存中间值
    vector<int>res;
    NumArray(vector<int>& nums) {
        res.assign(nums.size()+1,0); //注意：为res数值分配大小空间
        res[0]=0;//注意：在上面的代码中，我们插入了一个虚拟 0 作为 sum 数组中的第一个元素。这个技巧可以避免在 sumrange 函数中进行额外的条件检查。
        for(int i=1;i<nums.size()+1;i++){
            res[i]=res[i-1]+nums[i-1];  
        }
    }
    int sumRange(int i, int j) {
        return res[j+1]-res[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```