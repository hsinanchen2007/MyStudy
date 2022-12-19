### 解题思路
先把特殊情况一个个的找出来，每找出来一个就删掉一个，再把常规情况找出来，最后算合

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        string::size_type position;
        int sum=0;
        while((position=s.find("IV"))!=s.npos){
            s.erase(position,2);
            sum=sum+4;
        }
        while((position=s.find("IX"))!=s.npos){
            s.erase(position,2);
            sum=sum+9;
        }
        while((position=s.find("XL"))!=s.npos){
            s.erase(position,2);
            sum=sum+40;
        }
        while((position=s.find("XC"))!=s.npos){
            s.erase(position,2);
            sum=sum+90;
        }
        while((position=s.find("CD"))!=s.npos){
            s.erase(position,2);
            sum=sum+400;
        }
        while((position=s.find("CM"))!=s.npos){
            s.erase(position,2);
            sum=sum+900;
        }
        while((position=s.find("I"))!=s.npos){
            s.erase(position,1);
            sum=sum+1;
        }
        while((position=s.find("V"))!=string::npos){
            s.erase(position,1);
            sum=sum+5;
        }
        while((position=s.find("X"))!=string::npos){
            s.erase(position,1);
            sum=sum+10;
        }
        while((position=s.find("L"))!=string::npos){
            s.erase(position,1);
            sum=sum+50;
        }
        while((position=s.find("C"))!=string::npos){
            s.erase(position,1);
            sum=sum+100;
        }
        while((position=s.find("D"))!=string::npos){
            s.erase(position,1);
            sum=sum+500;
        }
        while((position=s.find("M"))!=string::npos){
            s.erase(position,1);
            sum=sum+1000;
        }
        return sum;
    }
};
```