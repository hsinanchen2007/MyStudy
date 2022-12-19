开辟一个新空间，遍历传入的数组，偶数从头开始放在新空间，奇数从尾部开始放入新空间。
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] ret = new int[A.length];
        int i = 0;
        int j = A.length - 1;

        for(int k: A){
            if(k % 2 == 0){
                ret[i] = k;
                i ++;
            }
            else{
                ret[j] = k;
                j --;
            }
        }

        return ret;
    }
    
}