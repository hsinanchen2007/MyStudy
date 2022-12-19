### 解题思路
1. 用map做归并容器, key为回答的数值(ans_num), value是回答这个数值的兔子数量(ans_count)
2. 最坏情况:如果有5只兔子(ans_count)回答4(ans_num), 那这5只兔子(ans_num+1)可能是一个颜色. 
3. 如果有多于5只兔子回答4, 那可能是这其中五只兔子是同一种颜色
4. 有3只兔子(ans_count)回答4(ans_num).  那么最坏这3只都一种颜色, 但回答不骗人的前提下, 应该最少确实有5只兔子(ans_num+1)一样颜色 


### 代码

```cpp
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> number_map;//用map做归并容器, key为兔子回答的数值(ans_num), value是回答这个数值的兔子数(ans_count)
        int count = 0;          //兔子数量累计变量

        //遍历并归并赋值number_map
        for(vector<int>::iterator iter = answers.begin(); iter != answers.end(); ++iter){
             number_map[*iter]++;
        }

        //计算兔子数
        for(map<int,int>::iterator iter = number_map.begin(); iter!=number_map.end(); ++iter){
            int ans_num = iter->first;
            int ans_count = iter->second;
            while(ans_count!=0){
                if(ans_count > ans_num+1){
                    //最坏情况:如果有5只兔子(ans_count)回答4(ans_num), 那这5只兔子(ans_num+1)可能是一个颜色
                    //如果有多于5只兔子回答4, 那可能是这其中五只兔子是同一种颜色
                    ans_count= ans_count - (ans_num + 1);
                    count+=ans_num+1;
                }
                else{
                    //有3只兔子(ans_count)回答4(ans_num).  那么最坏这3只都一种颜色, 但回答不骗人的前提下, 应该最少确实有5只兔子(ans_num+1)一样颜色
                    count+=ans_num+1;
                    ans_count=0;
                }
            }
        }
        return count;
    }
};
```