### 解题思路
此处撰写解题思路
创建新的空间提高代码的执行效率。。缺点：浪费空间
### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
            if(arr1==null || arr1.length==0 || arr2==null || arr2.length==0){
                return null;
            }
            // 找出arr1中最大值+1作为新数组的下标
            int max = arr1[0];
            for(int i=1;i<arr1.length;i++){
                max = Math.max(max,arr1[i]);
            }
            // 创建新数组
            int[] arr = new int[max+1];
            // 遍历arr1数组 将值作为下标 出现次数作为值 赋值给新数组
            for(int i=0;i<arr1.length;i++){
                arr[arr1[i]]++;
            }
            // 创建一个等同于arr1长度的数组作为返回值
            int[] arr_ = new int[arr1.length];
            int index = 0;// 返回数组的下标
            // 遍历arr2给返回数组赋值
            for(int i=0;i<arr2.length;i++){
                int e = arr2[i];
                while(arr[e]>0){
                    arr_[index] = e;
                    index++;
                    arr[e]--;
                }
            }
            // 将arr数组中剩余的值赋值给返回的数组
            for(int i=0;i<arr.length;i++){
                while(arr[i]>0){
                    arr_[index] = i;
                    index++;
                    arr[i]--;
                }
            }

            return arr_;
    }
}
```