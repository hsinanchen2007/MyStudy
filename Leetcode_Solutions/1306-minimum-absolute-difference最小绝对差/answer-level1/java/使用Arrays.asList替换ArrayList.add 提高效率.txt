### 解题思路
先排序,后比较,但是发现使用ArrayList.add 方法如果看源码的话,会知道add的过程中,会进行几次比较验证,所以速度其实是比较慢的,
如果用asList则没有这个问题,比使用add更快一点.

### 代码

```java
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
      List<List<Integer>>   listList = new ArrayList<>();
        if (null == arr || arr.length < 2)
            return listList;
        Arrays.sort(arr);
        int min = Integer.MAX_VALUE;
        int abs ;
        for (int i = 0; i < arr.length - 1; i++){
            abs = arr[i+1] - arr[i];
            if (abs < min)
                 min = abs;
        }
        for (int i = 0; i < arr.length - 1; i++){
            abs = arr[i+1] - arr[i];
            if (abs == min)
                listList.add(Arrays.asList(arr[i], arr[i+1] ));
        }
        return listList;
    }
}

    

```