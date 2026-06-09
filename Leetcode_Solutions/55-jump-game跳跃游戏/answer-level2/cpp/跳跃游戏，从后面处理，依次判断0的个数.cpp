### 解题思路
此处撰写解题思路

看注释

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nNumSize = nums.size();

        if(0 == nNumSize)
        {
            return false;
        }

        if(1 == nNumSize)
        {
            return true;
        }

        bool bIsCanJump = true;
        int nCurrPos = nNumSize - 1;
        int nZeroSize = 0;
        do
        {
            int nNum = nums.at(nCurrPos);

          if (0 != nNum)//如果该点不为0做一下处理
          {
              if (nNum <= nZeroSize)
              {
                  if(nNum == (nNumSize - 1 - nCurrPos))//判断是否能直接跳到队尾
                  {
                      bIsCanJump = true;
                      nZeroSize = 0;
                  }
                  else//如果不能，就说明如果上一步跳到该位置的话是跳不出后面的0的，再判断前面的数字是否能c跳过包括该点的0，因此把该点也当成0去处理
                  {
                      bIsCanJump = false;
                      nZeroSize++;
                  }    
              }
              else//如果该点能跳出后面的0，说明只要前面能跳转到该位置，那么就能跳到队尾
              {
                  bIsCanJump = true;
                  nZeroSize = 0;
              }
          }
          else//为0的话nZeroSize++
          {
              nZeroSize++;
          }
          nCurrPos--;
        }while(nCurrPos >= 0);

        return bIsCanJump;
    }
};
```