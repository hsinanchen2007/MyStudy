```cpp
class Solution {
public:
    void sortColors( vector<int> & nums ) {
        int i = 0, j = nums.size() - 1, k = 0;
        while ( k <= j ) {
            if      ( nums[k] == 0 and k > i ) swap( nums[k], nums[i++] );
            else if ( nums[k] == 2 and k < j ) swap( nums[k], nums[j--] );
            else ++k;
        }
    }
};
```
