### 解题思路
求和公式，先求完整分发的轮次，再求最后一次不完整的分发

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int k = 0;//记录分糖果的轮次
        vector<int> ans(num_people,0);
        //tmp_sum，第k轮分完所有小朋友糖果的总数
        int tmp_sum = (k*(k+1)*num_people*num_people+(k+1)*num_people*(num_people+1))/2;
        //找到分完的完整的轮数k，再在k+1轮中计算能分的小朋友
        while(tmp_sum <= candies){
            k++;
            tmp_sum = (k*(k+1)*num_people*num_people+(k+1)*num_people*(num_people+1))/2;
        }
        k--;
        //计算完整的k轮次各个小朋友的糖果总数
        for(int i = 0;i<num_people;i++){
            ans[i] = k*(k+1)*num_people/2+(k+1)*(i+1);
        }
        //完整的k轮次之后剩余的糖果数
        int delt = candies-(k*(k+1)*num_people*num_people+(k+1)*num_people*(num_people+1))/2;
        k++;
        int j = 0;
        //计算第k+1轮不完整的分发，小朋友分发的糖果数
        while(delt > 0){
            if(delt>=k*num_people+j+1){
                delt -= k*num_people+j+1;
                ans[j] += k*num_people+j+1;
                j++;
            }
            else{
                ans[j] += delt;
                break;
            }
        }
        return ans;
    }
};
```