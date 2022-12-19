执行用时 :1 ms, 在所有 Java 提交中击败了99.70%的用户
内存消耗 :37.1 MB, 在所有 Java 提交中击败了83.04%的用户

```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {     
        int length = bits.length;

        //长度为1，因为最后一位必定为0，结果为true
        if (length == 1) {
            return true;         
        }

        //长度为2，看第一位为0 or 1，为0则为true，反之为false；
        if (length == 2) {
            if (bits[0] == 0) {
                return true;
            }else{
                return false;
            }
        }

        //长度为3，第一位为1，结果为true,第一位为0则看第二位，
        //第二位为1，结果为false；
        if (length == 3) {
            if (bits[0] == 1) {
                return true;
            }else if(bits[1] == 1){
                return false;
            }else{
                return true;
            }
        }


        //当某位值为0时候，i++;
        //当某位值为1时候，i += 2；
        for (int i = 0; i < length - 1; i++ ) {
            if (bits[i] == 0) {
                //当倒数第二位为0的时候
                if (i == length - 2) {
                    return true; 
                //当倒数第三位为0的时候
                }else if (i == length - 3) {
                    //且当倒数第二位为0的时候
                    if(bits[i + 1] == 0){
                         return true; //返回 true;
                    }else{
                    //且当倒数第二位为1的时候
                        return false;
                    }               
                 }
            }else{//到b[i]为1的时候
                 //当倒数第二位为1的时候
                 if (i == length - 2) {
                    return false; //返回false;
                 //当倒数第三位为1的话
                 }else if (i == length - 3) {
                    return true; //返回 true;
                 }
                i++; //当bits[i] = 1时候，跳两个
            }
        
        }
        return false;
    }
}

```
