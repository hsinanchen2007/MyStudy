```
class NumArray {
public:
    vector<int> data;
    NumArray(vector<int>& nums) {
        data = nums;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int k=i; k<=j; k++)
        {
            sum += data[k];
        }
        return sum;
    }
};
```
