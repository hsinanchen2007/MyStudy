### 解题思路
求出n-1的序列，加入结果队列，在加上2^n-1，反向加入队列

### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0)
            return vector {0};
        else{
            vector<int> res;
            auto res1 = grayCode(n-1);
            res.insert(res.end(), res1.begin(),res1.end());
            for_each(res1.begin(), res1.end(), addVal(1 << (n-1)));
            res.insert(res.end(), res1.rbegin(), res1.rend());
            return res;
        }
    }
private:
    class addVal{
    private:
        int val;
    public:
        addVal(const int n) : val(n){  
        }

        void operator()(int& a){
            a += val;
        }
    };
};
```