### 解题思路
理解manacher的原理

### 代码

```c
//manacher in c
char * longestPalindrome(char * s){
    int len;
    char *ss=NULL;    
    char *t=s;
    int lstrd=0;
    int tari;

    while(*(t++));
    len=t-1-s;
   // printf("%d",len);

    if(len==0 || len==1)
    {
        return s;
    }

    ss=(char *)malloc((len*2+3+1)*sizeof(char));
    *ss='<';
    *(ss+1)='#';
    for(int i=0;i<len;i++)
    {
        *(ss+2+i*2)=*(s+i);
        *(ss+2+i*2+1)='#';
    }
    *(ss+len*2+2)='>';
    *(ss+len*2+3)='\0';
   // printf("%s",ss);

    int ctr=1; //center
    int rd[2*len+3];//radius
    int mir; //mirror
    rd[1]=rd[0]=0;
    for(int i=1;i<=len*2+2-1;i++)
    {
       // printf("%c",*(ss+i));
        mir=ctr*2-i;
        if(rd[mir] < ctr+rd[ctr]-i) //相等则还有可能扩张
        {
            rd[i]=rd[mir];
        }
        else
        {
            rd[i]=ctr+rd[ctr]-i;
            rd[i]=rd[i]>0?rd[i]:0;
            while(i-rd[i] >= 0)
            {
                if(*(ss+i-rd[i]) != *(ss+i+rd[i]))
                {
                    break;
                }
                rd[i]++;
            }
            rd[i]--;
            if(lstrd<rd[i])
            {
                lstrd=rd[i];
                tari=i;
            }
            ctr=i;
        }
    }
    //printf("%d",(tari-2)/2);
    char *ans=NULL;
    ans=(char *)malloc((1+rd[tari])*sizeof(char));  //半径刚好是目标子串长度
    int start=(tari-rd[tari]-1)/2;
   // printf("%d",-1/2);  //-1/2==0

    for(int i=0;i<rd[tari];i++)
    {
        *(ans+i)=*(s+start+i);
    }
    *(ans+rd[tari])='\0';

    return ans;
}


```