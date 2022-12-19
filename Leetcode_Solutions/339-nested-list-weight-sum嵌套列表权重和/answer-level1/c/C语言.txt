```
void dfs1(struct NestedInteger* nestnode,int k,int *sum){
    struct NestedInteger**tmp=NestedIntegerGetList(nestnode);
    int size=NestedIntegerGetListSize(nestnode);
    for(int i=0;i<size;i++){
        if(NestedIntegerIsInteger(tmp[i])){
            (*sum)+=NestedIntegerGetInteger(tmp[i])*k;
        }else{
            dfs1(tmp[i],k+1,sum);
        }
    }
}

int depthSum(struct NestedInteger** nestedList, int nestedListSize){
    int sum=0;
    for(int i=0;i<nestedListSize;i++){
        if(NestedIntegerIsInteger(nestedList[i])){
            int tmp=NestedIntegerGetInteger(nestedList[i]);
            sum+=tmp;
            }
            else{
                dfs1(nestedList[i],2,&sum);
            }
    }
    return sum;
}
```
