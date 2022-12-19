### 解题思路
此处撰写解题思路

### 代码

```c
int evalRPN(char ** tokens, int tokensSize){
    int temp,i,j,k;
    int Z[5000];
    for(k=0,i=0;i<tokensSize;i++){
        if(tokens[i][0]<='9'&&tokens[i][0]>='0'||(tokens[i][0]=='-'&&tokens[i][1]<='9'&&tokens[i][1]>='0')){
            temp=0;
            if(tokens[i][0]=='-') j=1;
            else j=0;

            while(tokens[i][j]!='\0'){
                temp=temp*10+(tokens[i][j++]-'0');
            }
            if(tokens[i][0]=='-') temp=-1*temp;
            Z[k++]=temp;
        }
        else{
            switch(tokens[i][0]){
                case '+':
                Z[k-2]=Z[k-2]+Z[k-1];
                k--;
                break;

                case '-':
                Z[k-2]=Z[k-2]-Z[k-1];
                k--;
                break;

                case '/':
                Z[k-2]=Z[k-2]/Z[k-1];
                k--;
                break;

                case '*':
                Z[k-2]=Z[k-2]*Z[k-1];
                k--;
                break;
            }
        }
    }
    return Z[0];
}
```