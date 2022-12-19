思路： 线性扫描法，遇到0跳一位，遇到1跳位，判断最后一位是否为0.
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int i = 0;
        while(i < bits.length){
            if(bits[i] == 0) {
                i ++;
                if(i == bits.length) {
                    return true;
                }
            } else {
                i += 2;
                if(i == bits.length ) {
                    return false;
                } else if( i > bits.length) {
                    if(bits[i-2] == 0 ) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
        return false;
    }
}