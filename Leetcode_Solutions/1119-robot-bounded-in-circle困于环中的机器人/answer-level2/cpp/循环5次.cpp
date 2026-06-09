如果有环，循环四次一定能构成换，只需判断第五次循环是否比第四次循环新增加了点。
```
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int flag=0;
        set<pair<int,int>> s;
        pair<int,int> now={0,0};
        s.insert(now);
        int num1,num2;
        for(int i=0;i<5;++i){
            for(auto a:instructions){
                if(a=='L'){
                    flag=(flag+270)%360;
                }
                else if(a=='R'){
                    flag=(flag+90)%360;
                }
                else{
                    if(flag==90){
                        now.second+=1;
                    }
                    else if(flag==180){
                        now.first+=1;
                    }
                    else if(flag==270){
                        now.second-=1;
                    }
                    else{
                        now.first-=1;
                    }
                    if(!s.count(now)){
                        s.insert(now);
                    }
                }
            }
            if(i==3){
                num1=s.size();
            }
            if(i==4){
                num2=s.size();
            }
        }
       // cout<<num1<<" "<<num2<<endl;
        return num1==num2;
    }
};
```
