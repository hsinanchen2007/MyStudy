### 解题思路
此处撰写解题思路
首先遍历相加每个二维数组得到一个新的二维数组  二维数组的第0位放具体的数，第二位放下标，然后从小到大排序 在取出前k位的二维数组的第二位下标 
### 代码

```java
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
            int[] arr = new int[mat.length];
            int[][] arr1 = new int[mat.length][2];
           
            for(int i = 0;i<mat.length;i++){
                int sum = 0;
                for(int j =0;j<mat[i].length;j++){
                    sum+=mat[i][j];
                      
                }
                arr1[i][0] = sum;   //第0位放具体的值
                 arr1[i][1] = i;    //第一位放下标 
                 
            }
            for(int i = 0;i<arr1.length;i++){
                for(int c = 0;c<arr1.length-1;c++){
                     if(arr1[c][0] > arr1[c+1][0]){
                         int[] f = arr1[c];
                         arr1[c] = arr1[c+1];
                         arr1[c+1] = f;    //排序
                     }   
            }
            }
           int result[] = new int[k];
           for(int i = 0;i<result.length;i++){
               result[i] = arr1[i][1]; //取下标
           }
            return result;
    }
}
```