```cpp
class Solution {
public:
	bool isYuanyin(char c){
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='O'||c=='U'||c=='I')
			return true;
		return false;
	}
    string toGoatLatin(string S) {
    	int i=0,j=0,k=1;
    	string res="";
    	S+=' ';
		while(i<S.size()&&j<S.size()){
			while(S[++j]!=' ');
			string str=S.substr(i,j-i);
			if(isYuanyin(str[0]))str+="ma";
			else{
				str+=str[0];
				str=str.substr(1,str.size()-1);
				str+="ma";
			}
			for(int x=0;x<k;++x)str+='a';
			res+=str;
			res+=' ';
			++j;
			i=j;
			++k;
		}
		while(res[res.size()-1]==' ')res=res.substr(0,res.size()-1);
		return res;
    }
};
```