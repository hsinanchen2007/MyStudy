![image.png](https://pic.leetcode-cn.com/3a8635042f85eeaf7d68d09e7d5fe92f7e66e7f238c4ea99105d8442bbee047a-image.png)
深度优先搜索属于图算法的一种，英文缩写为DFS即Depth First Search.
其过程简要来说是对每一个可能的分支路径深入到不能再深入为止，而且每个节点只能访问一次

DFS没多少体会，刷点题再来补充~

### 解题思路
复制的解题思路
时间复杂度 O(N)，一次遍历s.
调试信息：
 input："13[a2[c]]"
output："accaccaccaccaccaccaccaccaccaccaccaccacc"
print：
创建空栈: S->next = 112
添加数字字符: time = 1
添加数字字符: time = 13
待转化的数字字符: time = 13
转化后的数字: times[0] = 13
新增栈元素: S->next = 144
添加字母字符: S->next = 144, Top(S) = a
添加数字字符: time = 2
待转化的数字字符: time = 2
转化后的数字: times[1] = 2
新增栈元素: S->next = 176
添加字母字符: S->next = 176, Top(S) = c
解码字符重复次数：  2
栈顶字符串: S->next = 144, Top(S) = acc
解码字符重复次数：  13
栈顶字符串: S->next = 112, Top(S) = accaccaccaccaccaccaccaccaccaccaccaccacc

### 代码

```c
typedef struct SNode* PtrToSNode;
struct SNode {
    char* str;
    PtrToSNode next;
};
typedef PtrToSNode Stack;//定义栈结构体
//创建一个空栈
Stack CreateStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->str = NULL;//初始化，栈底置空
    S->next = NULL;
    return S;
}
//添加一个栈元素，入栈
bool Add(Stack S)
{
    PtrToSNode tmp = (PtrToSNode)malloc(sizeof(struct SNode));
    tmp->str = (char*)malloc(3000*sizeof(char));//为字符串申请内存
    memset(tmp->str, '\0', 3000*sizeof(char));
    tmp->next = S->next;//这个插入！！！
//图解： 起始：S->null，插入a: S->a->null,，插入b: S->b->a->null
    S->next = tmp;//S始终指向栈顶
    return true;
}
//判空
bool IsEmpty(Stack S)
{
    return (S->next == NULL);//栈底指向空
}
//top栈顶元素
char* Top(Stack S)
{
    if (IsEmpty(S)) {
        return NULL;
    }
    PtrToSNode topNode = S->next;
    return topNode->str;
}
//出栈
bool Pop(Stack S)
{
    if (IsEmpty(S)) {
        return false;
    }
    PtrToSNode topNode = S->next;
    S->next = topNode->next;//跳过该节点
    topNode->next = NULL;
    free(topNode);//释放
    return true;

}

char * decodeString(char * s){
    int sLen = strlen(s);
    //用来记录倍数关系的,盛放数字字符
    int* times = (int*)malloc(50*sizeof(int));
    memset(times, 0, 50*sizeof(int));
    int timesLen = 0;
    // 用来转换成int
    char* time = (char*)malloc(11*sizeof(char));
    memset(time, '\0', 11*sizeof(char));
    
    Stack S = CreateStack();
    Add(S);
    //printf("创建空栈: S->next = %d\n", S->next);
    for (int i = 0; i < sLen; i++) {
        if (isdigit(s[i])) {
            time[strlen(time)] = s[i];//遇到数字字符则加入time中（可含多位数字，最大11位）
            //printf("添加数字字符: time = %s\n", time);
        }
        else if (s[i] == '[') {
            //printf("待转化的数字字符: time = %s\n", time);
            int count = atoi(time);//遇到‘[’则吧数字字符转化为整型数字
            memset(time, '\0', 11*sizeof(char));//取出后初始化
            times[timesLen] = count;//将整型数放在times中，最多存放50个           
            //printf("转化后的数字: times[%d] = %d\n", timesLen, times[timesLen]);
            timesLen++;
            Add(S);//增加栈
            //printf("新增栈元素: S->next = %d\n", S->next);
        }
        else if (isalpha(s[i])) {
            Top(S)[strlen(Top(S))] = s[i];//Top(S)返回的是str指针，将字母字符顺序放在栈顶的str中
            //printf("添加字母字符: S->next = %d, Top(S) = %s\n", S->next,  Top(S));
        }
        else if (s[i] == ']') {
            char* str = (char*)malloc(3000*sizeof(char));
            memset(str, '\0', 3000*sizeof(char));
            strcpy(str, Top(S)); // 取出栈顶字符串放到str中
            Pop(S);// 清空栈顶元素
            int strcount = times[timesLen - 1];//拿出最近的一个数字
            //printf("解码字符重复次数：  %d\n",strcount);
            times[timesLen - 1] = 0;//拿出后清零
            timesLen--;//个数减一
            for (int i = 0; i < strcount; i++) {
                strcat(Top(S), str);//将str按照重复次数接到此时的栈顶元素后边
            }
            //printf("栈顶字符串: S->next = %d, Top(S) = %s\n", S->next, Top(S));
        }
        // printf("i = %d\n Top(S) = ",i);
        // puts(Top(S));
    }
    return Top(S);
}
```