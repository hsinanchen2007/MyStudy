```
int sum(struct NestedInteger** nestedList, int nestedListSize, int depth){
    int res = 0;
    for(int i = 0; i < nestedListSize; i++){
        //Case 1: Single integer
        if(NestedIntegerIsInteger(nestedList[i])){
            res += depth * NestedIntegerGetInteger(nestedList[i]);
        }
        //Case 2: Nested list
        else{
            struct NestedInteger** n = NestedIntegerGetList(nestedList[i]);
            int size = NestedIntegerGetListSize(nestedList[i]);
            res += sum(n, size, depth+1);
        }
    }
    return res;
}
int depthSum(struct NestedInteger** nestedList, int nestedListSize){
    return sum(nestedList, nestedListSize, 1);
}
```
