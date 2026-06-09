```
void dfs(int *arr, int len, int *path,int index, int **ret, int *ret_index,int *visited){
    if(index==len){
    ret[*ret_index]= malloc(sizeof(int)*len);
    memcpy(ret[*ret_index],path,sizeof(int)*len);
    (*ret_index)++;
    return;
    }
    for(int i=0;i<len;i++){
        if(visited[i]==0){
            visited[i]=1;
            path[index]=arr[i];
            dfs(arr,len,path,index+1,ret,ret_index,visited);
            visited[i]=0;//需要回溯，就加上这句
        }
    }
}


#define LEN 0xfff

int** permute(int* arr, int len, int* returnSize, int** returnColumnSizes){
    int **ret = (int **)malloc(sizeof(int*)*LEN);
    int *path = (int *)malloc(sizeof(int) * len);
    int index = 0;
    int i;
    int ret_index=0;
    int *visited= (int *)malloc(sizeof(int)*len);
    memset(visited,0,sizeof(int) * len);

    dfs(arr,len,path,index,ret,&ret_index,visited);
    *returnColumnSizes = malloc(sizeof(int)*ret_index);
    
    for(i=0; i<ret_index; i++){
        (*returnColumnSizes )[i] = len;
    }
    
   // printf("ret_index:%d\n", ret_index);
    *returnSize = ret_index;
    
    return ret;
    
}
```
