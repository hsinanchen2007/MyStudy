count用来统计10******这种二进制的数个数，然后根据每个字节数的特点进行判断，从后向前遍历，
可以用位运算，也可以直接比较数的范围
```
class Solution {
    public boolean validUtf8(int[] data) {
        int n=data.length;
        if(n<1) return true;
        int count=0;
        for(int i=n-1;i>=0;i--){
             if(data[i]>=248) return false;
            //第一种
            if((data[i]&128) == 0){
                if(count!=0) return false;
                continue;
            }
            if((data[i]&240) == 240){
                if(count!=3) return false;
                count=0;
                continue;
            }
            if((data[i]&224) == 224){
                if(count!=2) return false;
                count=0;
                continue;
            }
            if((data[i]&192) == 192){
                if(count!=1) return false;
                count=0;
                continue;
            } 
            if((data[i]&128) == 128){
                count++;
            }
        }
        if(count!=0) return false;
        return true;
    }
}
```
