**滑动窗口**
1. 同样对字符串s设置两个指针left和right，left和right的初始值都设置为0。
2. 然后right指针不断地往后移动，直到找到包含所有t中字符的子串，记下此时的left的位置以及此时子串的长度right-left。（为什么这里的子串长度是right-left呢？主要是因为在进行这个计算之前right先进行了一次自加right++，所以就不是right-left+1了）
3. 当找到符合要求的子串后，因为我们要找的是最小的覆盖子串，因此我们需要压缩我们的子串看是否满足要求。也就是left指针也慢慢的往右移动，然后看此时是否满足包含t中字符的要求，如果不满足就又要开始移动right指针，达到要求后再次进行压缩。
4. 每次满足要求的子串都记录下长度以及left的位置，如果比之前的min_len更小则更新，直到循环完整个字符串。



```
char * minWindow(char * s, char * t){
	int window[128];
	int need[128];
	int len_need = 0;
	int min_len = INT_MAX;
	int start=0;
	int left=0,right=0;
	int match=0;
	
	int len_s = strlen(s);
	int len_t = strlen(t);
	
	memset(window, 0, sizeof(int)*128);
	memset(need, 0, sizeof(int)*128);
	
	int i;
	for(i=0;i<len_t;i++){
		if(need[t[i]]==0){
			len_need+=1;
		}
		need[t[i]]++;
	}
	
	while(right<len_s){
		char s1 = s[right];
		if(need[s1]){
			window[s1]++;
			if(window[s1]==need[s1]){
				match++;
			}
		}
		right++;
		
		while(match==len_need){
			if (min_len>(right-left)){
				start = left;
				min_len = right - left;
				
			}
			
			char s2 = s[left];
			if(need[s2]){
				window[s2]--;
				if (window[s2]<need[s2])
					match--;
				
			}
			left++;
		}
	}
	if(min_len==INT_MAX){
		return "";
	}	
	else{
		s[start+min_len]='\0';
		return s+start;
	}	
}
```
