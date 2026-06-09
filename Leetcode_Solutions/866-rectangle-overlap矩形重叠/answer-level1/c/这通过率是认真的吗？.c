### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/ef178cad92ac1219daabf5e3b029444d818ecaf8af7c74d56eccd34572bc322f-image.png)


### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
   int flag=0;
    if(rec2[2]>rec1[0]&&rec2[3]>rec1[1]&&rec2[0]<rec1[2]&&rec2[1]<rec1[3])
    {flag=1;}
    if(flag==1)
    return true;
    else return false;
}
```