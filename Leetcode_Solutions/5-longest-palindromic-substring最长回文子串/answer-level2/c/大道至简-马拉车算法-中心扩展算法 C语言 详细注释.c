```
#define min(a,b) ((a)<(b)?(a):(b))

char * longestPalindrome(char * s){

int len=strlen(s);
int str_len=2*len+1;//构造新数组的长度，例如"abc"--->"# a # b # c #"

char *src=malloc(sizeof(char)*str_len);
char *dst=malloc(sizeof(char)*(len+1));
int *radius=malloc(sizeof(int)*str_len);//放置数组中元素的回文半径
//构造新数组,预处理，变成奇数个
int i;
for(i=0;i<len;i++)
{
    src[2*i]='#';
    src[2*i+1]=s[i];
}
src[str_len-1]='#';

int border=0,max_len=0,start=0,axis=0;//右边界，最大回文半径，最大回文对称轴
radius[0]=1;
for(int i=1;i<str_len;i++)
{
    radius[i]=i<border?min(radius[2*axis-i],border-i):1;//判断数组下标i值是否位于右边界左边
    while(i-radius[i]>=0&&i+radius[i]<str_len&&src[i-radius[i]]==src[i+radius[i]])
       radius[i]++;//更新回文半径
    if(i+radius[i]-1>border)//更新右边界
    {
        border=i+radius[i]-1;
        axis=i;
    }
    if(radius[i]-1>max_len)//更新最长回文半径
    {
        max_len=radius[i]-1;
        start=(i-max_len)/2;//起始点
    }
}

for(i=0;i<max_len;i++)//输出最长回文子串
    dst[i]=s[start+i];
dst[max_len]='\0';

free (src);
free (radius);
return dst;
}
```
```
#define max(a,b) ((a)>(b)?(a):(b))

int expandAroundCenter(char* s, int left, int right,int len)
{
	int L = left, R = right;
	while (L >= 0 && R < len && s[L] == s[R])
	{
        // 计算以left和right为中心的回文串长度
		L--;
		R++;
	}
	return R - L - 1;
}

char * longestPalindrome(char * s){

int len=strlen(s);
if(len<1) return "";

int start=0,end=0;
for(int i=0;i<len;i++)
{
    int diam1=expandAroundCenter(s, i, i,len);//一个元素为中心
	int diam2= expandAroundCenter(s, i, i + 1,len);//两个元素为中心
    int max_diam=max(diam1,diam2);//最大回文长度，即直径

    if(max_diam>end-start)
    {
        start=i-(max_diam-1)/2;
        end=i+max_diam/2;
    }
}
char* res=malloc(sizeof(char)*(end-start+2));
strncpy(res, s + start, end - start + 1);
res[end - start + 1] = '\0';
return res;
}
```
