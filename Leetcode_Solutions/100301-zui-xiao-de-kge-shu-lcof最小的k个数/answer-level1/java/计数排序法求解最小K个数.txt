### 解题思路
本题要求解给定整数数组的最小K个数，很直接的想法是排序后直接取前K个数输出即可。
但是Java中自带的排序方法Array.Sort方法的时间复杂度是o(nlogn)。所以这种方法的时间复杂度必然不能低于o(nlogn)。
我们有没有o(logn)的解法呢？
答案是肯定的，我们采用计数排序的思路：遍历数组，将各个数出现的次数记录下来，然后遍历我们得到的数组，取得前k个值即可。

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if(arr.length == 0)
            return new int[k];
        int max = arr[0] , min = arr[0];
        for(int i : arr){
            if(max < i)
                max = i;
            if(min > i)
                min = i;
        }
        int[] CountArr = new int[max - min + 1];
        for(int i : arr){
            CountArr[i - min]++;
        }
        int[] res = new int[k];
        int j = 0;
        for(int i=0;i<CountArr.length && j<k;i++){
            while(CountArr[i]-- > 0 && j<k) {
                res[j++] = i + min;
            }
        }
        return res;
    }
}
```