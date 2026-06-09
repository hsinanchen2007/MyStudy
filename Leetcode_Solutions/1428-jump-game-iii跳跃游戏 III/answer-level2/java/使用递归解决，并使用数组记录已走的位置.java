### 解题思路
![image.png](https://pic.leetcode-cn.com/5bddc85e9bf5fbd409e7f4d92bc28cf852823daa6a219daed7cc29dfdeb9f218-image.png)

使用一个数组用来避免重复判断已经走过的路

### 代码

```java
class Solution {
    //使用一个数组记录走过的路
    boolean[] canReach;
    public boolean canReach(int[] arr, int start) {
        canReach = new boolean[arr.length];
        return findCanReach(arr,start); 
    }
    private boolean findCanReach(int[] arr,int start){
        //当目标超出数组范围或者已经走过，直接返回false
        if(start>=arr.length||start<0||canReach[start]){
            return false;
        }
        if(arr[start]==0){
            return true;
        }
        //标记此路已经走过
        canReach[start] = true;
        return findCanReach(arr,start+arr[start])||findCanReach(arr,start-arr[start]);
    }
}
```