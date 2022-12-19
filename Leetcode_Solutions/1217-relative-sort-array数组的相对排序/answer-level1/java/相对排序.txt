### 解题思路
因为题目中已经限定了数组中数字的范围。所以就可以使用创建大的数组来处理。  
然后就是讲所有元素放入桶中，按照arr2来取元素。最后讲没有的元素取出就好了。

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] map = new int[1001];
        int[] ref = new int[arr1.length];
        
        for(int i = 0; i < arr1.length; i++) {
            map[arr1[i]]++;
        }
        
        int cnt = 0;
        for(int i = 0; i < arr2.length; i++) {
            while(map[arr2[i]] > 0) {
                ref[cnt++] = arr2[i];
                map[arr2[i]]--;
            }
        }
        
        for(int i = 0; i < 1001; i++) {
            while(map[i] > 0) {
                ref[cnt++] = i;
                map[i]--;
            }
        }
        return ref;
    }
}
```