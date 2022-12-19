### 解题思路
主要思想就是左右两边遍历，
左边：a0=1; a1=a0; a2=a0*a1; a3=a0*a1*a2;
右边：a3=1; a2=a3; a1=a3*a2; a0=a3*a2*a1;
然后左右两边相乘。就是最后的结果集。
方法1：是遍历一遍，通过双指针和判断来计算和存放结果集。
方法2：通过两次遍历。
不知道为什么，两次遍历比一次遍历判断要快。

### 代码
方法1：
```class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length-1;
        int sum = 1;
        int sumL = 1;
        int[] arr = new int[nums.length];
        for(int i=0;i<=n;i++){
            if(i>n-i){
                arr[i] = sum*arr[i];
                arr[n-i]=sumL*arr[n-i];
            }else if(i==n-i){
                arr[i] = sum*sumL;
            }else {
                arr[i]=sum;
                arr[n-i]=sumL;
            }
            sum*=nums[i];
            sumL*=nums[n-i];
        }
        return arr;
    }
}



方法2：
```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length - 1;
        int sum = 1;
        int[] arr = new int[nums.length];
        for(int i=0;i<=n;i++){
            arr[i] = sum;
            sum*=nums[i];
        }
        sum = 1;
        for(int i=n;i>=0;i--){
            arr[i]*=sum;
            sum*=nums[i];
        }
        return arr;

    }
}
```