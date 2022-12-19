class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x^y;
        int res=0;
        while(temp){
            res++;
            temp=temp&(temp-1);
        }
        return res;
    }
};