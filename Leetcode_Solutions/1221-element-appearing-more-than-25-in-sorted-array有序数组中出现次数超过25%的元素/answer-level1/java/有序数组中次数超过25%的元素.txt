### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findSpecialInteger(int[] arr) {
    /*审题：1.这个数组中只有一个这样的数，说明找到之后就可以返回了，不用继续找。
    2.数组是有序的，说明如果这个元素恰好出现次数超过总数的25%，则它后面的arr.length/4个元素都与该元素值一样。*/
    int s=arr.length/4;
    for(int i=0;i<arr.length;i++)
    {
        if(arr[i]==arr[i+s])
            return arr[i];
    }
    return -1;    
    }
}
```