```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int num=0;
        while(candies>0){
            for(int i=0;i<num_people;i++){
                num++;
                if(candies>=num){
                    res[i] +=num;
                    candies -=num;
                } 
                else{
                    res[i] +=candies;
                    candies=0;
                } 
            }
        }
        return res;
    }
};
```
```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int num=0;
        while(candies>0){
            for(int i=0;i<num_people;i++){
                num++;
                res[i] +=candies>=num ? num:candies;
                candies =candies>=num ? candies-num:0;
            }
        }
        return res;
    }
};
```
```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int num = 0;
        while (candies>0) {
            res[num % num_people] += min(candies, num+1);
            candies -= min(candies,num+1);
            num++;
        }
        return res;
    }
};
```


