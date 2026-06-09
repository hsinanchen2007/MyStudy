### 解题思路
1.切割空格产生单词，可参考434.字符串"单词数"，也就是strseq函数
2.统计两个字符串中单词出现次数为1次的单词，使用hash表解决
3.解决hash冲突（菜鸡，链表法）

### 代码
也是参考字符串作为hash键的设计方法，多项式相乘，选的质数31(不知道，搬运工)。然后用链表解决冲突问题
因为本题测试用例不多，手写hash考虑下冲突一般解决办法就行。
```c
struct hash{
	char *key;  // 单词键 
	int value;  // 单词出现次数
	struct hash *next;  // 冲突解决 
};

void addKey(struct hash **table,char *s,int *words,int start,int end){
	char *tmp=NULL;
	struct hash *p=NULL;
	unsigned int sum=0,k;
	tmp=(char*)calloc(end-start+1,sizeof(char));  // i-start=len+\0
	// 秦九算法
	for(k=0;start<end;start++){
		sum = (sum<<5)-sum+s[start]-97;  // 哈希计算
		tmp[k++]=s[start];  // 拷贝 
	}
	sum&=255;  // 得到哈希值,即桶中存储位置

	struct hash *q=table[sum];  // 查询结果先存q内
	p=q;  // q头结点保存 
	while(p){
		if(strcmp(p->key,tmp)==0) break;  // 找到相同 
		p=p->next;  // next后移
	}
	if(p) p->value++;  // 存在一定是相同 
	else{  // 不存在:1.空桶位 2.冲突至最后
		*words+=1;  // 单词总数+1(都是没找到情况) 
		p=(struct hash*)malloc(sizeof(struct hash));  // hash指针
		p->key=tmp;
		p->value=1;
		table[sum]=p;
		p->next=q;  // 更换头结点指向
	}
}

void strseq(struct hash **table,char *s,int *words){  // 计算单词长度
	int start=0,i;
	for(i=0;*(s+i)!='\0';i++){
		if((i==0||*(s+i-1)==' ')&&*(s+i)!=' ') start=i;
		else if(i>0&&*(s+i-1)!=' '&&*(s+i)==' ')
			addKey(table,s,words,start,i);
	}
	if(*(s+i-1)!=' ') addKey(table,s,words,start,i);  // 最后再计算一次，防止"etj" 
}

char ** uncommonFromSentences(char * A, char * B, int* returnSize){
	int words=0,i;  // hash表
	struct hash *table[256];  // 初始化256个字符指针数组
	for(i=0;i<256;i++) table[i]=NULL;  // 初始化NULL
	strseq(table,A,&words);
	strseq(table,B,&words);
	char **res=(char**)malloc(sizeof(char*)*words);  // 最多单词数长度
	for(i=0,*returnSize=0;i<256;i++){  // returnSize初始化为0
		while(table[i]){
			if(table[i]->value==1) res[(*returnSize)++]=table[i]->key;
			table[i]=table[i]->next;  // 遍历链表 
		}
	}
	return res;
}
```

##有uthash.h，用不着手写
```c []
struct hash{
    char *key;
    int value;
    UT_hash_handle hh;
};

void addKey(struct hash **table, char *s, int *words){
    char *seq,*cpy=strdup(s);  // 存word单词
    struct hash *p=NULL;
    while((seq=strsep(&cpy, " "))!=NULL){
        HASH_FIND_STR(*table, seq, p);
        if(!p){
            p=(struct hash*)malloc(sizeof(struct hash));
            p->key=seq;
            p->value=1;
            HASH_ADD_KEYPTR(hh,*table,p->key,strlen(p->key),p);
        }else p->value++;
        *words += 1;
    }
}

char ** uncommonFromSentences(char * A, char * B, int* returnSize){
    struct hash *table=NULL,*p=NULL,*q=NULL;  // 哈希表与变量
    int words=0;  // 单词总数(好申请返回单词数)
    addKey(&table,A,&words);  // 注意传地址！
    addKey(&table,B,&words);
    char **res=(char**)malloc(sizeof(char*)*words);
    *returnSize=0;  // 置0重要！
    for(p=table;p!=NULL;p=p->hh.next){
        if(p->value==1) res[(*returnSize)++]=p->key;
    }
    return res;
}
```
```python []
class Solution(object):
    def uncommonFromSentences(self, A, B):
		from collections import Counter
		count = collections.Counter(A.split()) + collections.Counter(B.split())
		return [word for word in count if count[word] == 1]
```
