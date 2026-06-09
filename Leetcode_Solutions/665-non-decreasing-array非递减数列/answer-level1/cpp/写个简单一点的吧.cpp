
代码比较简单，但在草稿纸上还是要做些 归纳处理，分类讨论的，只是最后做了点化简工作，严格来说还是需要逻辑上的证明的

```c++
    // 逐个遍历，假设发现逆序对 a,b (a > b)
    // 那么 先考虑调整a , 设 a 之前的数字为 prev
    // if prev > b 说明调 a行不通， 如果 prev <= b 说明 a可以调整为prev, 这样可以保持 非递减（到b为止）
    // prev > b的情况下， b 直接调整为 a， 那么 到b为止， 非递减
    // 还不能返回true, 比如 3 4 2 3， 2调整为4 后，还有逆序，不过不需要再加逻辑了，直接 递增 i， 按同样逻辑处理即可
    // 假设题目 说 可以改变 n个，也能用这种方法处理?
	bool checkPossibility(vector<int>& nums) {
		int cnt = 0;
		
		int prev = INT_MIN;
		for(int i = 0; i < nums.size()-1; i++) {
			if(nums[i] > nums[i+1]) {
				cnt++;
				if(cnt >= 2) {
					return false;
				}				
				if(prev <= nums[i+1]) {
					nums[i] = prev;					
				} else {
					nums[i+1] = nums[i];
				}
			}
			prev = nums[i];
		}
		
		return true;
    }
```
