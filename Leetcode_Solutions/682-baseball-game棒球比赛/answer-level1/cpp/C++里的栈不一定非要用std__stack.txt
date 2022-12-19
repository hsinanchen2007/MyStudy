很多C++的答案里用了std::stack，由于stack接口的限制，在实现'+'操作时出现了先pop再repush的情况，实际这是不必要的操作。可以用vector或deque，这样可以直接访问最后两条记录。

```
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector< int > score_stack;
        score_stack.reserve( ops.size() );
        for( const auto& s : ops ){
            const auto c= s.front();
            if( c == '+' ){
                const auto score= score_stack.back() + score_stack[ score_stack.size() - 2 ];
                score_stack.emplace_back( score );
            }else if( c == 'D' ){
                const auto score= score_stack.back() * 2;
                score_stack.emplace_back( score );
            }else if( c == 'C' ){
                score_stack.pop_back();
            }else{
                const auto score= to_num( s );
                score_stack.emplace_back( score );
            }
        }
        int result= 0;
        for( auto score : score_stack ){
            result += score;
        }
        return result;
    }
    
private:
    static int to_num( const string& s )
    {
        int result= 0;
        for( auto c : s ){
            if( '0' <= c && c <= '9' ){
                const int digit= c - '0';
                result *= 10;
                result += digit;
            }
        }
        if( s.front() == '-' ){
            result= -result;
        }
        return result;
    }
    
};
```
