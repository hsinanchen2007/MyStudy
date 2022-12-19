这道题比较巧妙且强大的方法是回溯法
很多大神都有介绍，小白就不再赘述了
我要提到的是一种比较以逸待劳的方法，在思想上比较容易接受
基本思路如下：
**假设目标数组大小为3
那么变换顺序的数组大小也都是3
我们在0位置、1位置和2位置随机选取原目标数组中的一个数
将得到的数组放入set中，若与已有的数组重复便会被自动过滤掉
这样，通过多次重复随机，基本上能得到所有的结果**
这种方法的缺点是运行时间长（多次随机）
但是优点就是便于理解，思路简单
大概就是命令计算机“我想要所有的可能组合，你去给我通通找出来！”
```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        set<vector<int>> mid;   //用set避免重复
        vector<vector<int>> result;
        mid.insert(nums);
        for(int i = 0 ; i < nums.size()*5000 ; i ++)
        {
            vector<int> temp1 = nums; //原排列
            vector<int> temp2;  //新排列
            for(int i = 0 ; i < nums.size() ; i ++)
            {
                int random = rand()%temp1.size();   //随机原数组中的一个数
                temp2.push_back(temp1[random]); //加入到新数组中
                temp1.erase(temp1.begin()+random);  //在原数组中移除该数避免下次再选到
            }
            mid.insert(temp2);  //利用set的去重功能
        }
        for(auto i:mid)
        {
            result.push_back(i);
        }
        return result;
    }
};
```
