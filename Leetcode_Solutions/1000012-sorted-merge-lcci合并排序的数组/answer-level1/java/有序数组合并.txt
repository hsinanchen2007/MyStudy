### 解题思路
此处撰写解题思路
读题：
1：B要合进来A。A 除了m长度数据外，预留了n个长度的位置给B；
2：返回结果是A。
解题：
1：我们可以定义一个临时合并结果m+n长度，最后赋值给A。空间会浪费n个。
2：也可以一开始，定义一个长度为m的临时数组变量存储合并前的A。最多使用m。

选用第二种，定义一个临时变量m长度数组存储A的数据。

合并采用双指针法，可以均从前面从小到大排，也可以均从最后面，从大到小排。

注意点：某一个数组遍历完毕，不代表另外一个数组也遍历完毕。
当一组遍历完，另外一组剩余数据可以直接加到队尾。


### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {

        int [] C = new int[m];
         System.arraycopy(A, 0, C, 0, m);

        int j=0;
        int i=0;
        int k =0;
        while(i<m && j<n ){
            if(C[i]<=B[j]){
               A[k]=C[i];
               i++;
            }else{
                A[k] = B[j];
                j++;
            }
            k++;
        }
        while(i < m){
            A[k] = C[i];
            k++;
            i++;
        }
        while(j<n){
              A[k] = B[j];
              k++;
              j++;
        }


    }
}
```