# 思路
用一个structure来记录他们行与战士的数量，然后排序输出数组
![image.png](https://pic.leetcode-cn.com/263dc72ecefc03849874f343cbbee1cf003287065518c9741253c8ed51b2c39d-image.png)


# 代码：
```
typedef struct{
    int numebrofsoldiers;
    int row;
}data;

int data_cmp(const void* num1, const void* num2);
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    data* comparing  = malloc(sizeof(data) * matSize);
    int count = 0, i,j;
    int *answer = malloc(sizeof(int) * k);

    for(i = 0; i < matSize;i++){
        count = 0;
        for(j = 0; j < *matColSize;j++){
            if(mat[i][j] == 0) break;
            count++;
        }
        comparing[i].numebrofsoldiers = count;
        comparing[i].row = i;
    }
    qsort(comparing, matSize, sizeof(data), data_cmp);
    for(i = 0; i < k; i++){
        answer[i] = comparing[i].row;
    }
    free(comparing); 
    *returnSize  = k;
    return answer;
}

int data_cmp(const void* num1, const void* num2){
    if(((data*)num1)->numebrofsoldiers - ((data*)num2)->numebrofsoldiers == 0){
        return ((data*)num1)->row - ((data*)num2)->row;
    }
    return ((data*)num1)->numebrofsoldiers - ((data*)num2)->numebrofsoldiers;
}
```
