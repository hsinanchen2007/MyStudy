```
bool isPalindrome(char * s){
	bool flag = false;
	int len = strlen(s);
	if(len<=1)  return !flag; 
	int i = 0 ,j=len-1;
	while(i<=j)
	{
        //判断是不是字符或数字
		if(isalnum(s[i])&&isalnum(s[j]))
		{
            //忽略大小写也可全部转换成小写或者大写
				if(tolower(s[i])==tolower(s[j]))
				{
					i++;
					j--;
                    //比如 bb这类型每部都要加上标志位
					flag = true;
				}else{
				    flag = false;
				  break;
				}
		}else
		{
			if(!isalnum(s[i]))
				i++;
                //判断边界问题
			if(i==j){
				flag =true;
				break;
			}
			if(!isalnum(s[j]))
				j--;
			if(i==j){
				flag =true;
				break;
			}
		}	
	}

	return flag;
}

```
