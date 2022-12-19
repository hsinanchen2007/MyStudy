```cpp
class Solution {
public:
    string reverseOnlyLetters(string S) {
		int i=0,j=S.size()-1;
		while(i<j){
			while(!isalpha(S[i])&&i<j)++i;
			while(!isalpha(S[j])&&i<j)--j;
			swap(S[i],S[j]);
			++i;
			--j;
		}
		return S;
    }
};
```