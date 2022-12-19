### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        //首先，先定义一个数组，用来存储和返回
        //数组的长度根据k来决定
        int [] sum=new int[k];
        //直接用Arrays.sort的方法排序，
        Arrays.sort(arr);
        //用for循环，循环次数由数组的长度决定
        for(int i=0;i<sum.length;i++){
            sum[i]=arr[i];
        }
        //返回数组
        return sum;
    }
}
```