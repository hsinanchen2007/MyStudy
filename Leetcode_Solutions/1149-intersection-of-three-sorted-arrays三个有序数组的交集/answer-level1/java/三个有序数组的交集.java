### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
       int [] hash=new int[2001];
       List<Integer> result=new ArrayList<>();
       for(int index=0;index<arr1.length;index++)
            hash[arr1[index]]++;
       for(int index=0;index<arr2.length;index++)
            hash[arr2[index]]++;
        for(int index=0;index<arr3.length;index++)
        {
            if(hash[arr3[index]]==2)
                result.add(arr3[index]);
        }
        return result;
    }
}
```