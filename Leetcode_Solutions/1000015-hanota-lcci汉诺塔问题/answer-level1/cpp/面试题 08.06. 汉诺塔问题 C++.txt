### 解题思路
递归

### 代码

```cpp
class Solution {
public:
    void move(vector<int>& from, vector<int>& to)
    {
        to.push_back(from.back());
        from.pop_back();
    }

    //增加一个整型参数n，当前个数
    void hanoi(int n, vector<int>& from, vector<int>& help, vector<int>& to)
    {
        if (n == 1) //从from -> to
        {
            move(from, to);
            return;
        }

        hanoi(n - 1, from, to, help); 

        move(from, to);

        hanoi(n - 1, help, from, to);
    }


    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {

        int n = A.size();
        hanoi(n, A, B, C);
    }
};
```