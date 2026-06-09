执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :7 MB, 在所有 C 提交中击败了76.85%的用户
(算法一般，执行用时可能有Bug)

**两重循环，时间复杂度 ≈ O(n^2)**
```
char * countAndSay(int n){
    char mstr[8000] = "1",nstr[8000] = "\0",*pm,*pn;
    
    while(--n){
    	pm = mstr;
		pn = nstr;
    	char ch = mstr[0];
		int count = 1; 
		do{
			pm++;
		    if(*pm == ch) count++;
			else{
				*pn++ = count+'0';
				*pn++ = ch;
				ch = *pm;
				count = 1;
			}
		}while(*pm != '\0');
        
		*pn = '\0';
		strcpy(mstr,nstr);
	}
    pm = mstr;
    return pm;
}
```
