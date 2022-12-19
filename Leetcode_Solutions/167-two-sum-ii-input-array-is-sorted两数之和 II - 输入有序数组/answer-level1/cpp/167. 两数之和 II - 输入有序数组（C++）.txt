# 167. 两数之和 II - 输入有序数组
```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		
		for( int i = 0; i < numbers.size()-1; ++i ){
			for( int j = i+1; j < numbers.size(); ++j ){
				if( (numbers[i] + numbers[j]) == target ){
					return { i+1, j+1 };
				}
				if( (numbers[i] + numbers[j]) > target ){
					break;
				}
			}
		}
		return {0,0};
    }
};
```
