(1)首尾指针：从第一个元素开始遍历，如果是奇数，再判断尾指针所指是否为奇数，如果尾指针所指也是奇数，尾指针前移，直到遇到偶数，然后进行调换；如果首指针所指是偶数，首指针前移，开始下一轮判断。循环终止条件为前后指针相遇或首指针小于尾指针。
时间：O(N)
空间：O(1);

(2)直接插入：新建一个数组，再对原数组进行遍历。如果为奇数，将其放入新数组后面，尾指针前移，如果是偶数，将其放入新数组前面，首指针后移。反复操作，直到循环结束。
时间：O(N)
空间:  O(N)
/**

Note: The returned array must be malloced, assume caller calls free().
/
int sortArrayByParity(int* A, int ASize, int* returnSize){
    if(!ASize){
        *returnSize=0;
        return NULL;
    }

    int* ans=(int*)malloc(sizeof(int)*ASize);
    int front=0,rear=ASize-1;
    //直接插入
    for(int i=0;i<ASize;++i){
        if(A[i]&1)
            ans[rear–]=A[i];
        else
            ans[front++]=A[i];
    }
    *returnSize=ASize;

    return ans; 
}

//首尾双指针调换
/**

Note: The returned array must be malloced, assume caller calls free().
/
int sortArrayByParity(int* A, int ASize, int* returnSize){
    if(!ASize){*returnSize=0;return NULL;}

    int* ans=(int*)malloc(sizeof(int)*ASize);
    memcpy(ans,A,sizeof(int)*ASize);
    int front=0,rear=ASize-1;
    for(;front<rear;++front){                       //相遇时说明遍历完成，结束循环
        if(ans[front]&1){
            int temp=0;
            while((ans[rear]&1)&&front<rear) rear–-; //相遇时尾指针无需再减一，因为下面就要进行调换了，如果再减的话，就会把前面的偶数往后排
            temp=ans[front];
            ans[front]=ans[rear];
            ans[rear]=temp;
            rear–;
        }
    }
    *returnSize=ASize;

    return ans;
}