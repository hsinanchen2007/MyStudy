```
class Solution {
public:
    string removeDuplicates(string S) {
        string data = "";
		data.push_back(S[0]);
		for (int i = 1; i < S.size(); i++){
			if (0 != data.size()){
				if (data.back() != S[i]){
					data.push_back(S[i]);
				}
				else{
					data.pop_back();
				}
			}
			else{
				data.push_back(S[i]);
			}

		}
		return data;
    }
};
```
