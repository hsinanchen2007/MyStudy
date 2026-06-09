class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        vector<int> vecMap(128, 0); 
 		for (int i = 0; i<s.size(); i++)
 		{
 			vecMap[s[i]]++;
		}

		int count = 0;
		for (int i=0; i<128; i++)
	    {
	    	if (vecMap[i] != 0 && count <= 1)
			count += vecMap[i] % 2;
		}
        
        return count <= 1;
      
    }
};