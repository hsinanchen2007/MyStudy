```
class Solution {
public:
    string reverseOnlyLetters(string S) {
    
    int l = 0, r = S.size()-1;
	while (l<r)
	{
		//若非字母，继续
		while (!isalpha(S[l]) && l<r)	l++;
		while (!isalpha(S[r]) && l<r)	r--;
		//若是字母，两端交换
		swap(S[r], S[l]);
		l++;
		r--;
	}


	return S;
};```