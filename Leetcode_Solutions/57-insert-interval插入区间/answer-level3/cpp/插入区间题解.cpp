### 解题思路
菜鸡代码，又臭又长
执行用时 :8 ms, 在所有 C++ 提交中击败了99.71%的用户
内存消耗 :17.7 MB, 在所有 C++ 提交中击败了5.08%的用户
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        // 用于标识区间是否已经合并
        bool flag=false;
        // 合并的区间的左右端点
        int left=newInterval[0],right=newInterval[1];
        for(int i=0;i<intervals.size();i++){
            // 区间已经合并，直接存入结果集
            if(flag){
                ans.push_back(intervals[i]);
            }else{
                if(newInterval[0]>intervals[i][1]){
                    ans.push_back(intervals[i]);
                }else if(newInterval[0]<intervals[i][0]){
                    left=newInterval[0];
                    int j;
                    for(j=i;j<intervals.size();j++){
                        if(newInterval[1]<intervals[j][0]){
                            right=newInterval[1];
                            flag=true;
                            i=j-1;
                            break;
                        }else if(newInterval[1]>=intervals[j][0]&&newInterval[1]<=intervals[j][1]){
                            right=intervals[j][1];
                            flag=true;
                            i=j;
                            break;
                        }
                    }
                    if(j==intervals.size()){
                        right=newInterval[1];
                        flag=true;
                        i=j-1;
                    }
                    vector<int> temp;
                    temp.push_back(left);
                    temp.push_back(right);
                    ans.push_back(temp);
                }else if(newInterval[0]>=intervals[i][0]&&newInterval[0]<=intervals[i][1]){
                    left=intervals[i][0];
                    int j;
                    for(j=i;j<intervals.size();j++){
                        if(newInterval[1]<intervals[j][0]){
                            right=newInterval[1];
                            flag=true;
                            i=j-1;
                            break;
                        }else if(newInterval[1]>=intervals[j][0]&&newInterval[1]<=intervals[j][1]){
                            right=intervals[j][1];
                            flag=true;
                            i=j;
                            break;
                        }
                    }
                    if(j==intervals.size()){
                        right=newInterval[1];
                        flag=true;
                        i=j-1;
                    }
                    vector<int> temp;
                    temp.push_back(left);
                    temp.push_back(right);
                    ans.push_back(temp);
                    
                }
            }
        }
        //  输入区间为空的情形
        if(!flag){
            ans.push_back(newInterval);
        }
        return ans;
    }
};
```