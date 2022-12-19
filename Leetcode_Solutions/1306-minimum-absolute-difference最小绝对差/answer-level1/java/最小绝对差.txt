### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        ArrayList<List<Integer>> list=new ArrayList<>();
      int min=Integer.MAX_VALUE;
      Arrays.sort(arr);
      for(int i=0;i<arr.length-1;i++){
          if(Math.abs(arr[i]-arr[i+1])<min)
          min=Math.abs(arr[i]-arr[i+1]);
      }
      for (int i = 1; i < arr.length; i++) {
            if (Math.abs(arr[i] - arr[i - 1]) == min) {
                 ArrayList<Integer>list1=new ArrayList<>();
                list1.add(arr[i - 1]);
                list1.add(arr[i]);
                list.add(list1);
            }
      }
      System.out.println(min);
      return list;
    }
}
```