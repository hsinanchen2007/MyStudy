
```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) 
            return false;
	int param = x;
	long rev = 0;
	int pop = 0;
	while (param != 0) {
		pop = param % 10;
		param /= 10;
		rev = rev * 10 + pop;
                if(rev > INT_MAX || rev < INT_MIN){
                    return false;
                }
	}
	return(x == rev);
    }
};
```