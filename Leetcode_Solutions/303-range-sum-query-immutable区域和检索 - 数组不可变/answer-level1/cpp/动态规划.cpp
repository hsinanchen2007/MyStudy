执行用时 :40 ms, 在所有 C++ 提交中击败了89.46%的用户
内存消耗 :17.3 MB, 在所有 C++ 提交中击败了36.73%的用户

```
class NumArray {
    
private:
    vector<int> ans;//容纳数组0到索引位置的元素的和
    
public:
    NumArray(vector<int>& nums) {
        
        int temp = 0;
        
        for(auto num : nums){

            ans.push_back(num + temp);
            
            temp += num;
        }
       
    }
    
    int sumRange(int i, int j) {

        if(i==0)
            return ans[j];
        else
            return ans[j] - ans[i-1];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```
