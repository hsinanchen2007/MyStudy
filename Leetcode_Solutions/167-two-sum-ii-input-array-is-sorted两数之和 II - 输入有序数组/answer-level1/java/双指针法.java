### 解题思路
1.如果两个指针指向元素的和等于给定值，那么它们就是我们要的结果。
2.如果两个指针指向元 素的和小于给定值，我们把左边的指针右移一位，使得当前的和增加一点。
3.如果两个指针指向元 素的和大于给定值，我们把右边的指针左移一位，使得当前的和减少一点。 
4.直到找到位置，返回



### 代码

```java
class Solution {
    public int[] twoSum(int[] arr, int target) {
        int left =0,right = arr.length-1;
        while(left<right){
            if(arr[left]+arr[right]==target)break;
            else if(arr[left]+arr[right]>target)right--;
            else left++;
        } 
        return new int[]{left+1,right+1};
    }

}
```