### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] tmp = new int[nums.length];
        for(int i=0;i<nums.length;i++){
            tmp[i]=nums[i];
        }
        int[] res = new int[nums.length];
        Arrays.sort(tmp);
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<tmp.length;j++){
                if(tmp[j]>=nums[i]){
                    res[i]=j;
                    break;
                }
            }
        }
        return res;
    }
}
```