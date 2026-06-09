### 暴力
按照题目意思做就可以了。
### 时间/空间复杂度
时间复杂度：O（n）
空间复杂度：O（1）
### 代码

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        for(int i=0;i<asteroids.size();++i){
            if(i==0) continue;
            else if(asteroids[i-1]>0 && asteroids[i]<0){
                int prev=asteroids[i-1],cur=-asteroids[i];
                if(prev>cur){
                    asteroids.erase(asteroids.begin()+i);
                    --i;
                }else if(prev<cur){
                    asteroids.erase(asteroids.begin()+i-1);
                    i=0;
                }else{
                    asteroids.erase(asteroids.begin()+i);
                    asteroids.erase(asteroids.begin()+i-1);
                    i-=2;
                }
            }
        }
        return asteroids;
    }
};
```