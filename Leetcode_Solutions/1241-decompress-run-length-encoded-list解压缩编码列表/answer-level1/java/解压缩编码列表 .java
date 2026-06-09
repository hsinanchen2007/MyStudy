### 解题思路
我的代码怎么总是怎么幼稚简单.......
好像没用到题目的列表........

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int geshu = 0;
        if(nums.length%2!=0){
            System.out.println("error");
        }
        for (int i=0;i<nums.length;i++){
            if(i%2==0){
                geshu+=nums[i];
            }
        }

        int[] out = new int[geshu];
        int o=0;
        for (int i=0;i<nums.length;i++){
            if(i%2==0){
               for(int m=0;m<nums[i];m++){
                   out[o]=nums[i+1];
                   o++;
               }
            }
        }
        

        return out;
    }
}
```