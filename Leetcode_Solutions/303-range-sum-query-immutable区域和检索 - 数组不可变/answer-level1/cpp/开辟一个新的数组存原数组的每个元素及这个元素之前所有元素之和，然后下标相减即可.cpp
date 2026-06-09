```
class NumArray {
private:
    vector<int> numset={0};
public:
    NumArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            numset.push_back(nums[i]+numset[i]);
        }
    }
    int sumRange(int i, int j) {
        return numset[j+1]-numset[i];
    }
};

/*
0 -2 -2 1 -4 -2 -3
 * Your NumArray object will be instantiated and called as such:实例化
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```
