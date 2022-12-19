### 解题思路
![image.png](https://pic.leetcode-cn.com/e247bc174d08c2cf0381f79e8e183ced73ada5f7d7e9da1304c5fef8eb73b4e0-image.png)

直接回溯，但要考虑好边界问题
跳不到的情况有三种：左出界，右出界，循环跳，因此递归的basecase要详细设计一下
这里要注意跳的过程中并不是只有跳回起点一种循环跳的情况，即数组中可能存在多组不同的循环跳情况
这里使用了一个标志数组，只要跳到的数组位置在之前的递归中跳到过，即可认为这种情况是循环跳
### 代码

```java
class Solution {
    public boolean canReach(int[] arr, int start) {
        int[] mark = new int[arr.length];
        if(arr.length == 0){
            return false;
        }
        return backTrack(arr, start, mark);
    }

    public boolean backTrack(int[] arr, int start, int[] mark){
        if(start > arr.length - 1 || start < 0 || mark[start] == 1){
            return false;
        }
        int mostStep = arr[start];
        boolean flag = true;
        if (mostStep == 0){
            return true;
        }
        mark[start] = 1;
        flag = backTrack(arr, start - mostStep, mark);
        flag = flag || backTrack(arr, start + mostStep, mark);

        return flag;
    }
}
```