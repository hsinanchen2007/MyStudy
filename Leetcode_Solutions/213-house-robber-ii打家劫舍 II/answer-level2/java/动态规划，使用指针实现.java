对于循环的情况，可进行两次判断：从0到n-1和从1到n，最后返回较大者。
因为每次抢劫的累计值在整个遍历过程中只使用一次，这里可用指针进行代替。
```
class Solution {
    public int rob(int[] nums) {
        //入参检验
        if(nums == null){
            return 0;
        }
        //对一个元素的数组单独处理
        if(nums.length == 1){
            return nums[0];
        }
        //声明两个指针，一个指向上前两次的累计值，一个指向上前一次
        int lastTime = 0;
        int now = 0;
        //跳过最后一个元素
        for(int i = 0; i < nums.length - 1; i++){
            //保存
            int temp = now;
            now = Math.max(now, lastTime + nums[i]);
            //用now更新lastTime
            lastTime = temp;
        }
        lastTime = 0;
        int otherNow = 0;
        //跳过第一个元素
        for(int i = 1; i < nums.length; i++){
            int temp = otherNow;
            otherNow = Math.max(otherNow, lastTime + nums[i]);
            lastTime = temp;
        }
        return Math.max(now, otherNow);
        
    }
}
```
