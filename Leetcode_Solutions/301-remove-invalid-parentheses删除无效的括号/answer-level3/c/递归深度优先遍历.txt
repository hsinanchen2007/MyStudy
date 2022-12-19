### 解题思路
将连续相同的括号（数量记为N）看作一组，针对每组（包括删除0~N个的情况）递归进行深度优先遍历，过程中记录下符合要求的结果。

### 代码

```c
//#define debug
#ifdef debug
    #define PRINT(fmt,args...) printf(fmt,##args)
#else
    #define PRINT(fmt,args...) 
#endif

typedef struct tagNode{
    char *str;
    struct tagNode *next;
} NODE;

NODE *nodeHead = NULL;
void AllocNodeAndCopyStr(NODE ***nextNode, int *resultNum, char *s, int len)
{
    PRINT("alloc node=%p,*node=%p,resultNum=%d,s=%p,len=%d\n", nextNode, *nextNode, *resultNum, s, len);
    NODE *p = malloc(sizeof(NODE));
    p->str = malloc(len + 1);
    char *str = p->str;
    char *temps;
    for (temps = s; temps < s + len; temps++) {
        if (*temps != '\0') {
            *str = *temps;
            str++;
        }
    }
    *str = '\0';

    p->next = NULL;
    if (*nextNode == NULL) {
        nodeHead = p;
    }
    else {
        **nextNode = p;   
    }
    *nextNode = &(p->next);
    (*resultNum)++;
    PRINT("alloc %d,%s,%p\n",*resultNum,p->str,p);
    return;
}

int calcSameCharNum(char *s, char c) {
    int i = 0;
    while ((*s == c) && (*s != '\0')) {
        i++;
        s++;
    }
    //PRINT("calc %s, %c,%d\n", s,c,i);
    return i;
}

void mark(char *s, char c, int num) {
    //PRINT("mark %s, %c,%d\n", s,c,num);
    int i = 0;
    for (i = 0; i < num; i++) {
        *(s + i) = c;
    }
    //PRINT("mark %s\n", s);
    return ;
}

void doDel(NODE ***nextNode, int *resultNum, char *s, int len, char *nextDelPos, int delLeft, int delRight,
           int nowLeft, int nowRight, int lrMatch) {
    PRINT("doDel nextNode=%p,Num=%d,s=%p,len=%d,nextDelPos=%p,Char=%c,l=%d,r=%d,nl=%d,nr=%d,lr=%d\n", nextNode, *resultNum, s,len, nextDelPos,*nextDelPos, delLeft, delRight, nowLeft, nowRight, lrMatch);

    if ((lrMatch < 0) || (lrMatch > (s + len - nextDelPos))) {
        //PRINT("doDel end=%d\n", -1);
        return;
    }
    if ((nowLeft > delLeft) || (nowRight > delRight)) {
        //PRINT("doDel end=%d\n", -2);
        return;
    }

    if (nextDelPos >= s + len) {
        if ((lrMatch == 0) && (nowLeft == delLeft) && (nowRight == delRight)) {
            AllocNodeAndCopyStr(nextNode, resultNum, s, len);
        }
        //PRINT("doDel end=%d\n", 1);
        return;
    }
    int num;
    if (*nextDelPos == '(') {
        num = calcSameCharNum(nextDelPos, '(');
        //删除i个
        for (int i = 0; i <= num; i++) {
            mark(nextDelPos, '\0', i);
            doDel(nextNode, resultNum, s, len, nextDelPos + num, delLeft, delRight, nowLeft + i, nowRight, lrMatch + num - i);
            mark(nextDelPos, '(', i);
        }
    }
    else if (*nextDelPos == ')') {
        num = calcSameCharNum(nextDelPos, ')');
        //删除i个
        for (int i = 0; i <= num; i++) {
            mark(nextDelPos, '\0', i);
            doDel(nextNode, resultNum, s, len, nextDelPos + num, delLeft, delRight, nowLeft, nowRight + i, lrMatch - (num - i));
            mark(nextDelPos, ')', i);
        }
    }
    else {
        doDel(nextNode, resultNum, s, len, nextDelPos + 1, delLeft, delRight, nowLeft, nowRight, lrMatch);
    }
    //PRINT("doDel end=%d\n", 999);
    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** removeInvalidParentheses(char * s, int* returnSize){
	nodeHead = NULL;
    int len = strlen(s);
	//计算删除数量 
	int delLeft = 0;
	int delRight = 0;
	char *p;
	for (p = s; p < s + len; p++) {
		if (*p == '(') {
			delLeft++;
		}
		else if (*p == ')'){
			if (delLeft <= 0) {
				delRight++;
			} 
			else {
				delLeft--;
			}
		}
	}
	PRINT("l=%d,r=%d,s=%s\n", delLeft, delRight, s);
    NODE **nextNode = NULL;
    *returnSize = 0;
    doDel(&nextNode, returnSize, s, len, s, delLeft, delRight, 0, 0, 0);
    
    PRINT("end...");

    NODE *nodeTemp;
    char **result = (char**)malloc(sizeof(char *) * (*returnSize));
    char **resultTemp = result;
    while(nodeHead != NULL) {
        PRINT("save head=%p,str=%s,next=%p\n",nodeHead,nodeHead->str,nodeHead->next);
        *resultTemp = nodeHead->str;
        nodeTemp = nodeHead->next;
        free(nodeHead);
        nodeHead = nodeTemp;
        resultTemp++;
    }

	return result;
}

```