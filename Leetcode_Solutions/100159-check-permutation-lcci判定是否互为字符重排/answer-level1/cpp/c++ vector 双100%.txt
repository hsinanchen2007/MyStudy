

```
class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		int length1 = s1.length();
		int length2 = s2.length();
		if (length1 !=length2)
		{
			return false;
		}

        vector<char> v1(s1.begin(),s1.end());
        vector<char> v2(s2.begin(),s2.end());
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
		
        for(int i = 0 ; i < v1.size(); i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }

		return true;
	}

};
```
