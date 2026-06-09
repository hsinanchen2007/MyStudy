事先声明一下，没懂C解题时候“returnSize”和“returnColumnSizes”这两个参数的意义是啥
```solveNQueens(int n, int* returnSize, int** returnColumnSizes)```
另外，把这两个参数打印后，也发现是地址内参数并没有被赋值，虽然有注释，但还是不太懂，希望清楚的人给我留个言告诉我一声。

以下是我按照自己思路用C写的，输入/输出参数可能和本题不太一样。
```
#include <stdio.h>
#include <stdlib.h>

void solveNQueens(int n,char *r){
    int up[2*n];
    int down[2*n];
    int col[n];
    int row[n]; // recorder the index in rows
    int i = 0; // layer
    int j = 0; // index in layers
    int num = 0;
    int *_result;
    _result = (int *)malloc(sizeof(int)*n);
    int res[n];
    for(int s=0;s<n;s++){
        row[s]=0;
        col[s]=0;
    }
    for(int s=0;s<2*n;s++){
        up[s]=0;
        down[s]=0;
    }
    while(i < n){
        int count = 0;
        j = row[i];
        for(;j<n;j++,row[i]=j){
            printf("#%d,%d\n",i,j);
            if(col[j]==1 || up[i-j+n]==1 || down[i+j]==1){
                if(j==n-1){
                    count=1; // cant find a right place
                    break;
                }
                continue;
            }
            printf("##%d,%d\n",i,j);
            col[j]=1; up[i-j+n]=1; down[i+j]=1;
            res[i] = j;
            break;
        }
        if(count == 1){ // search fail in this layer
            row[i] = 0;
            i--;
            col[res[i]]=0; up[i-res[i]+n]=0; down[i+res[i]]=0;
            while(++row[i] >= n){
                row[i] = 0;
                i--;
                printf("back to %d layer!\n",i);
                if(i<0) break;
                col[res[i]]=0; up[i-res[i]+n]=0; down[i+res[i]]=0;
            }
            if(i<0) break;
        }else{
            i++;
            if(i==n && row[0]<n){ // find the next result
                num++;
                printf("the %dst writen\n",num);
                if(num == 1){
                    for(int t=0;t<n;t++) _result[t]=res[t];
                }else{
                    _result = (int *)realloc(_result,sizeof(int)*n*num);
                    for(int t=0;t<n;t++) _result[n*num-n+t] = res[t];
                }
                printf("wiiten finshed\n");
                i--;
                row[i]++;
                col[res[i]]=0; up[i-res[i]+n]=0; down[i+res[i]]=0;
            }
        }
    }
    for(int t=0;t<num;t++){
        for(int y=0;y<n;y++){
            for(int z=0;z<n;z++)
                r[t*n*n+y*n+z]='.';
            r[t*n*n+y*n+_result[t*n+y]] = 'Q';
        }
    }
    free(_result);
}

int main(){
    int n = 4;
    char *res = (char*)malloc(sizeof(char)*n*n*2);
    solveNQueens(n,res);
    printf("result:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++)
                printf("%c",res[i*n*n+j*n+k]);
            printf("\n");
        }
        printf("\n");
    }
    free(res);
}

```
这里，实际上我需要事先知道我输出的解一共会有多少种，才能够传回来