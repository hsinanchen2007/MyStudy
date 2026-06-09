```
class Solution {
public:
char firstUniqChar(string s) {
    int letter[26]={0};
	for(auto x:s){
		letter[x-'a']++;
	}
	for(auto x:s){
		if(letter[x-'a']==1)return x;
	}
	return ' ';
}
};
```
