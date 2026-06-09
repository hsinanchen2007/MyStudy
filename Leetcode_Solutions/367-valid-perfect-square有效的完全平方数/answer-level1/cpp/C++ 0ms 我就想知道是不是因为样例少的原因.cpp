### 解题思路
就从1开始一个一个除，啥二分都没用，最后也能整一个0ms和4ms的来回震荡的结果。
明明是最慢的方法，是因为这个题目样例都很小的缘故么

### 代码

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        int c=1;
        bool check=false;
        while(num/c>=c)
        {
            if(num/c==c&&num%c==0)
            {
            check=true;
            break;
            }
            c++;
        }
        return check;
    }
};
```