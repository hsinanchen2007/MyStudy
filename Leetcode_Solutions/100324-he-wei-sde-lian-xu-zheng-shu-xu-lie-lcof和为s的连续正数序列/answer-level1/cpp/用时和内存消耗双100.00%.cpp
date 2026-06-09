### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :9.1 MB, 在所有 C++ 提交中击败了100.00%的用户
增加了target<3的情况判断
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        //滑动窗口 左关右开[ )
        vector<vector<int>> res;//存放满足条件的数组
        if(target<3){//3以下不满足情况
            return res;
        }

        int i=1;
        int j=1;//i是左端口 J是右端口
        int sum=0;
        while(i<=target/2){
            if(sum<target){
                sum+=j;
                j++;
            }
            else if(sum==target){
                //将该数组存放到res中
                vector<int> arr;
                for(int k=i;k<j;k++){//满足条件的数组
                    arr.push_back(k);
                }
                res.push_back(arr);
                sum-=i;
                i++;

            }
            else{//sum>target
                sum-=i;
                i++;
                
            }
        }
        return res;
    }
};
```