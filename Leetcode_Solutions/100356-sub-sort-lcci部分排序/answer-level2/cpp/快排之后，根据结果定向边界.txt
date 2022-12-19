### 解题思路
1. 简单写直接循环遍历找到两个边界算法为O（N^2）
2. 快排可以达到O（NlogN）

### 代码

```cpp
class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int>ans(2, -1);
        if(array.size()<2) return ans;
        vector<int>copy(array);
        sort(copy.begin(), copy.end());
        for(int i=0; i<array.size(); i++){
            if(array[i]>copy[i]) {
                ans[0]=i;
                break;
            }
        }

        if(ans[0]==-1) return ans;
        else{
            for(int i=array.size()-1; i>=ans[0]; i--){
                if(array[i]<copy[i]){
                    ans[1]=i;
                    break;
                }
            }
        }


        return ans;
    }
};
```