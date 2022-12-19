    解题思路：将[left,right]区间每个数直接与自身包含的每个数进行整除计算，期间如有不能整除的情况跳出循环，最后比较temp是否等于0。见代码：


class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>res;
        for(int i= left;i<=right;++i){
            int temp=i;
            while(i!=0){
                if(temp%10==0||i%(temp%10)!=0) break;
                temp=temp/10;
            }
            if(temp==0)res.push_back(i);
        }
        return res;
    }
};