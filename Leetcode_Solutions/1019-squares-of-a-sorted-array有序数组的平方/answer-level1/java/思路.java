### 解题思路
此处撰写解题思路
我的思路:
    新创建一个新的数组长度就是原始数组的长度
    然后遍历循环原始数组的值，把数组中的每一个的值的平方赋值给新的数组。
    最后对新的数组进行排序，我这里用的是比较排序算法
    返回排序好的数组就ok;
### 代码

```java
class Solution {
    public int[] sortedSquares(int[] A) {
        int arr[]=new int[A.length];

        for(int i=0;i<arr.length;i++){
            arr[i]=A[i]*A[i];
        }

        for(int i=0;i<arr.length;i++){
            for(int j=i+1;j<arr.length;j++){
                if(arr[i]>arr[j]){
                    int k=arr[i];
                    arr[i]=arr[j];
                    arr[j]=k;
                }
            }
        }
        return arr;
    }
}
```