### 解题思路
先要获知每个数字二进制下1的数码；
然后冒泡排序；

### 代码

```java
class Solution {
    public int[] sortByBits(int[] arr) {
        int[] countOfArr = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            int count = 0,temp=arr[i];
            //用以下方法，二进制中有几个1就执行几次，不需要每次判断是否为1
            while(temp>0){
                temp=temp & (temp-1);
                count++;
            }
            countOfArr[i]=count;
        }
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length -1 -i; j++) {
                int temp1 = 0;
                if(countOfArr[j] > countOfArr[j+1]){
                    temp1 = countOfArr[j];
                    countOfArr[j] = countOfArr[j+1];
                    countOfArr[j+1] = temp1;
                    temp1 = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp1;
                }
                else if(countOfArr[j]==countOfArr[j+1]){
                    if(arr[j] > arr[j+1]){
                        temp1 = countOfArr[j];
                        countOfArr[j] = countOfArr[j+1];
                        countOfArr[j+1] = temp1;
                        temp1 = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp1;
                    }
                }
            }
        }
        return arr;
    }
}
```