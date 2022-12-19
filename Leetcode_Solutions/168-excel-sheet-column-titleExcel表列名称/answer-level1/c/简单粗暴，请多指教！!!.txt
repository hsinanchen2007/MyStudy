本题的主要解题思路在于类似于进制转换，但是又有一点不同，就在于这里的进制转换没有0，有26，所以转换时对26提出来单独进行讨论。

char * convertToTitle(int n){
    char a[10],b[10];
    char *p;
    p=&a;
    int i=0,j=0,k,num;
     while(n>0)
    {
        k=n%26;
         if(n%26==0)
         {
             n=(n-k)/26-1;
         }
         else
         {
             n=(n-k)/26;
         }
        b[i++]=k;
    }
    for(j=0,num=i;j<num;j++, i--)
     {
         if(b[i-1]==0)
         {
             p[j]='Z';
         }
         else
         {
              p[j]=b[i-1]+64;
             
         }
     }
    p[j]='\0';
    return p;
}
