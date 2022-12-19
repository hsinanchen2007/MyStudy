用 int letter[26]统计每个字母的个数
```
class Solution {
public:
   string sortString(string s) {
	int letter[26]={0};
    string ans="";
	for(int i=0;i<s.size();i++){
		letter[s[i]-'a']++;
	}
	while(s.size()!=ans.size()){
	for(int i=0;i<26;i++){
		if(letter[i]!=0){
			letter[i]--;
			ans+='a'+i;
		}
	}
	for(int i=25;i>=0;i--){
		if(letter[i]!=0){
			letter[i]--;
			ans+='a'+i;
		}
	}
	}
	
	
	
	return ans;
}
};
```
