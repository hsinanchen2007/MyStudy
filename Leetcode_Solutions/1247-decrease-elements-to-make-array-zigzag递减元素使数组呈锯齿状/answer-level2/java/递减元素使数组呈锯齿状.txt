执行用时 : 0 ms, 在所有 Java 提交中击败了 100.00% 的用户
内存消耗 : 34.3 MB, 在所有 Java 提交中击败了 100.00% 的用户

1、因为只会递减，所以只有求奇数索引和偶数索引下最小消耗
2、对于同一减数，被不同的被减数减去时，只保留最小的差（因为是负数）去累计
3、-1是因为‘对应的元素都大于相邻的元素’
以下代码
```
class Solution {
    public int movesToMakeZigzag(int[] nums) {
        int size=nums.length;
        int diOdd=0;//奇数索引
        int diEven=0;//偶数索引
        for (int i = 0; i < size; i++) {
            int temp1=0;
            int temp2=0;
            if(i%2==0){
                if(i-1>0) {
                    temp1=nums[i-1]-nums[i]<=0?nums[i-1]-nums[i]-1:0;
                }
                if(i+1<size) {
                    temp2=nums[i+1]-nums[i]<=0?nums[i+1]-nums[i]-1:0;
                }
                diEven+=temp1>temp2?temp2:temp1;
            }else {
                if(i-1>=0) {
                    temp1=nums[i-1]-nums[i]<=0?nums[i-1]-nums[i]-1:0;
                }
                if(i+1<size) {
                    temp2=nums[i+1]-nums[i]<=0?nums[i+1]-nums[i]-1:0;
                }
                diOdd+=temp1>temp2?temp2:temp1;
            }
        }
        if(diEven>diOdd) return Math.abs(diEven);
        else return Math.abs(diOdd); 
    }
}
```

