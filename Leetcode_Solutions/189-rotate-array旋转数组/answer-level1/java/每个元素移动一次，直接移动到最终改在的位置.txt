执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 java 提交中击败了
95.53%
的用户
内存消耗 :
37.2 MB
, 在所有 java 提交中击败了
95.41%
的用户
```
class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        if (len <= 1 ) return;
        
        k = k % len;
        if (k == 0 ) return;
       
        int[] res = new int[len];
        for(int x=1; x<=k; x++){
            int last = len - x; //从最后一位开始
            if(res[last]==1)return;//记录是否该位置被覆盖过
            int temp = nums[last];//保存最后一位的值
            int index = last - k;
            if(index < 0) index+=len;//求哪个位置的值会放到last位置
            while(true) {
                nums[last] = nums[index];
                res[last] = 1;
                last = index;
                if( (index = last - k) < 0 ){
                    index = last - k + len;
                }
                if(index == len - x){
                    nums[last] = temp;
                    res[last] = 1;
                    break;
                }
            }
        }
        
    }
}
```
