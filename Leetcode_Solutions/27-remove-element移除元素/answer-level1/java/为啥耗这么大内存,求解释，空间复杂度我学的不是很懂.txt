### 解题思路
```
为啥我这种解法会消耗这么多内存
执行用时0ms 击败了100%的用户



![解题.png](https://pic.leetcode-cn.com/819a955def145e369b868c348a88ff88e15f74cbdb64e41c3c0628c6c7e87699-%E8%A7%A3%E9%A2%98.png)

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums==null||nums.length==0){
            return 0;
        }
        int i=0;
        for(i=0;i<nums.length;i++){
            if(nums[i]==val)
                break;
        }
        int j=i+1;
        for(j=i+1;j<nums.length;){
            if(nums[j]==val){
                j++;
            }else{
                nums[i]=nums[j];
                i++;
                j++;
            }
        }

       return i;
    }
}


