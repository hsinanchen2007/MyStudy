代码来自于评论区，我改进了一点点。同样的代码重复提交，不知道为什么时长从0ms到16ms都出现过。

``` 
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int j=0;
	for(int star=0,i=0, last=0;i<s.length();){
		if(j<p.size() && (s[i]==p[j] || p[j]=='?')){
			++i;
			++j;}
		else if(j<p.size() && p[j]=='*'){
			last=i;
			star=++j;}
		else if(star!=0){
			i=++last;
			j=star;}
		else return 0;
		}
		for(; j<p.size() && p[j]=='*'; ++j);
		return j==p.size();
  }
};
```
