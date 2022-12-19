```
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        vector<char> inquire;
	    //完成一个26个字符的数组
	    for (char p = 'a';p != 'z';p++)
	    {
	    	inquire.push_back(p);
    	}
    	inquire.push_back('z');
    	long sum_shift = 0;
        	for (int i = shifts.size()-1; i >= 0; i--)
	    {
	    	sum_shift += shifts[i];
	    	int sum_shift_remainder = sum_shift % 26;
	    	int q = S[i] - 'a';
	    	while (sum_shift_remainder)
	    	{
		    	q++;
	    		if (q == 26)
			    	q = 0;
		    	sum_shift_remainder--;
		    }
		    S[i] = inquire[q];
	    }
	    return S;
    }
};
```
