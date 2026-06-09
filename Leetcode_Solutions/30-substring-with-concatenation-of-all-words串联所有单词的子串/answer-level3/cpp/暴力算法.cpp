代码精简,但速度太慢,勉强能过.
```
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> v;
		if(words.size()==0 || words[0].length()==0) return v;
		int len=words[0].length(), win=len*words.size();
		if(s.length()<win) return v;
		unordered_map<string,int> freqs;
		for(int i=words.size(); i--; ++freqs[words[i]]);
		for(int i=0; i+win<=s.length(); ++i){
			auto tmp=freqs;
			bool found=true;
			for(int j=i, k=words.size(); found && k--; j+=len)
				if(0==tmp[s.substr(j,len)]--) found=false;
			if(found) v.push_back(i);
		}
		return v;
	}
};
```
