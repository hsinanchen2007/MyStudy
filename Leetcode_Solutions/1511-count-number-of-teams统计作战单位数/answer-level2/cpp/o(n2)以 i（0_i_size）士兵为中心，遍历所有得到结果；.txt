### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/bd67aeb086b0e9e191912d60cc751ef723c18770a38a475a990999269701e36d-image.png)

### 代码

```cpp
class Solution {
public:
    // 以某个士兵为中心，统计左边+右边；
    int numTeams(vector<int>& rating) {
        int size = rating.size();
        if(size<3) return 0;
        int ans = 0;
        for(int i = 1;i<size;i++){
            int left_min = 0;
            int left_max = 0;
            int right_min = 0;
            int right_max = 0;

            for(int j = 0;j<i;j++){
                if(rating[j]<rating[i]){
                    left_min++;
                }else if(rating[j]>rating[i]){
                    left_max++;
                }
            }
            for(int k = i+1;k<size;k++){
                if(rating[k]>rating[i]){
                    right_max++;
                }else if(rating[k]<rating[i]){
                    right_min++;
                }
            }
            ans += left_min*right_max;
            ans += left_max*right_min;
        }
        return ans;
    }
};
```