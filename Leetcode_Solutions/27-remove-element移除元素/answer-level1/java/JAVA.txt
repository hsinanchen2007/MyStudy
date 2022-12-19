### 解题思路
此处撰写解题思路
我的思路:
    既然不能使用临时的数组，那么只能写在原数组中，那要如何去写才不会发什么错误？
是这样的，我们循环判断原来的数组中的值有没有等于这个传进来的值，如果有的话，我们用
临时的一个变量j赋值为0，然后将原始的数组放入到原来的数组，原来的数组是用i的这个下标，
而被辅助的用j赋值的，累加，最后返回的是整数就是j了；
### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int j=0;
        for(int i=0;i<nums.length;i++){
                if(nums[i]!=val){
                    nums[j]=nums[i];
                    j++;
                }
        }
        return j;
    }
}
```