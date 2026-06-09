将每个数字都转成32位的二进制数字，然后累加每一位数字，记录到arr数组中。如果某一位的个数不能被3整除，说明只出现一次的那个数字的二进制表达，在这一位上是1。
```
public int singleNumber(int[] nums) {
    int[] arr=new int[32];
    for(int num:nums){
        for(int i=0;i<32;i++){
            arr[i]+=(num&1);
            num>>=1;
        }
    }
    int ans=0;
    for(int i=0;i<32;i++){
        if(arr[i]%3==1){
            ans+=(1<<i);
        }
    }
    return ans;
}
```
