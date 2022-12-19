### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	vector<int> digits_plusOne(digits);
    	if(digits[digits.size()-1] == 9){
    		int carry_one = 1;
    		size_t ind = digits_plusOne.size() - 1;
    		while(carry_one){
    			digits_plusOne[ind] = (digits_plusOne[ind] + 1) % 10;
    			if(digits_plusOne[ind] || !ind){
    				carry_one = 0;
    			}
    			ind--;
    		}
    		if(!digits_plusOne[0]){
    			vector<int> digits_plusOne_carry = {1};
    			digits_plusOne_carry.insert(digits_plusOne_carry.end(), digits_plusOne.begin(), digits_plusOne.end());
    			return digits_plusOne_carry;
    		}
    	}else{
    		digits_plusOne[digits_plusOne.size()-1]++;
    	}
    	return digits_plusOne;
    }
};
```