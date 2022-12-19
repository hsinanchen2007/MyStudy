### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/60bd88dce178afbcac32a6717f4334619a4208eab53d8cff197450d76fd04c7c-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    int* data_buf=(int*)malloc(sizeof(int)*(n));
    memset(data_buf,0,sizeof(int)*(n));
    *returnSize=n;

    for(int i=0,j=n-1;i<n/2;i++,j--){
        data_buf[i]=i+1;
        data_buf[j]=-(i+1);
    }

    return data_buf;
}
```