### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int sumNums(int n) {
        Solution::reset();
        Solution* p=new Solution[n];
        delete [] p;
        p=NULL;
        return getsum();
    }
    Solution(){
        N++;
        sum+=N;
    }
private:
   static int N;
    static int sum;
public:
   static int getsum(){return sum;}
   static void reset(){N=0;sum=0;}
};
int Solution::N=0;
int Solution::sum=0;
```