![360截图20200403164055309.jpg](https://pic.leetcode-cn.com/1ff15aaf1c0a75f6a1d37d9d0ba15fba02de055ab3b32464395383be98c75840-360%E6%88%AA%E5%9B%BE20200403164055309.jpg)

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<int> temp(200,0);
        int res=0;
        for(int i=0;i<J.length();i++){temp[J[i]]++;}
        for(int i=0;i<S.length();i++){
            if(temp[S[i]] > 0) res++;
        }
        return res;


    }
};