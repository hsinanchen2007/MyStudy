### 解题思路
1.首先思考该问题，配对后剔除，很像栈的后入先出的特点。
2.针对0个字符、奇数个字符的字符串，特殊判定。
3.将字符串内字符依次与栈顶字符对比，可配对弹出栈顶，不可配对，压入栈；利用cnt记录栈高。
4.特别注意：弹栈时边界考虑，防止溢出（这个地方可把我坑惨了）。

### 代码

```c
bool isValid(char * s){

    char *a = (char*)malloc(sizeof(char)*strlen(s));
    int index = 0;
    int cnt = 0;

    if(strlen(s) == 0)  //空或偶数字符串，为有效字符串
	{
        return true;
	}

    if(strlen(s) % 2 != 0) //偶数字符串，为无效字符串
    {
        return false;
    }

    if((s[0]!='(')&&(s[0]!=')')&&(s[0]!='{')&&(s[0]!='}')&&(s[0]!='[')&&(s[0]!=']'))
    {
        return false;
    }   
    *a = s[0];    //初始化建立参考
    cnt = 1;

    for(index = 1; index < strlen(s); index++)
    {
        if((s[index]!='(')&&(s[index]!=')')&&(s[index]!='{')&&(s[index]!='}')&&(s[index]!='[')&&(s[index]!=']'))
        {
            break;
        }

        if(((s[index] - (*a)) == 1)||((s[index] - (*a)) == 2))    //利用ascii表位置，表示配对
        {
            if(--cnt >= 1) 
                a--;        //注意数组溢出问题(只为了实现功能其实可以不用减!!!)
        }
        else
        {
            *(++a) = s[index];
            cnt++;
        }
    }

    if(cnt == 0)    //化简后的个数为0，全部配对完成
	{
        return true;
	}

    return false;
}
```