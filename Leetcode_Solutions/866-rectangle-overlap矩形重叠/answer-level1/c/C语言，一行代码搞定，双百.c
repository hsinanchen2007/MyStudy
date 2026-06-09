### 解题思路
见代码
![image.png](https://pic.leetcode-cn.com/e1bdd7b73af2ade3a438ede5b343b3f6f4b56c465b8228718ca19b6f3e4e0e48-image.png)


### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    return (rec1[0]<rec2[2]&&rec1[1]<rec2[3]&&rec2[0]<rec1[2]&&rec2[1]<rec1[3])? true:false;
}
```