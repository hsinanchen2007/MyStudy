从1开始，到平方根结束，分两个遍历，定义一个s作为标志，那个小取哪个加入结果

```
class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> res;
        int qrt1 = sqrt(num+1);
        int qrt2 = sqrt(num+2);
        int min = INT_MAX;
        int flag = 0;
        for(int i=1;i<=qrt1;i++){
            if((num+1)%i == 0){
                if(min >= abs(i-(num+1)/i)){
                    min = abs(i-(num+1)/i);
                    flag = i;
                }
            }
        }
        int s = 0;
        for(int i=1;i<=qrt2;i++){
            if((num+2)%i == 0){
                if(min >= abs(i-(num+2)/i)){
                    min = abs(i-(num+2)/i);
                    flag = i;
                    s = 1;
                }
            }
        }
        res.push_back(flag);
        res.push_back(s==0? (num+1)/flag:(num+2)/flag);
        return res;
    }
};
```
