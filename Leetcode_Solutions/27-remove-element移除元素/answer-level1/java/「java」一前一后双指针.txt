### 解题思路
此处撰写解题思路
![Screenshot_20200331_183045.png](https://pic.leetcode-cn.com/bcaa28a6116c2ee4ddb7345ebbe7c66166b711a69d1f7d1187ca4e5e5429a15c-Screenshot_20200331_183045.png)
一前一后双指针法。参考自别的大佬的写法。
### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int latter=0,former=0;
        while(former<nums.length)
        {
            if(nums[former]==val){
                former++;
                continue;
            }
            else{
                nums[latter++]=nums[former++];
            }
        }
        return latter;
    }
}
```