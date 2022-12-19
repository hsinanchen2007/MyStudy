### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int cur=0;
        int l=0,r=-1;//左右指针为窗口边界
        int res=nums.length+1;
        while(l<nums.length){
            if(r+1<nums.length&&cur<s){//先右端开始移动
                r++;
                cur+=nums[r];
            }else{//左端进行调整
                cur-=nums[l];
                l++;
            }
            
            if(cur>=s){
                res=Math.min(r-l+1,res);
            }
        }
        if(res==nums.length+1){
            return 0;
        }
        return res;
    }
}
```