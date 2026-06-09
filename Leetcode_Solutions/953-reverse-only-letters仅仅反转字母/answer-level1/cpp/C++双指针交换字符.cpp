### 解题思路
思路：利用双指针思想依次交换元素

### 代码

```cpp
class Solution {
public:
	// 判断是否是字符的方法 
	bool isAlpha(char c) {
		return 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z';
	}
    string reverseOnlyLetters(string S) {
    	// LeetCode的惯例 
        if (S.size() == 0 || S.empty()) return S;
        int left = 0, right = S.size() - 1;
        while (left < right) {
        	// 找不到字符则继续靠拢，等两边都找到了就交换位置 
        	if (!isAlpha(S[left])) {
        		left++;
			} else if (!isAlpha(S[right])) {
				right--;
			} else {
				// 防止重复查找 
				swap(S[left++], S[right--]);
			}
		}
		return S;
    }
};
```