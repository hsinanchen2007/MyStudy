1.先找到山顶，需要判断山顶不能是第一个元素，即A[i]>A[i+1]，此时i就是山顶元素
2.在确保下坡存在，也就是说会分两次for循环。
这里需要说明的是，在for循环，break跳出和正常跳出对i效果会有所不同，正常跳出i会是判断时候的i+1
break跳出才是正常i.确保下坡期不太方便直接写在外面。有兴趣的大佬可以试试哦。
```
bool validMountainArray(int* A, int ASize){
    if(ASize<3)
    return false;
    if(A[0]>=A[1]||A[ASize-1]>=A[ASize-2])//处理一下极端情况
    return false;
    int i;
    for(i=1;i<ASize-1;i++)
    if(A[i]>=A[i+1])//找到山峰
    break;
    for(i;i<ASize-1;i++)
    if(A[i]<=A[i+1])
    return false;
    return true;

}
```
