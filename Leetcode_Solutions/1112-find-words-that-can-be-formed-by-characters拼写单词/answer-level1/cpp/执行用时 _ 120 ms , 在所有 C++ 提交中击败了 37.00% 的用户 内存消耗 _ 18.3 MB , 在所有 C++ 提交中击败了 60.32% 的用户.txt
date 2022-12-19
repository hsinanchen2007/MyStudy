### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
		int len_sum = 0;
		for (auto& word : words) {
			string chars_bak = chars;
			bool is_find = true;
			for (size_t i = 0; i < word.size(); ++i) {
				auto ind = std::find(chars_bak.begin(), chars_bak.end(), word[i]);
				if (ind == chars_bak.end()) {
					is_find = false;
					break;
				}
				chars_bak.erase(ind);
			}
			if (is_find) {
				len_sum += word.size();
			}
		}
		return len_sum;
    }
};
```