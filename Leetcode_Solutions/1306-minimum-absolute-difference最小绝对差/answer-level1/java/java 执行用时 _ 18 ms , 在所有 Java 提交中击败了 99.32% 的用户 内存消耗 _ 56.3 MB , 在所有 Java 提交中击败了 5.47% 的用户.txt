### 解题思路
两个for循环，第一个找出绝对差，第二个添加list。

### 代码

```java
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        Arrays.sort(arr);   // -->先对数组排序
        int absDiff = Integer.MAX_VALUE;
        for(int i = 0;i<arr.length-1;i++){ //  -->第一个for循环找出最小绝对差
            absDiff =  Math.min(absDiff,arr[i+1] - arr[i]);
        }
        for(int i = 0;i<arr.length-1;i++){ //  -->第二个for循环添加进list
            if(arr[i+1] - arr[i] == absDiff){
                List<Integer> temp = new ArrayList<>();
                temp.add(arr[i]);
                temp.add(arr[i+1]);
                ans.add(temp);
            }
        }
        return ans;
    }
}
```