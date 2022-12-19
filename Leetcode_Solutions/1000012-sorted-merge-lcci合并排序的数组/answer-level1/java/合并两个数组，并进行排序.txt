### 解题思路

![1583239242(1).png](https://pic.leetcode-cn.com/b078f8f56bd48708fce604e382bc3061687971d448cad5a0f9a576d209e96552-1583239242\(1\).png)

新建一个辅助数组temp，对A[]、B[]数组中的元素进行比较，当其中一个数组A[]或B[]遍历完毕，直接把没遍历完的数组的元素放到temp之后，最后把temp一一赋值给A[]；

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
    int[] temp=new int[m+n];
    int i=0,j=0;
    int index=0;
    while(i<m&&j<n)
    {
        if(A[i]<=B[j]){
         temp[index]=A[i];
         i++;
         index++;
        }
        else{
            temp[index]=B[j];
            j++;
            index++;
        }
    }
    if(i==m&&j<n) {
        for(;j<n;j++)
        {temp[index++]=B[j];}
    }
    if(j==n&&i<m){
        for(;i<m;i++)
        temp[index++]=A[i];
    }
    for(int a=0;a<m+n;a++)
    {
        A[a]=temp[a];
    }
    }
}
```