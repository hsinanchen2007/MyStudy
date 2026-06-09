### 解题思路
一开始想的是通过处理最后数据逆序处理，但后来发现这样仍要保留尾端数据，反而复杂，于是考虑正向处理。(当然事实上，可以使用已知数据跳跃回溯，详见精选题解第三个
)
总体思路与用户程序员小吴的类似，都是使用栈，正向处理数据，比较后项大小，新数据更大，则已获得结果，推出；尚未结果就保留在栈中等待新的数据更新。

然而鄙人在细节实现上确实远远不如用户程序员小吴。关键在于如何表示数对（index，<int>datumn)以及处理栈叠加以后每个元素对应天数的增加问题。小吴很巧妙的用index做差来实现，并且就可以只用一个栈来表示（我原先用了两个栈，一个对应dataumn,一个对应index，但事实上确实有了index后直接使用给定的数据vector<int> T即可，我多次一举了 ）；
相比之下，我是利用遗留在栈中较上方元素的天数再加回到下方元素实现的，从而在最后的最后还需要对剩下的元素清0处理，比较复杂。

### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        int counter = 0 ;
        vector<int> answer ;
        vector<int> help ;
        
        // initialization
        answer.push_back(0);
        help.push_back(counter);
        
        for ( counter = 1 ; counter < T.size() ; ++counter)
        {
            while( !help.empty() && T[help.back()]< T[counter] )
            {
                ++answer[help.back()];
                
                if ( help.size() > 1 )         // 如果栈中在推出后仍有元素，需要将现有天数加到下一个结果上
                answer[*(help.end()-2)] += answer[help.back()] - 1;  // ”-1“是由于前面初始化加了1有重复
                
                help.pop_back();
                
            }
            
            if ( help.empty())
            {
                answer.push_back(0);
                help.push_back(counter);
            }
            else
            {
                ++answer[help.back()];
                answer.push_back(0);
                help.push_back(counter);
            }
            
        }
        
        auto ptr = help.begin() ;       /
        while ( ptr != help.end())
        {
            answer[*ptr] = 0 ;
            ++ptr ;
        }
        return answer ;
    }



};

```