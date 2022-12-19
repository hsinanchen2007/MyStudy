双指针法

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)
            return 0;
        int count = 0;
        int left = 0;
        int right = 2;
        while (right < A.size()) {
            if (A[right] - A[right - 1] == A[left + 1] - A[left])
		count += right - left - 1;
	    else
		left = right - 1;
	    ++right;
	}
	return count;
    }
};
```