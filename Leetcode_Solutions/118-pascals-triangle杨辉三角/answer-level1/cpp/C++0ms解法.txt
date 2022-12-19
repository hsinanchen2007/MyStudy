想法来源于 “取巧解法：错一位再逐个相加”
cpp提交结果：
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :8.8 MB, 在所有 cpp 提交中击败了17.92%的用户

计算过程为：
第三行为 1 2 1
得到第三行的过程为 ： 1 2 1 ->  0 1 2 1 -> 1 3 3 1
                                        s[0]=s[0]+s[1]  s[1]=s[1]+s[2]  ... s[3] = 1


```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> temp;
        vector<vector<int> > res;
        if(!numRows)
            return res;            // 如果numRows=0 直接返回空数组
        temp.push_back(1);         // 第一行
        res.push_back(temp);
        for(int i=1; i<numRows; i++){
            temp.insert(temp.begin(), 0);           // 实现错位 在开始插入0
            for(int j=0; j<temp.size()-1; j++){
                temp[j] = temp[j]+temp[j+1];        // 然后从第一位开始，每一个等于自身+后一个元素，注意结束条件
            }  
            temp[temp.size()-1]=1;                  // 处理最后一个元素
            res.push_back(temp);
        }
        return res;
    }
};

```
