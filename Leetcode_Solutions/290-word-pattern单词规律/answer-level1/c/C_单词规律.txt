### 解题思路
参照我的题解：
同构字符串https://leetcode-cn.com/problems/isomorphic-strings/solution/c_tong-gou-zi-fu-chuan-by-liu-shuo-7/

本题不同的在于第二个字符串不再代表字符的集合，而是变成了一个字符串的集合。所以要换成字符串版本的“比较第一次出现的位置是否相同”
代码多，因为没用库函数，自己写的链表，但是效率双百，没问题。
![290单词规律.jpg](https://pic.leetcode-cn.com/81ee35eb160b35c8cfc1ec970fa80aa8da5a08663867d57486a0de3a52b6711f-290%E5%8D%95%E8%AF%8D%E8%A7%84%E5%BE%8B.jpg)



### 代码

```c
//-------------------------------针对字符的链表
typedef struct NodeChar {
	char data;
	int firstTime;
	struct NodeChar* next;
}NodeChar;
//新建
NodeChar* newNode(char Data, int FirstTime)
{
	NodeChar* n = (NodeChar*)malloc(sizeof(NodeChar));
	n->data = Data;
	n->firstTime = FirstTime;
	n->next = 0;
	return n;
}
//字符第一次出现的位置
int firstTimeIn(NodeChar* LinkHead, char Data, int Local)
{
	NodeChar* n = LinkHead->next;
	while (n != 0)
		if (n->data == Data)
			return n->firstTime;
		else
			n = n->next;
	n = newNode(Data, Local);
	n->next = LinkHead->next;
	LinkHead->next = n;
	return Local;
}
//释放内存
void freeLink(NodeChar* LinkHead)
{
	while (LinkHead != 0)
	{
		NodeChar* n = LinkHead;
		LinkHead = LinkHead->next;
		free(n);
	}
}

//-------------------------------针对单词的链表
typedef struct NodeStr {
	char* data;
	int firstTime;
	struct NodeStr* next;
}NodeStr;
//新建
NodeStr* newNodeStr(char* Data, int FirstTime)
{
	NodeStr* n = (NodeStr*)malloc(sizeof(NodeStr));
	n->data = Data;
	n->firstTime = FirstTime;
	n->next = 0;
	return n;
}
//判断两个单词是否相同
bool sameStr(char* Str1, char* Str2)
{
	while (*Str1 != '\0'&&*Str2 != '\0')
		if (*Str1 != *Str2)
			return false;
		else
		{
			++Str1;
			++Str2;
		}
	if (*Str1 != '\0' || *Str2 != '\0')
		return false;
	return true;
}
//单词在字符串中第一次出现的位置
int firstTimeInStrs(NodeStr* LinkHead, char* Data, int Local)
{
	NodeStr* n = LinkHead->next;
	while (n != 0)
		if (sameStr(n->data, Data))
			return n->firstTime;
        else
            n=n->next;
	n = newNodeStr(Data, Local);
	n->next = LinkHead->next;
	LinkHead->next = n;
	return Local;
}
//释放链表内存
void freeLinkStr(NodeStr* LinkHead)
{
	while (LinkHead != 0)
	{
		NodeStr* n = LinkHead;
		LinkHead = LinkHead->next;
		free(n);
	}
}

//-------------------------------题解
bool wordPattern(char * c, char * str)
{
    //统计有几个单词
    int strNums=0;
    for(int i=0;str[i]!='\0';++i)
        if(str[i]==' ')
            ++strNums;
    ++strNums;
    //统计有几个字母
    int cNums=0;
    for(int i=0;c[i]!='\0';++i)
        ++cNums;
    //字母和单词数量不同，不匹配。
    if(cNums!=strNums)
        return 0;
    //单词的集合从字符串转换成矩阵形势
    char** strs=(char**)malloc(sizeof(char*)*strNums);
    for(int i=0;i<strNums;++i)
    {
        //单词长度
        int length=0;
        ////因为单词是用空格分隔的，最后一个单词后面是‘\0’
        for(int j=0;str[j]!=' '&&str[j]!='\0';++j)
            ++length;
        //开辟空间
        strs[i]=(char*)malloc(sizeof(char)*(length+1));
        //单词存入
        for(int j=0;j<length;++j)
            strs[i][j]=*(str++);
        //跳过单词中间的空格，str指向下一个单词的一个字母。最后一个单词后面是'\0'，所以不用跳
        if(*str==' ')
            ++str;
        //新单词结尾添加'\0'
        strs[i][length]='\0';
    }
    //建立链表
    NodeChar* LinkOfChar=newNode('\0',-1);
    NodeStr*  LinkOfStr =newNodeStr(0,-1);
    //一种字母对应一种单词，如果相互对应的字母和单词首次出现的位置不同，释放内存，返回false
    for(int i=0;i<cNums;++i)
        if(firstTimeIn(LinkOfChar,c[i],i)!=firstTimeInStrs(LinkOfStr,strs[i],i))
        {
            freeLink(LinkOfChar);
            freeLinkStr(LinkOfStr);
            for(int i=0;i<strNums;++i)
                free(strs[i]);
            free(strs);
            return 0;
        }
    return 1;
}
```