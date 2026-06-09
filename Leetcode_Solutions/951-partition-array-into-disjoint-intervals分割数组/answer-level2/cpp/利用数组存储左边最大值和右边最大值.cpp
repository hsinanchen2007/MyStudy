### 解题思路
此处撰写解题思路

如题目要求，左边数组的元素都右边数组的元素，即左边的最大值小于右边的最小值。
利用一个额外数组存储从第一个元素到当前元素的最小值
将A本身存储从最后一个元素到当前元素的最大值
找到第一个左边最大值小于右边最小值的index（left_max[i]<=A[i+1）

### 代码

```cpp
class Solution {
public:           
    //分割成left,right两个连续子数组，左边最大的数要小于右边最小的数,从左边开始遍历，第一个满足条件的就是结果，左边最大的值小于右边最小的值
    int partitionDisjoint(vector<int>& A) {
        
        vector<int> left_max;
        //vector<int> right_min;
        left_max.push_back(A[0]);
        for (int i=1;i<A.size();i++){
            int max_num=max(A[i],left_max[i-1]);
            left_max.push_back(max_num);
        }
        //right_min.push_back(A[A.size()-1]);
        for  (int j=A.size()-2;j>=0;j--){
            /*int min_num=min(A[j],right_min[i]);
            right_min.push_back(min_num);*/
            A[j]=min(A[j],A[j+1]);
        }

        //reverse(right_min.begin(),right_min.end());

        for (int i=0;i<left_max.size()-1;i++){
            if (left_max[i]<=A[i+1]){
                return i+1;
            }
        }
        return 0;
    }
};
```