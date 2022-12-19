### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/cf074099b7b6dd12cda5d6859e42b71ddce0af41505b4471f8340703191a30a0-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
          int top=0;
          for(int x:asteroids)
          {
              if(top==0) asteroids[top++]=x;
              else
              {
                  if(asteroids[top-1]<0) 
                  {
                     asteroids[top++]=x;
                     continue;
                  }
                  else if(asteroids[top-1]>=0 && x>=0) 
                  {
                     asteroids[top++]=x;
                     continue;
                  }
                  else if(asteroids[top-1]>=0 && x<0 && abs(x)<asteroids[top-1])
                  {
                      continue;
                  }
                  while(asteroids[top-1]>=0 && x<0)
                  {
                     if(abs(x)==asteroids[top-1])
                     {
                         top--;
                         break;
                     }
                     if(abs(x)>asteroids[top-1])
                     {
                        top--;
                        if(top==0)
                        {
                            asteroids[top++]=x;
                            break;
                        }
                        if(asteroids[top-1]<0) 
                        {
                            asteroids[top++]=x;
                            break;
                        }
                         if(asteroids[top-1]>0 && asteroids[top-1]>abs(x)) 
                         {
                             break;
                         }
                     } 
                     
                  }
              }

          }
          asteroids.resize(top);
          return asteroids;
    }
};
```