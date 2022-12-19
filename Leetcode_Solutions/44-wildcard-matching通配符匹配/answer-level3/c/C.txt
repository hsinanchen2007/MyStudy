bool isMatch(char * s, char * p){
    int j=0;
	for(int star=0,i=0, last=0;i<strlen(s);){
		if(j<strlen(p) && (s[i]==p[j] || p[j]=='?')){
			++i;
			++j;}
		else if(j<strlen(p) && p[j]=='*'){
			last=i;
			star=++j;}
		else if(star!=0){
			i=++last;
			j=star;}
		else return 0;
		}
		for(; j<strlen(p)&& p[j]=='*'; ++j);
		return j==strlen(p);
}
改了一下，能在纯C上跑
作者：sunt
链接：https://leetcode-cn.com/problems/wildcard-matching/solution/0-ms-88mb-c-bao-li-by-sunt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
