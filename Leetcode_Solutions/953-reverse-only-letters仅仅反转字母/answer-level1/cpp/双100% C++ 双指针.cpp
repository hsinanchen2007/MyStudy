### 解题思路
一个直观的方法是先记录所有 非letter ,然后去除 letter, 反转，再恢复 非letter。
利用双指针，直接在原字符串上操作，返回最终结果。这几天在看快速排序，快排里面也有类似的思想。具体方法为：
1. 初始化双指针，分别指向字符串首尾；
2. 左指针一直后移，直到遇到 letter
3. 右指针一直左移，直到遇到 letter
4. 交换左右指针所指元素，左指针增1，右指针减1
5. 继续步骤2，直到左指针 >= 右指针。

### 代码

```cpp
class Solution {
public:
    string reverseOnlyLetters(string S) {
		int L = S.length(); // 用很多次，直接存着
		int i=0;        // 头指针
		int j=L - 1;	// 尾指针
		while(i < j) {
			while(i<L && not_letter(S[i])) i++;//左指针右移直到letter
			while(j>=0 && not_letter(S[j])) j--;//右指针左移直到letter
			if(i < j) swap(S[i], S[j]); //交换
			++i, --j;
		}
		return S;
    }
    
    bool not_letter(char c) { // c 不是letter ？
    	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    		return false;
    	else
    		return true;
	}
};
```