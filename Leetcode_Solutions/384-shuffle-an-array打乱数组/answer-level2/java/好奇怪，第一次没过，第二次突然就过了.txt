### 解题思路
想问这个复杂度怎么算鸭
### 代码

```java
class Solution {

    int[] numL;
    public Solution(int[] nums) {
        numL=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return numL;

    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        Random r=new Random();
        int[] flag=new int[numL.length];
        int[] res=new int[numL.length];
        int count=0;
        while(count<numL.length){
            int index=r.nextInt(numL.length);
            if(flag[index]==0){
                flag[index]=1;
                res[count]=numL[index];
                count++;
            }
        }
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
```