### 解题思路
普普通通逻辑，一步一步就绪吧。

### 代码

```c
char* compressString(char* S)
{ 
    int len=strlen(S);  //开辟足够用的数组空间
    if(len<2) return S;
    char *result= (char *)alloca(sizeof(char)*len*2+1);  
    int p_S=0,p_result=0,count=1;  //初始化遍历状态
    char temp=S[0];    
    p_S++;

    while(*(S+p_S)!='\0')   //遍历字符串
    {
        if(*(S+p_S)==temp) count++;     //与上一个字符相同，计数加一
        else                            //与上个不同，加入上个字符和数目到结果数组，并记数清为1
        {
            *(result+p_result++)=temp;
            if(0<count&&count<10)       //判断count大小并添加
                *(result+p_result++)=count+'0';
            else if(10<=count&&count<100) 
            {
                *(result+p_result++)=count/10+'0';
                *(result+p_result++)=count%10+'0';
            }
            else if(100<=count&&count<1000)
            {
                *(result+p_result++)=count/100+'0';
                *(result+p_result++)=count/10%10+'0';
                *(result+p_result++)=count%10+'0';
            }
            else if(1000<=count&&count<10000)
            {
                *(result+p_result++)=count/1000+'0';
                *(result+p_result++)=count/100%10+'0';
                *(result+p_result++)=count/10%10+'0';
                *(result+p_result++)=count%10+'0';
            }   
            temp=*(S+p_S);
            count=1;
        }
        p_S++;
    }
    *(result+p_result++)=temp;
    if(0<count&&count<10)      //判断count大小并添加
        *(result+p_result++)=count+'0';
    else if(10<=count&&count<100) 
    {
        *(result+p_result++)=count/10+'0';
        *(result+p_result++)=count%10+'0';
    }
    else if(100<=count&&count<1000)
    {
        *(result+p_result++)=count/100+'0';
        *(result+p_result++)=count/10%10+'0';
       *(result+p_result++)=count%10+'0';
    }
    else if(1000<=count&&count<10000)
    {
        *(result+p_result++)=count/1000+'0';
        *(result+p_result++)=count/100%10+'0';
        *(result+p_result++)=count/10%10+'0';
        *(result+p_result++)=count%10+'0';
    }   
    *(result+p_result)='\0';

    if(strlen(result)<len) return result;    //返回结果
    else return S;
}

```