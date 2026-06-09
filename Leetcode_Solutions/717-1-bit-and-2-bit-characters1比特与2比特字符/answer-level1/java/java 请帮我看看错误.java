```angelscript
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int last = bits.length-1;
        if(last==0){
            return true;
        }
        if(last==1){
            if(bits[0]==1){
                return false;
            }else{
                return true;
            }
        }
        if(bits[last-1]==0){
            return true;
        }else if(bits[last-1]==1){
            if(bits[last-2]==0){
                return false;
            }else{
                // 有很多可能姓
                int i = last-2;
                while(i>=0){
                    int t = bits[i];
                    if(t==0||i==0){
                        int s = last-i;
                        if(s%2==1){
                            return true;
                        }else{
                            return false;
                        }
                    }else{
                        i--;
                    }
                }
            }
        }
        return true;
    }
}
```
请问这个为什么不对呢
我也是从最后一位遍历到0或者到头，那么中间都是1，我是将最后一位减去0所在的位数，然后%2，如果是0就是说明所有的都是二比特，如果为1就是最后一位是一比特。截取的字符串我认为是类似011...10中间有n个1,但是编译不通过