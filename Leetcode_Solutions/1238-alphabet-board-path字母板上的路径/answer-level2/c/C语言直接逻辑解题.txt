执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :6.9 MB, 在所有 C 提交中击败了38.39%的用户

```
char * alphabetBoardPath(char * target){
    int i,j,k,t_i,t_j,res_i;
    i=j=k=t_i=t_j=res_i = 0;
    int ii,jj,q;
    char* res = (char*)malloc(500);
	while (target[k]!='\0'){
        if(target[k]>='a' && target[k]<='e'){
            t_i = 0;
            t_j = target[k]-'a';
        }else if(target[k]>='f' && target[k]<='j'){
            t_i = 1;
            t_j = target[k]-'f';
        }else if(target[k]>='k' && target[k]<='o'){
            t_i = 2;
            t_j = target[k]-'k';
        }else if(target[k]>='p' && target[k]<='t'){
            t_i = 3;
            t_j = target[k]-'p';
        }else if(target[k]>='u' && target[k]<='y'){
            t_i = 4;
            t_j = target[k]-'u';
        }else{
            t_i = 5;
            t_j = 0;
        }
        
        ii = t_i - i;
        if(ii>0){
            for(q=0;q<ii;q++){
            	if(t_i == 5 && ii!=0 && q==ii-1){
					continue; 
				} 
                res[res_i] = 'D';
                res_i ++;
            }
        }else if(ii<0){
            for(q=0;q<-ii;q++){
            	 
                res[res_i] = 'U';
                res_i ++;
            }
        }
        i = t_i;
        
        jj = t_j - j;
        if(jj>0){
            for(q=0;q<jj;q++){
                res[res_i] = 'R';
                res_i ++;
            }
        }else if(jj<0){
            for(q=0;q<-jj;q++){
                res[res_i] = 'L';
                res_i ++;
            }
        }
        if(t_i==5 && ii!=0){
        	res[res_i] = 'D';
        	res_i ++;
		}
        j = t_j;
        
        {
        	res[res_i] = '!';
        	res_i ++;
		}
		k++;
	}
    res[res_i]='\0';
    return res;

}
```
