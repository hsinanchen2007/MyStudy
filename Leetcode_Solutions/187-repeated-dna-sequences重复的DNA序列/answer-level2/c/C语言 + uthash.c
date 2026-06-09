struct HASH_NODE{  
    char DNA[11];             /* key (string is WITHIN the structure) */  
    int count;  
    UT_hash_handle hh;         /* makes this structure hashable */  
};  
  
char ** findRepeatedDnaSequences(char * s, int* returnSize){
	int i;
	int len = strlen(s);
	struct HASH_NODE *tNode, *p, *q;
	struct HASH_NODE *head = NULL;
	char **retStr;
    
    *returnSize = 0;
	if(s == NULL || len < 10)return NULL;

	tNode = (struct HASH_NODE*)malloc((len-9)*sizeof(struct HASH_NODE));
	
	for(i = 0;i < len-9;i++){ // 步进只是一个字符，性能较差，又是能排除一些场景，性能可能提升一些；
		tNode[i].count = 1;
		strncpy(tNode[i].DNA,&s[i],10);
		tNode[i].DNA[10] = 0;
		HASH_FIND_STR(head,tNode[i].DNA,p);
		if(p == NULL){ // 未出现过，则添加到hash 表中
            p = &tNode[i]; //这行代码未调试时解决一个编译错误而添加
			HASH_ADD_STR(head, DNA, p);
		} else { // 已出现过，计数++
			p->count++;
		}
	}
    // 遍历所有出现超过1次的hash 节点
	HASH_ITER(hh,head,p,q){
		if(p->count > 1){
			*returnSize += 1;
		}
	}

    // 申请返回空间
	retStr = (char**)malloc((*returnSize) * sizeof(char*));
	i = 0;
	HASH_ITER(hh,head,p,q){
		if(p->count > 1){
			retStr[i++] = p->DNA; 
		}
	}	
	// 代码不好的地方，两次malloc都没有释放空间
	return retStr;
}