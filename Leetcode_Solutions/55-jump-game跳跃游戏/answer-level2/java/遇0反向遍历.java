### 解题思路
执行用时 :
1 ms
, 在所有 java 提交中击败了
100.00%
的用户
内存消耗 :
38.4 MB
, 在所有 java 提交中击败了
94.90%

遇到0反向遍历查找能否跳过~

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length<2) return true; 
        for(int i= 0;i<nums.length;i++){
            if (nums[i] == 0){
                int max = 0;
                int num0 = 0;
                for(int j=i-1;j>=0;j--){
                   if (max < (nums[j]-i+j)){
                       max = (nums[j]-i+j);
                   }
                };
                for(int k=i+1;k<nums.length;k++){
                    if (nums[k] == 0){
                        num0 += 1;
                    }else{
                        break;
                    };
                };
                if (num0 > max || ( num0 == max && (num0 +i)<(nums.length-1))){
                    return false;
                };
            }
        }
        return true;
    }
}
```