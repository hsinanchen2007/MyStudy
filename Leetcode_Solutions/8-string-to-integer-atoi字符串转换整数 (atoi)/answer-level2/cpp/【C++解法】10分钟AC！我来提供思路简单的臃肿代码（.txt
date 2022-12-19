要点：
1.找到起点状态，根据状态判断下一部操作。
2.判断溢出。
```
class Solution {
public:
    int myAtoi(string str) {
        int p1 = -1,p2 = -1,flag = 0;
        for(int i = 0;i < str.size();i ++){
            if(str[i] == '-') flag = 1;
            else if(str[i] == '+') flag = 2;
            else if(str[i] >= '0' && str[i] <= '9') flag = 3;
            else if(str[i] == ' ') flag = 0;
            else flag = 4;
            if(flag){
                p1 = i;
                break;
            }
        }
        if(flag == 4 || p1 == -1) return 0;
        vector<int> s;
        if(flag == 1 || flag == 2) ++p1;
        for(int i = p1;i < str.size();i ++){
            if(str[i] >= '0' && str[i] <= '9'){
                //舍弃前导0
                if(str[i] == '0' && s.size() == 0) continue;
                else s.push_back(str[i]-'0');
            }
            else break;
        }
        if(!s.size()) return 0;
        if(s.size() > 10){
            if(flag == 1) return INT_MIN;
            else return INT_MAX;
        }
        long long tmp = 0;
        for(int i = 0;i < s.size();i ++){
            tmp *= 10;
            tmp += s[i];
        }
        if(flag == 1) tmp *= -1;
        if(tmp > (long long)INT_MAX) return INT_MAX;
        else if(tmp < (long long)INT_MIN) return INT_MIN;
        else return (int)tmp;
    }
};
```
