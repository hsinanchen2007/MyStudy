__右移遍历每一位的数字然后记录下和前一个的距离，动态取出最大值
__
```
class Solution {
    public int binaryGap(int N) {
       int max = 0;
      //记录当前位1和前一位1之间的距离
        int temp =-1;
        while(N!=0) {
//0b101100开始循环时右边几位为0的话，不计算距离
            if(temp>=0) {
                ++temp;
            }
//判断当前位是否为1 
            if((N&1)==1) {
                max=Math.max(max, temp);
                temp=0;
            }
            //右移一位
            N=N>>1;
        }
        return max;
    }
}
```
