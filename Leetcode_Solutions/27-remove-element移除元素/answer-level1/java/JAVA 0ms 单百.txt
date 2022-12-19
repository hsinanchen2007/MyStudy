### 解题思路
双指针，一个寻找匹配的下标，另一个寻找不匹配的下标，然后进行移位

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums.length<1){
            return 0;
        }
        int t=0;//辅助下标
        int c=0;//计数
        for(int i=0;i<nums.length;i++){
            if(nums[i]==val){//匹配时
                t=i;//记录要替换的下标
                for(int j=i+1;j<nums.length;j++){//从i+1开始搜索
                    if(nums[j]!=val){//第一个不匹配的
                        c++;//计数+1
                        nums[t]=nums[j];//移位
                        nums[j]=val;//把原来的值替换成val，后面可能会在这里插入
                        break;
                    }
                }
            }else{//不匹配
                c++;
            }
        }
        return c;
    }
}
```