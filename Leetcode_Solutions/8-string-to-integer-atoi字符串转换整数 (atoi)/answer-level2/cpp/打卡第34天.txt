剑指offer写法
```
class Solution {
public:
    
    int myAtoi(string str) {
      int s = str.size();
      int i=0;
     int minus = 1;
      while(i<s && str[i] == ' '){
          i++;
      }
      if(i == s) return 0;
        if(str[i] == '+') {
              i++;
          }else if(str[i] == '-') {
              minus = -1;
              i++;
          }
      long num = 0;
      num = core(str.substr(i),minus);
      return (int)num;

        
    }
    long core(string d, int minus){
        long num=0;
        int s = d.size();
        int i=0;
        for(i=0;i<s;i++){
            if(d[i]<='9' && d[i]>='0'){
                num = 10*num + minus*(d[i]-'0');
                if(num>INT_MAX ){
                    return INT_MAX;
                }else if( num<INT_MIN){
                    return INT_MIN;
                }
            }else{

                break;
            }
        }
        
        return num;

    }
};

```
