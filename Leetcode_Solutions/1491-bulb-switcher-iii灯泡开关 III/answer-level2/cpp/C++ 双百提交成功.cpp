
```c++
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int count = 0 ,sum = 0;
        int addSum = 1;
        for(int i = 0;i < light.size();i++){
            sum += light[i];
            int len = i + 2;
            if(sum == addSum){
                count++;
            }
            addSum += len;
        }
        return count;
    }
};
```

