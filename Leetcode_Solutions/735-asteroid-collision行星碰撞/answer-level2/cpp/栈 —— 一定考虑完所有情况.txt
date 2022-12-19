### 解题思路
根据测试数据一步一步调试，把所有情况考虑到
![TIM图片20200320173047.png](https://pic.leetcode-cn.com/ec4b06c371de78bdb1125449c0d91616800cc4a527bc292056c4001e455a117a-TIM%E5%9B%BE%E7%89%8720200320173047.png)


### 代码

```cpp
class Solution {
public:
vector<int> ans;
    //s中存的是一个稳定的行星系统
    stack<int> s;
    stack<int> s1;
    vector<int> asteroidCollision(vector<int>& asteroids) {
        s.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            //当前方向向右无论如何都不会与左边已经稳定的行星系统发生碰撞
            if(asteroids[i]>0) s.push(asteroids[i]);
            else{
                //栈顶和当前方向同左，不会碰撞
                if(s.empty()||s.top()<0){
                    s.push(asteroids[i]);
                    continue;
                }
                else{
                    //相撞后行星系统不会变化
                    if(abs(s.top())>abs(asteroids[i])) continue;
                    else if(abs(s.top())==abs(asteroids[i])){
                        s.pop(); continue;
                    }
                    //可能与行星系统发生连续碰撞
                    else{
                        while(!s.empty()&&(s.top()>0&&abs(s.top())<abs(asteroids[i]))){
                            s.pop();
                        }
                        if(!s.empty()){
                            //与当前行星同向
                            if(s.top()<0) s.push(asteroids[i]);
                            //与当前行星相抵消
                            else if(s.top()>0&&s.top()+asteroids[i]==0){
                                s.pop();
                            }
                        }
                        else s.push(asteroids[i]);
                    }
                }
            }
        }
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
        }
        while(!s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        }
        return ans;
    }
};
```