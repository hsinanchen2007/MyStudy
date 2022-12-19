```
bool cmp(const int &a,const int &b){return a>b;}
class Solution {/*思路：按照两地价格差的最大值从大到小进行排序分配即可，但是该比较函数cmp写不出来*/
public:


    int twoCitySchedCost(vector<vector<int>>& costs) {
        //思路：将差价从大到小来进行排序
        vector<int> vec;
        int A=0;//飞往A市的人数
        int B=0;//飞往B市的人
        int sum=0;
        int len=costs.size();
        for(int i=0;i<costs.size();++i){

         vec.push_back(abs( costs[i][0]-costs[i][1] ));
        }
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i<vec.size();++i){//cout<<"vec[i]="<<vec[i]<<endl;
            for(int j=0;j<costs.size();++j){//
                if(abs(costs[j][0]-costs[j][1])==vec[i] ){//cout<<"costs[j][0]+costs[j][1]="<<costs[j][0]+costs[j][1]<<endl;
                    if(A==len/2){++B;sum+=costs[j][1];costs.erase(costs.begin()+j);}
                    else if(B==len/2){++A;sum+=costs[j][0];costs.erase(costs.begin()+j);}
                    else if( costs[j][0]-costs[j][1]<=0 && A<len/2  ){++A;sum+=costs[j][0];costs.erase(costs.begin()+j);}//飞往A
                    else if( costs[j][0]-costs[j][1]>=0 && B<len/2  ){++B;sum+=costs[j][1];costs.erase(costs.begin()+j);}//飞往B
                   
                    
                    
                }
            }
            }
       return sum;
    }
};
```
