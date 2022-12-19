从前往后扫一遍就行，复杂度O（n）
用一个map数组存放字符在已扫过区域中最后出现的位置，类似于hash的方法，比如'a'最后一次出现的位置就是map['a']或map[97]，查找复杂度为O（1）
如果当前pos减去pos所在字符上一次出现的位置map[s[pos]]，小于等于滑动窗大小nowLen，就说明重复出现了，那么更新一次maxlen
如果没重复，我们知道nowlen还可能继续增加，所以先不着急更新maxlen，但是等全部扫完要记得更新

int lengthOfLongestSubstring(char * s){
	//map record the last appearance position of a word
	int map[128];
	memset(map,-1,sizeof(map));
	int pos=0,maxLen=0,nowLen=0;
	while(s[pos]!='\0'){
		//which means repeated
		if(pos-map[s[pos]]<=nowLen){
			//len stop increasing,record it
			if(nowLen>maxLen)maxLen=nowLen;
            nowLen=pos-map[s[pos]];
		}
		//else just add 1 to nowLen
		else nowLen++;
		//record map
		map[s[pos]]=pos;
		//moving forward
		pos++;
	}
    if(nowLen>maxLen)maxLen=nowLen;
	return maxLen;
}