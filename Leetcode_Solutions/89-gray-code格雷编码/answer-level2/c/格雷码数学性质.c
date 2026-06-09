### 解题思路
二进制数转格雷码
数学法
![图片.png](https://pic.leetcode-cn.com/39264c1a8ddf023c70cba1bc437c1c0c0af1729305919b5f6d4c18254db07168-%E5%9B%BE%E7%89%87.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    int total=pow(2.0,n);
    int *a=malloc(sizeof(int)*total);
    *returnSize=total;
    for(int i=0;i<total;i++){
        a[i]=(i>>1)^i;
    }
    return a;
}
```