看下注释就懂啦
```
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(!bills.size()) return true;
        int dollar5=0;//存储5元的美钞总数
        int dollar10=0;//存储10元的美钞总数
        for(int i=0;i<bills.size();++i){
            if(bills[i]==5) {dollar5+=5;}//5元美钞直接收入囊中
            else if(bills[i]==10) {  //10元美钞需要找零
                dollar5-=5;  
                if(dollar5<0) return false;
                else dollar10+=10;//将10元收入囊中  
                }
            else {//bills[i] =20;
              if(dollar10) {dollar10-=10;bills[i]-=10;}//如果有10元钞票就先用10元的找零
              dollar5-=(bills[i]-5);//用5元钞票找零
              if(dollar5<0) return false;
            }
        }
        return true;
    }
};
```
