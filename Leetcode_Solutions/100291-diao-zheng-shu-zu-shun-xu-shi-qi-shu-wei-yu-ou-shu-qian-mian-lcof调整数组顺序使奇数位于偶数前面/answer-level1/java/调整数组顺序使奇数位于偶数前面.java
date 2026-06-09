![微信截图_20200223133235.png](https://pic.leetcode-cn.com/f81d23e7b0f7b6147f208e7713d1a04b155183ae5e0dc9fc3fe1a06aaa909441-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200223133235.png)

### 解题思路
开辟新数组，扫描原始数组填充新数组。
奇数从新数组头部开始填充，偶数从新数组尾部开始填充，因为新数组和原始数组长度相同，遍历完成即可，不用做起始、结束索引多余的判断。

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        if(nums==null){
            return null;
        }
        int len=nums.length;
        int[] numsNew=new int[len];
        int start=0,end=len-1;
        for(int i=0;i<len;i++){
            if((nums[i]&1)==1){
                numsNew[start++]=nums[i];
            }else{
                numsNew[end--]=nums[i];
            }
        }
        return numsNew;
    }
}
```