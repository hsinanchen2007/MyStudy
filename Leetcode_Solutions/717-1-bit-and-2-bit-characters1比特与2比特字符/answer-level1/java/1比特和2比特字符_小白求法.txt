```
//执行用时：0 ms，内存消耗35.8MB
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int len = bits.length;
        int i;
        boolean flag = true;//假设其就是以一比特字符结尾，则flag初始设为true
        for(i=0;i<len-1;){//所以直接不考虑最后一个值，那么判断条件为i<len-1
            if(bits[i]==1) i = i + 2;//如果数组值为1，则其为二比特字符，所以直接跳过下一个数组值，即+2
            else if(bits[i]==0) i = i + 1;//如果数组值为0，则正常+1
        }
        if(i==len) flag=false;//如果最后i的值等于**数组长度**，那么说明上面假设不成立
        return flag;               
    }                  
}  

```
