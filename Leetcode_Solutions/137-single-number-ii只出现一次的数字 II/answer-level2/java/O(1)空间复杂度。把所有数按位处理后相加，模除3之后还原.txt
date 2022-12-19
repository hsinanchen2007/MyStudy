执行结果：
通过
显示详情
执行用时 :
8 ms
, 在所有 Java 提交中击败了
34.91%
的用户
内存消耗 :
36.9 MB
, 在所有 Java 提交中击败了
95.94%
的用户
```
class Solution {
    public int singleNumber(int[] nums) {
        if(nums.length==1)return nums[0];
        int[] res = new int[33];
        for(int i=0; i<nums.length; i++){
            int k = nums[i];
            if(k<0){
                res[32]++;
            }
            int x=0;
            while(k!=0){
                res[x++]+=k%2;
                k = k/2;
            }
        }
        int z=0;
        int pow=1;
        for(int i=0; i<31; i++){
            int zz = res[i];
            if(zz%3==0){
                zz=0;
            }else{
                zz=1;
            }
            z+=pow*zz;
            pow<<=1;
        }
        if(res[32]%3!=0){
            if(res[31]%3!=0){
                return Integer.MIN_VALUE;
            }else{
                z=z*-1; 
            } 
        }
        return z;
    }
}
```
