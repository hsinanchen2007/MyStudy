### 解题思路
![image.png](https://pic.leetcode-cn.com/e87167bb12d0080e94eaba444544298fd3058284a3f1bd8e3ff2f3df979f959b-image.png)

用i,j两个指针分别表示A、B两个数组，k来表示A数组的界限，j<n来用作循环界限。
以A数组为基准，A[i]<=B[j]时i++，找到第一个A[i]>B[j],将A数组从i开始到k-1的数据后移一位，然后将B[j]填入。
当A数组要求的初始化数据已经遍历完成，但B数组仍有数据时，此时i>=k,直接将B数组数据填入。

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i=0,j=0,k=m;
    while(j<n){
        if(A[i]<=B[j]&&i<k)
            i++;
        else if(A[i]>B[j]&&i<k){
            for(int s=k-1;s>=i;s--)
                A[s+1]=A[s];
            k++;//注意此处用以标明A的初始化数量界限的指针要加1；
            A[i++]=B[j++];
        }
        else{
            A[i++]=B[j++];
        }
    }
}
```