### 解题思路
主要总是画出树状图，还有在设计空间大小的时候要足够大

### 代码

```c


 void dfs(char **r,int j,int n,int *returnSize,char *lr,int left,int right,int num){
     if(n==0){
     	int x;
     	x=j;
         while(x<2*num){
             r[*returnSize][x++]=')';
         }
         r[*returnSize][x]='\0';
		 (*returnSize)++;
       	 r[*returnSize]=(char *)malloc(sizeof(char)*(2*num+3));
         strcpy(r[*returnSize],r[*returnSize-1]);
         n++;
         return;
     }
   
     	for(int i=0;i<2;i++){ 
		    if(left==right){
		         r[*returnSize][j]='(';
		         left++;
		         dfs(r,j+1,n-1,returnSize,lr,left,right,num);
		         break;
		    }
		    else if(left>right){
		    	r[*returnSize][j]=lr[i];
		         if(i==0){
		         	left++;
		         	n--;
				 }
		         else if(i==1)right++;
//		         printf("%c",r[*returnSize][j]);
		         dfs(r,j+1,n,returnSize,lr,left,right,num);
		         if(i==0){
		         	left--;	
		         	n++;
				 }
		         else if(i==1)right--;
			}
	         
	     }
	     
     return;
 }
char ** generateParenthesis(int n, int* returnSize){
    char **r=(char **)malloc(sizeof(char *)*(500000));
    char lr[2]={'(',')'};
    r[0]=(char *)malloc(sizeof(char)*(2*n+3));
    r[0][0]='(';
    *returnSize=0;
    dfs(r,1,n-1,returnSize,lr,1,0,n);
//    printf("%d",r);
//    for(int i=0;i<*returnSize;i++){
//    	printf("%s\n",r[i]);
//	}
//	printf("1");
    return r;
}


```