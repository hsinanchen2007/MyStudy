### 解题思路
使用一个长度为2的队列分别保存上次得分，以及上上次得分。在统计得分之前，先进行对字符串里的“C”的处理，避免后期处理带来麻烦。算出当前局的分数后，把它push进队列，然后再把第一个上上次的得分pop掉，这样就能保持队列的长度不会太大，减少对内存的浪费，在加入记录总分的变量score。最后，返回score。

### 代码

```cpp
class Solution {
public:
    int calPoints(vector<string>& ops) {
        queue<int> result;
        result.push(0);//初始化队列,保证队列长度始终保持为2，分别为上次得分与上上次得分
        result.push(0);
        int score = 0;//总分置0
        //提前一次性完成“C”的清算，避免后期处理“C”带来的麻烦
        auto iterator = ops.begin();
        while( iterator != ops.end() )
        {
            if( "C" == *iterator )
            {
                --iterator;
                ops.erase(iterator);
                ops.erase(iterator);
                continue;//这就是不使用for而用while的原因：避免迭代器自动加1，
            } 
            ++iterator;           
        };

       iterator = ops.begin();
       while( ops.end() != iterator)
       {
            if( "D" == *iterator) 
            {
                result.push( 2*result.back() );
                score += result.back();
                result.pop(); 
            }
            else if( "+" == *iterator) 
             {
                result.push( result.front()+result.back() );
                score += result.back();
                result.pop();
             }  
            else
            {
                result.push( stoi( *iterator ) );
                score += result.back();
                result.pop();
             }
             ++iterator;
       }
       return score;
    }
};
```