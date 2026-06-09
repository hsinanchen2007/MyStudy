```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>res(num_people, 0);
        if(candies == 0){
            return res;
        }
        int temp = 1;
        int index = 0;
        while(candies){
            res[index] += temp;
            index++;
            if(index == num_people){
                index =  0;
            }
            candies -= temp;
            
            if(candies <= temp){
                if(candies < 0){
                    res[index] += 0;
                }else{
                    res[index] += candies;
                }
                break;
            }
            temp++;
        }
        return res;
    }
};
```
![微信截图_20191206203012.png](https://pic.leetcode-cn.com/699eba0537b4f14cfc695f498a70556eb6c142b1854ccb5ed7fe851ec8a766e1-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191206203012.png)
