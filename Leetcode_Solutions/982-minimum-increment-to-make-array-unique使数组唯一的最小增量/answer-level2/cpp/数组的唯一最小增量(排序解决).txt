### 解题思路
这里用到的是贪心算法的思想，也就是为了保证次数最少，每次只能增加1，所以只需要排序之后，后一个数只需比前一个数字大1即可，当后一位数字小于前一位数字的时候，需要运用算式做减法，增加到与前一位数字相等再加一

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int len=A.size();
	int count = 0;
	sort(A.begin(),A.end());
	for (int j = 0; j < len-1;j++){
		if (A[j + 1] <= A[j]){
			count = count + A[j] - A[j+1] + 1;
			A[j + 1] = A[j] + 1;
		}
	}
	return count;
    }
};
```