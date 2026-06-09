```
#include <iostream>
using namespace  std;
class Solution {
/*
当发生油箱的存油小于所消耗油时为空。
选择出发点。1，gas[i]>cost[i]。2,如果第一次选择的点不正确，则新的出发点，应在停止点之后的第一个gas[i]>cost[i]。
*/
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int num = gas.size();
        vector<int> a{};//存储差值大于0的点
        for(int i =0;i<num;i++){
            if (gas[i]>=cost[i]){
                a.push_back(i);
            }
        }
        int gas_sum=0;
        unsigned int start_num=0;
        int temp=-1;
        int temp_h;
        int break_num=0;
        
        vector<int> temp_gas {};
        vector<int> temp_cost{};
        
        //选择a[0]作为第一个出发的点
        for(int j=0;j<a.size();j++){
            //cout<<"j: "<<j<<'\n';

            if (a[j]<break_num){
                continue;
            }            
            start_num=a[j];
            cout<<"start_num: "<<start_num<<'\n';
            gas_sum =0;

            //auto* p = gas[start_num];
            
            for(int h=0;h<num;h++){

                //cout<<"h: "<<h<<'\n';
            //循环访问的话，加一个判断语句不就行了。如果大于NUM则对H进行处理
                    if (h+start_num>=num){
                        temp_h=h+start_num-num;
                    }
                    else{
                        temp_h =h+start_num;
                    }
                    //cout<<"temp_h: "<<temp_h<<'\n';
                

                    gas_sum += gas[temp_h]-cost[temp_h];

                    //cout<<"gas_sum: "<<gas_sum<<'\n';

                    //该点无法作为起始点。换新的出发点。
                    if(gas_sum <0){
                        break_num=temp_h;


                        break;

                
                    }
                    if(h==num-1 && gas_sum>=0){
                        temp=start_num;
                       
                        break;
                    }

            }
            if(temp != -1){
                break;
            }
            




        }


        return temp;
        
    }
};
```
![image.png](https://pic.leetcode-cn.com/2cd386fc8a19d7407c8a324f209c8da97990fbb35dbbe323ad8337d6822c86fd-image.png)

