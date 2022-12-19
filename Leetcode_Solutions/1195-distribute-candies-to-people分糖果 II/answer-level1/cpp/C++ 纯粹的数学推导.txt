### 解题思路
这道题目的核心就是 $n*(n+1)/2 < candies$
算出能正常分配前的最后一个数，然后，就可以按需分配了。
这里注意轮转的方法：  i % num_people，就可以了。

### 代码

```cpp
class Solution {
public:
    //先算到多少个能够正常给，然后，再进行后续的处理
    vector<int> distributeCandies(int candies, int num_people) {
        //n(n+1)/2 < candies;
        int small_index = floor(sqrt(2*candies));
        if(small_index * (small_index + 1) > 2 * candies) small_index--;
        int last_cound = candies - small_index * (small_index+1)/2;
        cout << small_index << " " << last_cound << endl;
        //先按照全部的放进去，再分给小朋友
        vector<int> res(small_index+1,0);
        for(int i=0;i<res.size()-1;i++){
            res[i] = i+1;
        }
        res[res.size()-1] = last_cound;
        vector<int> result(num_people,0);
        for(int i=0;i<res.size();i++){
            result[i%num_people] = result[i%num_people] + res[i];
        }
        return result;
    }
};
```