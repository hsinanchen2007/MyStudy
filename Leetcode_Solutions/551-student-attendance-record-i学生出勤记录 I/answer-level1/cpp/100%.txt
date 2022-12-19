```cpp
class Solution {
public:
    bool checkRecord(string s) {
		int A_count=0;
		int L_count=1;
		int max_L=INT_MIN;
		s+=' ';
		for(int i=0;i<s.size();++i){
			if(s[i]=='A')++A_count;
			if(s[i]=='L'&&s[i+1]=='L'){
				++L_count;
				max_L=max(max_L,L_count);
			}else{
				L_count=1; 
			}
		}
		return A_count<=1&&max_L<=2;
    }
};
```