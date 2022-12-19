
```
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int fengzi,fengmu;
        fengmu =1;
        fengzi =0;//fengzi/fengmu=0/1，即0，不影响最终结果
        
        for(int i =cont.size()-1;i>0;i--){
            fengzi += cont[i]*fengmu;

            fengmu = fengmu^fengzi;//这三行使使用位运算实现两个数字的交换swap功能
            fengzi = fengmu^fengzi;
            fengmu = fengmu^fengzi;
        }
        
        fengzi+= cont[0]*fengmu;//因为a0不需要倒分数，所以单独处理


        //现在只需使分子和分母互质就可以了。
        int min = fengzi>fengmu?fengmu:fengzi;
        for(int i =sqrt(min);i>1;i--){
            if(fengzi%i==0&&fengmu%i==0){
                fengzi/=i;
                fengmu/=i;
            }
        }
        
        cont.clear();//不想另外开设空间了，就在原地修改吧
        cont.push_back(fengzi);
        cont.push_back(fengmu);
        return cont;
    }
};
```
