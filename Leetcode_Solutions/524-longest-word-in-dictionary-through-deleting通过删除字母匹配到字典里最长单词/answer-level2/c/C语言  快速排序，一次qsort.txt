
1.用qsort将字符串长度从大到小，相同长度按照字符串从小到大排序
2.排序好的字典，从前往后找，找到一个字符串，存在于s中，则退出；
int cmpLen(const void *a, const void *b)
{
    char **p1;
    p1 = (char**)a;
    char **p2;
    p2 = (char**)b;

    int  len1, len2;

    len1 = strlen(*p1);
    len2 = strlen(*p2);
	if(len1==len2){
		return strcmp(*p1, *p2);
	}

    return (len2 - len1);
}

int judge(char *s, char* d, int lens, int len)
{
    int j, count = 0;
    int i = 0;

    for (j=0;j<len;j++){
        for(;i<lens;i++){
            if(s[i] == d[j]){
                i++;
                count++;
                break;
            }
        }
    }
    if(count<len){
        return 0;
    }
    return 1;
}

char * findLongestWord(char * s, char ** d, int dSize){
    char *rslt;
    int *len;
    int i, start, val, lens;

	if((dSize == 0)||(s==NULL)||(s[0]==0)||(strlen(s)==0)){
        rslt = (char*)malloc(1);
        rslt[0] = 0;
        return rslt;
    }
    //字典按长度从大到小， z字符串从小到大排序
    qsort(d, dSize, sizeof(char*), cmpLen );

    len = (int*)malloc(sizeof(int)*dSize);
    lens = strlen(s);
    
    //从前往后找到第一个存在于字典中的字符串
    for(i=0; i<dSize; i++){
		len[i] =strlen(d[i]);
        val = judge(s, d[i], lens, len[i]);
        if(val == 1){
            rslt = (char*)malloc(len[i]+1);
            memcpy(rslt, d[i], len[i]+1);
			free(len);
			return rslt;
        }
    }

	rslt = (char*)malloc(1);
    rslt[0] = 0;
    free(len);
	return rslt;   
}
