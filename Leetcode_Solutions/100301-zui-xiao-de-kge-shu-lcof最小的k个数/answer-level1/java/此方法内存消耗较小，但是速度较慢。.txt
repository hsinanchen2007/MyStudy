### 解题思路
1.传进来的参数k决定了要生成的含最小值数组的容量
2.使用二重循环，每次都假定当前数组中第一个值是最小，然后查找最小值，记录位置，存入数组
3.找到当前最小值后就把原先位置的值改为10001，因为最大值为10000
4.重复2.3循环，直至结束
5.返回最小值

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        int[] min=new int[k];
        int pos=0;
        for(int i=0;i<min.length;i++){
            int min1=arr[0];
            min[i]=arr[0];
            for(int j=0;j<arr.length;j++){
                if(min1>arr[j]){
                    min1=min[i]=arr[j];
                    pos=j;
                }
            }
            arr[pos]=10001;
        }
        return min;    
       }

    }
```