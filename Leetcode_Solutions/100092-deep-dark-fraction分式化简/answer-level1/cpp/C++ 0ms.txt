```
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        vector<int> res(2);
        int len = cont.size();
        if(len==1){  //特殊判断，比赛的时候这个case一直想不到，又不报错，心累哦0.0
            res[1]=1;
            res[0]=cont[0];
            return res;
        }
        for(int i=len-1;i>0;--i){
            if(i==len-1){  //倒数第一对，分母是最后一个数字，分子是最后一个数字乘倒数第二个数字
                res[1]=cont[i];
                res[0]=cont[i-1]*res[1]+1;
            }else{         //之后的每一个，分母是之前的分子，分子是之前的分子乘现在的a，最后加上之前的分母；可能画图比较好理解
                int temp = res[1];
                res[1]=res[0];
                res[0]=cont[i-1]*res[1]+temp;
            }
        }
        return res;
    }
};
```
