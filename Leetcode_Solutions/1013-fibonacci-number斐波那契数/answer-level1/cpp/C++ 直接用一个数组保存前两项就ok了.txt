执行用时 :0 ms, 在所有C++提交中击败了100.00%的用户
内存消耗 :8 MB, 在所有C++提交中击败了96.68%的用户
```
class Solution {
public:
    int fib(int N) {
	int tmp=0;
	vector<int> nums = {0,1};
	if(N<2) return N;	
	for(int i=2;i<=N;i++){
		tmp = nums[0] + nums[1];
		nums[0] = nums[1];
		nums[1] = tmp;
	}
	return tmp;
    }
};
```