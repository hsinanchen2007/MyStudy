int lengthOfLongestSubstring(char * s){
    int i,j,k=0,max=0,cnt=0;
    for(i=0;s[i]!='\0';i++){
    	for(j=k;j<i;j++){
    		if(s[i]==s[j]){
    			if(cnt>max)max=cnt;
    			cnt=i-j;
    			k=j+1;
    			break;
			}
		}
		if(j==i)cnt++;
		if(cnt>max)max=cnt;
	}
    return max;
}