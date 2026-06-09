### 解题思路
1.头尾各1个指针
2.移动头指针，只要头指针出现偶数，判断尾指针，如果尾指针是偶数将尾指针前移，且每次移动后判断是否越界是否移动到头指针前面（是就返回数组），如果尾指针是奇数就对调，

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int l=nums.length;
        int start=0;
        int end=l-1;
        while(start<end){
           while(start<end&&(nums[start]&1)==1)
           start++;
           while(start<end&&(nums[end]&1)==0)
           end--;
           if(start<end){
               int item;
               item=nums[start];
               nums[start]=nums[end];
               nums[end]=item;
           }
        }
        return nums;
    }
}
```
### 更好的写法，增加扩展性，假如题目变成其他条件不是奇偶，只需要更改功能函数即可
```
class Solution {
    public int[] exchange(int[] nums) {
        if(nums.length==0||nums==null)return nums;
        int l=nums.length;
        int start=0;
        int end=l-1;
        while(start<end){
           while(start<end&&!func(nums[start]))
           start++;
           while(start<end&&func(nums[end]))
           end--;
           if(start<end){
               int item;
               item=nums[start];
               nums[start]=nums[end];
               nums[end]=item;
           }
        }
        return nums;
    }
    public boolean func(int x){
        return (x&1)==0;
    }
}
```
