```
// 双指针 
	//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Only Letters.
	//Memory Usage : 8.3 MB, less than 90.91 % of C++ online submissions for Reverse Only Letters.
	string reverseOnlyLetters(string S) {
		int left = 0;
		int right = S.size() - 1;
		while (left < right)
		{
			while (left < right && !isalpha(S[left]))
			{
				++left;
			}
			while (left < right && !isalpha(S[right])) 
			{
				--right;
			}
			if (left < right)
			{
				swap(S[left], S[right]);
				++left;
				--right;
			}
		}
		return S;
	}
```
