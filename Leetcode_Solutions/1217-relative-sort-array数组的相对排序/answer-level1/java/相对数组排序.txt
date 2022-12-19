### 解题思路
计数排序

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        //计数排序
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for(int i : arr1){
            max = Math.max(max,i);
            min = Math.min(min,i);
        }
        int[] help = new int[max+1];
        for(int n : arr1){
            //help数组统计在arr1中每个数字n出现的次数help[n]
            help[n]++;
        }
        int j=0;
        //按照arr2的顺序，如果help数组其次数>0,则依次放入arr1数组
        for(int n : arr2){
            while(help[n] >0){
                arr1[j] = n;
                j++;
                help[n]--;
            }
        }
        //处理不在arr2中的数据
        for(int i=min; i<=max; i++){
            while(help[i] >0){
                arr1[j] = i;
                j++;
                help[i]--;
            }
        }
        return arr1;
    }
}
```