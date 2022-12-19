### 解题思路
![image.png](https://pic.leetcode-cn.com/2317e2ba9fe2bdbe99705be63e9a4c0ebe04f20cb857b6561635489af1ca0aee-image.png)
经典的回溯算法。按数组长度迭代，按遍历的位置递归。
看注释吧。详细写了
还请多多交流多多指教

### 代码
```cpp
class Solution {
private:
    vector<vector<int>> res;
    int length;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        length=nums.size();
        vector<int> tmp;
        res.push_back(tmp);//空集也是子集的一个
        for(int i=1;i<=length;i++)
            search(0,i,tmp,nums);//i是子数组的最大长度,递归调用的开始
        return res;
    }
    void search(int turn,int &max,vector <int > &tmp,vector<int>& nums)//max是子数组的最大长度
    {
        if(tmp.size()==max)//递归结束的标志
            res.push_back(tmp);//添加tmp到结果数组
        else
            for(int i=turn;length-i>=max-tmp.size();i++)//按位置的递增关系
            {
                /*length-i>=max-tmp.size() 该判断语句是判断是否“将当前位置之后的所有元素都添加到
                tmp也都到不了max长度”，如果是的话那么就结束循环。这一句是剪枝的关键，很重要*/
                tmp.push_back(nums[i]);//添加当前位置的元素到tmp
                search(i+1,max,tmp,nums);//递归调用i的下一个位置
                tmp.pop_back();//将当前位置的元素从tmp中剔除
            }
    }
};
```