### 解题思路
小白第一次发解题（为了赚分hhh），如有差错大佬们多担待~
每一次外循环拓展一个一位数组长度，每一次内循环覆盖原数组获取除最后一位的新一轮的杨辉三角赋值
使用两个temp，temp1用来存放当前数组rowIndex[j]的值，另一个temp2存放上一轮循环中rowIndex[j-1]的旧值（这个值已经被覆盖掉，由temp1传递给temp2，传递完temp1在新一轮循环中被重新赋当前j位置的值）
执行结果：
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :6.2 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int temp1,temp2=1;
        vector<int> ans;
        ans.push_back(1);
        for(int i=0;i<rowIndex;i++){
            for(int j=0;j<=i;j++){
                if(j==0) {
                    ans[j]=1;
                }
                else{
                    temp1=ans[j];                  
                    ans[j]=temp1+temp2;
                    temp2=temp1;
                }
            }
            ans.push_back(1);
        }
        return ans;
    }
};
```