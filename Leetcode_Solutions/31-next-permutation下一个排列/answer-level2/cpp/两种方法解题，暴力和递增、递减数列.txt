### 解题思路
方法一：嵌套循环+队列
1、第一层循环作为目标数，如a[i]，第二层循环从a[i+1]开始，依次查找比a[i]大的数字，并将其中最小的数字位置j和i入栈 pair<i,j>;依次第一层循环中依次重复上述操作；最后栈顶的pair就是需要交换的数字对。
2、将栈顶的数字pop，并交换，同时将i之后的位置从大到小排列。

方法二：递增和递减数列
1、从后往前找到第一个由递增数列断开的拐点 i；
2、从拐点由前往后找到第一个递减数列的拐点或终点j；
3、交换i,j位置的数字，并将i之后的数列由小到大排序。

### 代码

```cpp
class Solution {
public:
/*void nextPermutation(vector<int>& nums) {
    if(nums.size() < 1)
        return;
    
    stack<pair<int, int>> sk;
    for(int i = 0; i < nums.size(); i++){
        int val = nums[i];
        for(int j = i; j < nums.size(); j++){
            if(nums[i] < nums[j]){
                if(!sk.empty() && i == sk.top().first){
                    int index = sk.top().second;
                    if(nums[index] > nums[j]){
                        sk.pop();
                        sk.push(make_pair(i, j));
                    }
                }else
                    sk.push(make_pair(i, j));
            }
        }
    }
    
    if(!sk.empty()){
        int a = sk.top().first;
        int b = sk.top().second;
        swap(nums[a], nums[b]);
        sort(nums.begin() + a + 1, nums.end());
    } else
        sort(nums.begin(), nums.end());
}*/

void nextPermutation(vector<int>& nums){
    int i = nums.size() - 1;
    while(i - 1 >= 0 && nums[i - 1] >= nums[i]){
        i--;
    }
    
    i -= 1;
    if(i >= 0){
        int j = i + 1;
        while(j < nums.size() && nums[i] < nums[j])
            j++;
        
        swap(nums[i], nums[j - 1]);
    }
    
    reverse(nums.begin() + i + 1, nums.end());
}
};
```