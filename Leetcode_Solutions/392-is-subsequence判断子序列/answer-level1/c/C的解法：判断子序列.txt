
### 解题思路
方法一：
思路：循环t的每一个字符去和s的字符匹配，如果成功（第一次），记录此字符在t的坐标t_pos,在s中的坐标j
	  之后，在以上的基础上，再让t的字符和s的字符匹配。如果所有s的字符都能匹配成功，返回true。
	  否则，让t遍历的坐标i=t_pos+1，让s已经匹配上的坐标j=0。再从头开始执行以上操作，直至函数结束。
### 代码
```c
bool isSubsequence(char * s, char * t){
    int s_size=strlen(s);
    if(s_size==0)return true;
    int t_size=strlen(t);
    int t_pos=0; 
    int flag=0;
    for(int i=0,j=0;i<t_size;i++)
    {
        if(!flag&&s[j]==t[i])
        {
            flag=1;
            t_pos=i+1;
            while(i<t_size&&j<s_size)
            {
                if(s[j]==t[i])
                {
                    i++;
                    j++;
                }
                else
                {
                    i++;
                }
            }
            if(j>=s_size)
            {
                return true;
            }
            else
            {
                j=0;
                i=t_pos;
                flag=0;
            }
        }
    }
    return false;

}
/*
### 解题思路

方法二：
首先解释一下函数char *strchr(char*str, int c);
作用：在字符串str中查找字符c并返回其在字符串中对应的指针（第一个c的指针）。

思路：在字符串t中逐个查找s的每一个字符。如果查找到，则将t的指针移到查找到的字符的下一个。
	  然后重复进行上一步，如果没有查找到函数char *strchr(char*str, int c)返回空指针，则函数结束。
	  如果循环结束时函数任然没有结束，则代表符合题意，返回true。


### 代码
```c
*/
bool isSubsequence(char * s, char * t) {
	int s_size = strlen(s);
	if (s_size == 0)return true;
	int t_size = strlen(t);
	char*temp = t;
	for (int i = 0; i<s_size; i++)
	{
		char *point = strchr(temp, s[i]);
		if (point == NULL)return false;
		int pos = point - t;
		temp = t + pos + 1;
	}
	return true;
}
```