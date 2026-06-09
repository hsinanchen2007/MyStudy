### 解题思路
多提交几次，可能减少执行用时

### 代码

```c
int itos(int x,char* str,int fp,int* c){

    char index[]="0123456789";
    int j=fp;
    int i=0;
    char s[5]={NULL};
    do{
        s[i++]=index[x%10];
        x/=10;
    }while(x);
    for(--i;i>=0;--i){
        str[fp++]=s[i];
        *c+=1;
    }
    return fp;
}

char* compressString(char* S){
    if(*S=='\0')
        return S;
    char F[100001]={0};
    int Fp=0; 
    char* fs,*rs;
    fs=rs=S;
    int count=0;
    int counts=0;
    int countd=0;

    while(*fs!='\0'){

        if(*fs==*rs){
            count++;
            counts++; 
            fs++;           
        }
        else{
            counts++;
            countd++;
            F[Fp++]=*rs;
            Fp=itos(count,F,Fp,&countd);
            count=1;            
            rs=fs;
            fs++;
        }
    }
    countd++;
    F[Fp++]=*rs;
    Fp=itos(count,F,Fp,&countd);
    F[Fp]='\0'; //结尾
    printf("s: %d | d: %d",counts,countd);
    return counts <= countd ? S : F;
}

```