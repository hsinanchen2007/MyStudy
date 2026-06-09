### 解题思路
这题思路并不难，关键在于超时的问题，如果你的for循环足够多，他就会出这种问题，包括排序，尽量使用时间短的排序方法。

### 代码

```java
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> sum = new ArrayList<>();
        Arrays.sort(arr);
        int min = arr[1]-arr[0];
        for(int i = 0;i<arr.length-1;i++) {
            if(min==arr[i+1]-arr[i]) {
                sum.add(Arrays.asList(new Integer[]{arr[i],arr[i+1]}));
            }
            if(min>arr[i+1]-arr[i]) {
                sum.clear();
                sum.add(Arrays.asList(new Integer[]{arr[i],arr[i+1]}));
                min = arr[i+1]-arr[i];
            }
        }
        
        return sum;


    }
}
```