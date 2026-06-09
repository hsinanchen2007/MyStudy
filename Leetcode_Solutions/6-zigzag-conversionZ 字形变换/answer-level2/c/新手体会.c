```
/*这个题我的思路与答案是一致的，但是再具体实现方面，只能说就是新手与老手的差别了吧。
我的理解是分几种情况，首先确定一点就是2*R-2为一个cycle。我的分类如下：
1,在一个cycle内： ·1.1,小于一个R；  ·1.2，R到2*R-2；
2,在多个cycle内： ·2.1,小于一个R；  ·2.2，R到2*R-2；
但是答案直接以行为基数进行讨论，同时在最内层循环以2*R-2+i，2*R-2-i+2*R-2进行区分判断，
这就是差距，细微之处见差别，把看似特殊情况用一般规律表现出来。这也是我需要努力的地方*/
char * convert(char * s, int numRows){
	if(s==NULL) return s;
	if(numRows==1) return s; 
	int len=strlen(s);
	int cyclelen=2*numRows-2;
	char *ret=(char *)calloc(len+1,sizeof(char));
	int  k=0;
	for(int i=0;i<numRows;i++){
		for(int j=0;j+i<len;j+=cyclelen){
			//int k=0;
			ret[k++]=s[i+j];
			if(i!=0&&i!=(numRows-1)&&(j+cyclelen-i)<len) ret[k++]=s[cyclelen+j-i];
		}
	} 
	return ret;
}
```