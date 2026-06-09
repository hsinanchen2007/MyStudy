### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        int n = nums.length;
        while(i < n){
            if(nums[i] == val){
                nums[i] = nums[n-1];
                n--;
            }
            else{
                i++;
            }
        }
        return i;
    }
}
```

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int p = 0;
        for(int i = 0; i < nums.length;i++){
            if(nums[i]!=val){
                int tmp = nums[p];
                nums[p] = nums[i];
                nums[i] = tmp;
                p++;
            }
        }
        return p;
    }
}
```