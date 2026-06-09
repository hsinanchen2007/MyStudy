### 解题思路
此处撰写解题思路
遍历数组
### 代码
int countSegments(char * s)
{
	if(strlen(s) == 0)
		return 0;
	int i,count;
	int rear = strlen(s)-1;
	for(i = rear;i >= 0;i--)                //防止全是空格
    {
        if(s[i] == ' ')
            rear--;
        else
        	break;
    }
    if(rear < 0)                            //全是空格返回0
        return 0;
    i = 0;
    if(s[0] == ' ')                       //判断第一个字符是否为空格
    	count = 0;                         //是空格count从0计数
    else
    	count = 1;                         //否则从一计数
	for(i = 0; s[i+1]!='\0';i++)            //此处 i+1 为了防止下面if条件越界
	{
		if(s[i]!=' ')
			continue;
		else if(s[i+1] != ' ')             
			count++;
	}
	return count;
}