### 解题思路
队列，但注意入队和出队的条件，另外注意队列是先进后出，后进先出

### 代码

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res ;

        if(asteroids.empty()) return res ;

        stack<int> stk;

        for(int i=0 ; i<asteroids.size() ; i++)
        {
            bool flag = true ;
            while(!stk.empty() && stk.top()>0 && asteroids[i]<0)
            {
                int diff(stk.top()+asteroids[i]) ;
                if(diff<=0) 
                    stk.pop() ;
                
                if(diff>=0)
                {
                    flag = false ;
                    break ;
                }    
            }

            if(flag) stk.push(asteroids[i]) ;
        }

        while(!stk.empty())
        {
            res.push_back(stk.top()) ;
            stk.pop() ;
        }

        reverse(res.begin() ,res.end());

        return res ;
    }
};
```