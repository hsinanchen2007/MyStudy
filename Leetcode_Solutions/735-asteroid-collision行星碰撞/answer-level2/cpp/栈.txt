通过栈的思想模拟，每次要加入一个元素时和栈顶元素比较，如果不会发生碰撞就把当前元素加入栈，如果会发生碰撞就将栈顶弹出，将碰撞结果放入，然后在判断当前栈顶是否符合要求，不符合再弹出与栈顶的上一个元素碰撞，直到符合要求。

代码细节较多，注意条件。
```c++ []
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.empty()) return asteroids;
        int stack[asteroids.size()+1],sz = 0;
        vector<int> res;
        memset(stack,0,sizeof stack);
        stack[++sz] = asteroids[0];
        for(int i = 1; i < asteroids.size(); i++){
            if(asteroids[i] * stack[sz] >= 0) stack[++sz] = asteroids[i];
            else if(asteroids[i] + stack[sz] == 0 && stack[sz] > 0) sz--;
            else if(asteroids[i] + stack[sz] == 0 && stack[sz] <0) stack[++sz] = asteroids[i];
            else if(stack[sz] > 0){
               stack[sz] = (abs(stack[sz]) > abs(asteroids[i]) ? stack[sz] : asteroids[i]);
               if(sz > 1){
                   while(stack[sz] * stack[sz-1] < 0 && stack[sz-1] > 0 ){
                       if(stack[sz] + stack[sz-1] == 0 ) sz-=2;
                       else stack[--sz] = (abs(stack[sz-1]) > abs(stack[sz]) ? stack[sz-1] : stack[sz]);
                       if(sz <= 1) break;
                   }
               }
            } 
            else if(stack[sz] < 0) stack[++sz] = asteroids[i];
        }
        for(int i = 1; i <= sz; i++)
            res.push_back(stack[i]);
        return res;
    }
};
```
