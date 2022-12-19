### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	string addBinary(string a, string b){
		string s_sum;
		if(!a.size() && !b.size()) return s_sum;
		else if(!a.size()) return b;
		else if(!b.size()) return a;

		size_t max_bits = std::max(a.size(), b.size());
		int carry_bit = 0;
		for(size_t i=0;i<max_bits;++i){
			int cur_a_bit = (i > (a.size()-1))? 0 : (a[a.size()-1-i] - '0');
			int cur_b_bit = (i > (b.size()-1))? 0 : (b[b.size()-1-i] - '0');
//			cout << "cur_a_bit = " << cur_a_bit << " cur_b_bit = " << cur_b_bit << endl;
			int sum_bit = (cur_a_bit ^ cur_b_bit ^ carry_bit);
			carry_bit = (cur_a_bit + cur_b_bit + carry_bit) / 2;
//			cout << "{" << carry_bit << ", " << sum_bit << "}" << endl;
			s_sum = to_string(sum_bit) + s_sum;
		}
		s_sum = carry_bit ? (to_string(carry_bit) + s_sum) : s_sum;
		return s_sum;
	}
};
```