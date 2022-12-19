### 解题思路
检测后面队列的所有值 是不是大于前面队列的最大值；
如果不是  小于前面最大值得位置开始 重新进行上面的运算，直到找到结果。  或者起始位置位置移动到对列尾部。

### 代码

```c
int partitionDisjoint(int* A, int ASize){
    int key = A[0];
    int i = 1;
    int flag = 0;
    int max_1 = 0; //临时队列的最大值
    while(i < ASize){
        if(A[0] <= A[i]){ 
               max_1 = key;  //初始值为key
               int flag = 0;
               for(int j = i;j<ASize&&flag == 0;j++){
                    //保存前面队列的最大值
                    if(A[j]>max_1){
                        max_1 = A[j];
                    }
                    if(A[j]<key){
                        key = max_1;
                        i = j + 1;
                        flag = 1;
                        break; 
                    }
               }
               if(flag == 0){
                    return i;
               }
              
         }else{
             i++;
         }


    }
    return 0;

}
```