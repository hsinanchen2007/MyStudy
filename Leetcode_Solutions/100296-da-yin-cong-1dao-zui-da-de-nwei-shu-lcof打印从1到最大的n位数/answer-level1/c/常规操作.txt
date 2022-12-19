### 解题思路
常规操作
![图片.png](https://pic.leetcode-cn.com/10083123c07454e7f77c0886f8d17a6f319ee867160676877515a011b6b52de5-%E5%9B%BE%E7%89%87.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printNumbers(int n, int* returnSize){
    int size=pow(10.0,n)-1;
    int *output=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        output[i]=i+1;
    }
    *returnSize=size;
    return output;
}
```