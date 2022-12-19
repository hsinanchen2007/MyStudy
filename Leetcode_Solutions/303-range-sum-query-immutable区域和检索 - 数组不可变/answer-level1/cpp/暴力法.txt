### 解题思路
直接暴力求解
### 代码

```cpp
class NumArray {
public:
    NumArray(vector<int>& nums):Array(nums) {}
    
    int sumRange(int i, int j);
protected:
    vector<int> Array;
};

int NumArray::sumRange(int i,int j){
    int res=0;
    for(int x=i;x<=j;x++){
        res+=Array[x];
    }

    return res;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```