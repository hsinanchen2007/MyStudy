建立一个足够大的一维数组a，初始值都为0，
假设数组大小为n，那么数组中每一个元素存放的是0~n-1门课中，学习每门课之前需要完成课程的数量。
然后循环prerequisitesSize次，把a[prerequisites[i][0]]++;，目的是把数组a针对问题初始化。
然后为了不漏解，重复遍历prerequisites二维数组numCourses次，对数组a进行调整。
在改动过程中，判断a[prerequisites[j][0]]>0&&a[prerequisites[j][1]]==0，数组a中如果有前提课程没完成则为正数，否则为0，
所以当a[prerequisites[j][0]]>0并且a[prerequisites[j][1]]==0时，认定为可以把prerequisites[j][0]的前提课程减少一个，
因为prerequisites[j][1]已经完成了，
然后把调整过数据的prerequisites[j][0]变为-1，保证不重复查询到他。
在循环过程中，设置一个标记t，若t没有变动过，则数组a已经改动完全了，可以跳出循环。
最后把数组a中前numCourses个元素累加，若结果为0，则满足条件，否则不满足条件。
```
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int a[2000]={0};
    for(int i=0;i<prerequisitesSize;i++)
        a[prerequisites[i][0]]++;
    for(int i=0;i<numCourses;i++){
        int t=0;
        for(int j=0;j<prerequisitesSize;j++)
            if(prerequisites[j][0]!=-1&&a[prerequisites[j][0]]>0&&a[prerequisites[j][1]]==0){
                a[prerequisites[j][0]]--;
                prerequisites[j][0]=-1;
                t=1;
            }
        if(t==0)
            break;
    }
    int n=0;
    for(int i=0;i<numCourses;i++)
        n+=a[i];
    return n==0;
}
```
