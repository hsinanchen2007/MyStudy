# $O(NK)$

## Brute-force

```cpp
class NumArray {
private:
    vector<int> array;
public:
    NumArray(vector<int>& nums) {
        array = nums;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; k++) {
            sum += array[k];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```
### Complexity
- Time: $O(NK)$
- Space: $O(N)$

# $O(N)$
## Store another array sum[] accordingly

```cpp
class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        sum = nums;
        for (int k = 1; k < nums.size() ; k++) {
            sum[k] = sum[k - 1] + nums[k];
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) {
            return sum[j];
        } else {
            return sum[j] - sum[i - 1];
        }
        return -1;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */


```
### Complexity
- Time: $O(N)$
- Space: $O(N)$