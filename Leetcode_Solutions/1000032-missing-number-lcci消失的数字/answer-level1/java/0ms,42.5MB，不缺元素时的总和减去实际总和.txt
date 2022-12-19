### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/8586d31625611670e46150b06d4a352e4c3723de7468a07c0dd4a4a320afc9f8-%E6%8D%95%E8%8E%B7.PNG)
超级简单的算法，不缺元素时总和就是所有元素下标之和再加上数组长度，实际总和直接加起来，用一个循环就好了

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int s=0;//实际总和
        int l=0;//不缺元素时的总和
        for(int i=0;i<nums.length;i++){
            s+=nums[i];
            l+=i;
        }
        l+=nums.length;
        l-=s;
        return l;

    }
}
```