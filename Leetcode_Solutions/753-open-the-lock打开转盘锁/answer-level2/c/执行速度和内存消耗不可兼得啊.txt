### 解题思路
其实就是bfs模板题，多了一个dead的限制条件而已，在搜索时跳过即可

### 代码

```c
int isdead(char** a,char b[5],int c)//是否为dead
{
    for(int i=0;i<c;i++)
    {
        if(strcmp(a[i],b)==0)
            return 1;
    }
    return 0;
}

void push(char p[][5],int* rear,char dat[5])//入队
{
    *rear=(*rear+1);
    strcpy(p[*rear],dat);
}


int isempty(int rear,int fount)//是否队空
{
    if(rear<fount)
    return 0;
    return 1;
}
int hash(int a[],char b[5])//避免重复
{int c=0;
for(int i=0;i<4;i++)
{c*=10;
    c+=(b[i]-'0');
}

if(a[c]==0)
{a[c]=1;return 0;}
else
{
    return 1;
}
}

int openLock(char ** deadends, int deadendsSize, char * target){

char qu[10000][5];//队列
int hashd[10000]={0};//哈希表
int step=0;char ch[5];
int fount=0,//队头
int rear=-1;//队尾

if(isdead(deadends,"0000",deadendsSize)==1)
return -1;
else
{push(qu,&rear,"0000");
   while(isempty(rear,fount))
    {
        step+=1;int x=rear-fount+1;
        
        for(int k=1;k<=x;k++){
        for(int i=0;i<4;i++)
        for(int j=-1;j<2;j+=2)
        {
            strcpy(ch,qu[fount]);
            ch[i]=(ch[i]-'0'+j+10)%10+'0';

        if(hash(hashd,ch)||isdead(deadends,ch,deadendsSize))
        {
            continue;
        }

        if(strcmp(ch,target)==0)
            {return step;}

        push(qu,&rear,ch);
        }
   fount++;
        }
    }
return -1;

}
}
```