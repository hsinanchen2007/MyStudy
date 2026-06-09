### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int length = nums.length;
        int [] re = new int[length];
        for(int i = 0;i < length;i++){
            int num = nums[i];
            int inde = index[i];
            
            if(inde == i){
                re[i] = num;
            } else {
                // 只有小于 i,需要移动
                    for(int j = i - 1;j >= inde;j--){
                        re[j+1] = re[j];
                    }
                    re[inde] = num;
            }
        }
        return re;
    }
}
```