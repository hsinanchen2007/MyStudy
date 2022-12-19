***Talk is cheap. Show me the code.***
```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	size = nums.size();
    	results.reserve(factorial(size));    // 优化
    	result.resize(size);    // 优化
    	vector<bool> selected(size, false);
    	backtrack(0, selected, nums);
    	return results;
    }

// round：表示进行到第几轮，一共进行 size 轮选择
// selected：已选择的数字标记为 true，nums 和 selected 用下标关联
    void backtrack(int round, vector<bool> selected, const vector<int> &nums) {
    	if (round == size) {
    		results.push_back(result);
    		return;
    	}
    	for (int i = 0; i < size; i++) {
    		if (!selected[i]) {
    			selected[i] = true;
    			result[round] = nums[i];
    			backtrack(round+1, selected, nums);
    			selected[i] = false;    // 该 round 不选择这个数，要标记为没有选择
    		}
    	}
    }

    long factorial(int n) {
    	int res = 1;
    	while (n > 1) {
    		res *= n--;
    	}
    	return res;
    }

private:
	int size;
	vector<int> result;
	vector<vector<int>> results;
};
```
中规中矩，回溯模板👌