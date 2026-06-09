```
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    int a[2000]={0};
    for(int i=0;i<prerequisitesSize;i++)
        a[prerequisites[i][0]]++;
    *returnSize=numCourses;
    int* b=(int*)malloc(numCourses*sizeof(int));
    int n=0;
    for(int i=0;i<numCourses;i++)
        if(a[i]==0)
            b[n++]=i;
    for(int i=0;i<numCourses;i++){
        int t=0;
        for(int j=0;j<prerequisitesSize;j++)
            if(prerequisites[j][0]!=-1&&a[prerequisites[j][0]]>0&&a[prerequisites[j][1]]==0){
                a[prerequisites[j][0]]--;
                if(a[prerequisites[j][0]]==0)
                    b[n++]=prerequisites[j][0];
                prerequisites[j][0]=-1;
                t=1;
            }
        if(t==0)
            break;
    }
    if(n!=numCourses)
        *returnSize=0;
    return b;
}
```
