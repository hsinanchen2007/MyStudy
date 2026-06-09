### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        //vector<int> sortedRating = rating;
        int unitCnt = 0;
        
        //sort(sortedRating.begin(), sortedRating.end(), [](const int &a, const int &b) {
          //  return a < b;
        //}
        for (int i = 0; i < rating.size(); i++) {
            for (int j = i+1; j < rating.size(); j++) {
                if (rating[j] > rating[i]) {  // ascend up
                    for (int m = j+1; m < rating.size(); m++) {
                        if (rating[m] > rating[j]) {
                            unitCnt++;
                        }
                    } 
                } else {
                    for (int m = j+1; m < rating.size(); m++) {
                        if (rating[m] < rating[j]) {
                            unitCnt++;
                        }
                    }
                }
            }
        }
        return unitCnt;
    }
};
```