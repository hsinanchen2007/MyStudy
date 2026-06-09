class Solution {
    public int reverse(int x) {
        int tmp = 0;
        int res = 0;
        while(x != 0){
            tmp = tmp * 10 + x % 10;
            if((tmp - x % 10) / 10 != res) //越界情况1534236469
                return 0;
            x = x / 10;
            res = tmp;
        }
        return res;
    }
}