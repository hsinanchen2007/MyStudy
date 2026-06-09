解题思路：最长回文=偶数个字母数+最多奇数个字母数+其它每个（奇数个字母数-1）


int longestPalindrome(char * s){
   

    int i = 0,j=0,add=0,max=0;
    int arr[52] = {0};
     
    for(i=0;*(s+i)!='\0';i++){
         if(((int)*(s+i))>=65&&((int)*(s+i))<=90)
         arr[(int)(*(s+i))-65]+=1;
         else if(((int)*(s+i)>=97)&&((int)*(s+i)<=122))
         arr[(int)(*(s+i))-97+26]+=1;
         else
         printf("erro");
     }

     for(j=0;j<=51;j++)
     {  
         if((arr[j]%2)==0)
            add=add+arr[j];
         else
            {
            add = add+(arr[j]-1);
            if(add%2==0)
            add = add +1;
            }
     }
    return add;
}