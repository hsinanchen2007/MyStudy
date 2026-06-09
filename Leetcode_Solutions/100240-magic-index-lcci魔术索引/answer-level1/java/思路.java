### 解题思路
此处撰写解题思路
我的思路:
    魔术索引就是判断当前数组的值是否和下标一样，如果一样那么就返回当前这个值，因为第一个发现的值肯定就是索引中最小的一个
值嘛，找到就记录下来true一定要跳出循环，否则，没找到就记录false
### 代码

```java
class Solution {
    public int findMagicIndex(int[] nums) {
        boolean flag=false;
        int index=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==i){
                index=nums[i];
                flag=true;
                break;
            }else{
                flag=false;
            }
        }
        if(flag){
            return index;
        }else{
            return -1;
        }
    }
}
```