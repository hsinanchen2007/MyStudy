```
class Solution {
    public boolean validUtf8(int[] data) {
        int i=0,j=0,length=data.length;
        while(i<length){
            //单字节
            if(((byte)data[i]|0x7f)==(byte)0x7f)
                i++;
            //双字节
            else if(((byte)data[i]|0x1f)==(byte)0xdf){
                if(i+1<length
                  &&((byte)data[i+1]|0x3f)==(byte)0xbf)
                    i=i+2;
                else
                    return false;
            }
            //三字节
            else if(((byte)data[i]|0x0f)==(byte)0xef){
                if(i+2<length
                  &&((byte)data[i+1]|0x3f)==(byte)0xbf
                  &&((byte)data[i+2]|0x3f)==(byte)0xbf)
                    i=i+3;
                else
                    return false;
            }
            //四字节
            else if(((byte)data[i]|0x07)==(byte)0xf7){
                if(i+3<length
                  &&((byte)data[i+1]|0x3f)==(byte)0xbf
                  &&((byte)data[i+2]|0x3f)==(byte)0xbf
                  &&((byte)data[i+3]|0x3f)==(byte)0xbf)
                    i=i+4;
                else
                    return false;
            }
            else 
                return false;
        }
        return true;
    }
}
```