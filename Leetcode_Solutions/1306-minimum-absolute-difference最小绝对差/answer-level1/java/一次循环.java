### 解题思路
一次循环，不听更新最小差，然后更新列表

### 代码

```java
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> list = new ArrayList<>();
        int min = 0;
        for(int i = 1;i<arr.length;i++){
            if(min!=0){
                if(min > (arr[i]-arr[i-1])){
                    list.clear();
                    list.add(Arrays.asList(arr[i-1],arr[i]));
                    min = arr[i]-arr[i-1];
                }else if(min == (arr[i]-arr[i-1])){
                    list.add(Arrays.asList(arr[i-1],arr[i]));
                }
            }else {
                min = arr[i]-arr[i-1];
                list.add(Arrays.asList(arr[i-1],arr[i]));
            }
        }
        return list;
    }
}
```