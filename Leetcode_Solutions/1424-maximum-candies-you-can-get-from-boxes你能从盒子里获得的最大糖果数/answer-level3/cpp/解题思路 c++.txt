### **解题思路**

- **设两个池子**：
**第1个池子**：存储所有 **待处理** 的盒子（盒子的状态可能是开，也可能是关）；初始给的盒子、后来得到的新盒子都丢到这个池子里。这里直接用*initialBoxes*这个容器作为第**1**个池子。
**第2个池子**：存储第**1**个池子中 **状态是开** 的盒子。这里新设变量*tag*。

- **开盒子过程模拟**：
1. 首先检查第**1**个池子里有没有状态是开的盒子：若有，将盒子编号都存入第**2**个池子中；若没有，程序结束；
2. 第**2**个池子中的盒子依次执行 **打开动作**，并根据每个盒子里的内容做下方更新，然后把打开过的盒子从两个池子中移除；
             - 取出盒子里的糖果，更新糖果数量*sum*；
             - 取出盒子里的钥匙，更新盒子开关状态*status*；
             - 取出内含的盒子，丢入第**1**个池子。

### **执行结果**
![leetcode1298.png](https://pic.leetcode-cn.com/b8e693f7f009bd63b7b69f375a417350f014c1f1079494b0325bbc6162a882ab-leetcode1298.png)

 
 
###  **c++代码**
```
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
         int sum=0;
         int index=0;
         vector<int> tag;

         while(initialBoxes.size()!=0)
         {
            //检查initialBoxes中是否仍有打开的盒子，有则将盒子的标签存入tag，若没有则break
            for(size_t i=0;i<initialBoxes.size();i++)
            {
                index = initialBoxes[i];
                if (status[index])
                {
                     tag.push_back(index);
                }
            }
            if(tag.empty()) {break;}
            
            //依次打开tag中记录的盒子，拿出里面的糖果、钥匙、盒子，更新状态
            while(!tag.empty())
            {
                index = tag.back();
                //取出盒子编号后，将该盒子分别从两个池子中移除；
                tag.pop_back();
                initialBoxes.erase(remove(initialBoxes.begin(),initialBoxes.end(),index),initialBoxes.end());

                //取出盒子里的糖果，更新sum
                sum += candies[index];

                //取出盒子里的钥匙，并更新盒子的status
                if(keys[index].size()!=0)
                {
                    for(size_t j=0;j<keys[index].size();j++)
                    {
                        status[keys[index][j]]=1;
                    }
                }

                //取出盒子内含的盒子，并更新到initialBoxes中
                if(containedBoxes[index].size()!=0)
                {
                    for(size_t k=0;k<containedBoxes[index].size();k++)
                    {
                        initialBoxes.push_back(containedBoxes[index][k]);
                    }
                }
                
            }   
         }  
         return sum;
    }
};
```


