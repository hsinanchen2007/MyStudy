### 解题思路
此处撰写解题思路
我的思路:
    先将二维数组的大小赋值给一个一维数组的长度，用二维数组的长度和二维数组中的一维数组的长度相成就是二维数组的长度了
然后把二维数组中的值都放进到一维数组中取，随后就对它进行插入排序算法，从小大到排序完以后，用线性查找算法完成查找到
下标第K个值的位置的元素，最后返回这个元素就可以了！
### 代码

```java
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int t=0;
        int arr[]=new int[matrix.length * matrix[0].length];
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[i].length;j++){
                arr[t]=matrix[i][j];
                t++;
            }
        }
        cha(arr);
        int index=0;
        for(int i=0;i<k;i++){
            index=arr[i];
        }
        return index;
    }
    //插入排序
    public static void cha(int arr[]){
        for(int i=1;i<arr.length;i++){
            int j=i-1;
            int temp=arr[i];
            while(j>=0 && temp<arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=temp;
        }
    }
}
```