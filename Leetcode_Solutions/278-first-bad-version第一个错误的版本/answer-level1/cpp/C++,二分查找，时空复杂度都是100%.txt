### 解题思路
![TIM截图20200322112019.png](https://pic.leetcode-cn.com/9b53065c8ec127aa9a3f5924da9f5286a46d35eaaa12f4456baf91d8705bb56d-TIM%E6%88%AA%E5%9B%BE20200322112019.png)
此处撰写解题思路

### 代码

```cpp
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
            int pstart=0,pend=n;
            int mid;
            while(pstart<pend)
            {
                mid=pstart+(pend-pstart)/2;
                if(isBadVersion(mid))
                {
                    pend=mid;
                }
                else
                pstart=mid+1;
            }
            return pstart;
   

           

    }
};
```