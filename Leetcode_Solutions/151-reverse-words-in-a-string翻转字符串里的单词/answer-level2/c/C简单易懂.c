### 解题思路
第一步：将所有无用空格删除，并将单词逆置
       当前为空格时，只有下一个元素时字母，这个空格才有用，保留。否则blank++代表至今共有blank个空格。
       当前为字母时，下一个为空格或\0,则此处字母是单词结束，将字母前移并将单词逆置，num清零。否则单词长       度num++。
        pre==0代表此处及前面全是空格。
第二步：整体逆置
     代码整体未调用任何库函数
   
### 代码

```c
char * reverseWords(char * s){
    int i,m,n,j,g,pre=0,blank=0,num=0;
    char temp;
   
   for(i=0;s[i]!='\0';i++)
   { 
       if(s[i]==' ')                                          
       {   if(pre==0||s[i+1]==' '||s[i+1]=='\0')  //无用空格        
             blank++;
           else                                              
              s[i-blank]=s[i];                   //有用空格
      
       }
       else                                                                
        {   pre=1;  
             if(s[i+1]==' '||s[i+1]=='\0')        //单词最后一个字母
            {   
                num++;
                s[i-blank]=s[i];
                for(m=i-blank-num+1,n=i-blank;m<n;m++,n--) 
             {
                temp=s[m];
                s[m]=s[n];
                s[n]=temp; 
             }
             num=0;
            }          
            else                                 //中间字母
            {                                        
              num++;
              s[i-blank]=s[i];
              }
           }   
     }         

     s[i-blank]='\0';

     for(j=0,g=i-blank-1;j<g;j++,g--)                    
     {    temp=s[j];
          s[j]=s[g];
          s[g]=temp; 
}

return s;
}
```