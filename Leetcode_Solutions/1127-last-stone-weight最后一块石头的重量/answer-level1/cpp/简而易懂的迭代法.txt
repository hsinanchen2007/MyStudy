执行用时 :4 ms, 在所有 C++ 提交中击败了84.63%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

```
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        while(stones.size()!=1){//循环迭代
            
            sort(stones.begin(), stones.end());//从小到大排序
            
            int temp = stones.back();//指向容器末尾（最大值）
            
            stones.pop_back();//排出最大值
            
            if(stones.size()==1)//如果此时容器容量为1 则返回两者差值
                return abs(temp - stones.back());
            else if(stones.size()==0)//如果此时容器已空，则返回最大值
                return temp;
            else{//如果此时容器内元素大于1，则将最大值和次最大值作差，然后重新投入到容器中
                
                temp = abs(temp - stones.back());
                
                stones.pop_back();
                
                stones.push_back(temp);
            }

        }
        
        
        return stones.back();
    }
};
```
