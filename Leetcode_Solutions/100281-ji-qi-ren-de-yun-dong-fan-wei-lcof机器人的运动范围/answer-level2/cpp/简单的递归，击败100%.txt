### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int count = 0;
        vector<vector<int>> vec(m,vector<int>(n,0));
        helper(0,0,m,n,k,vec,count);
        return count;
    }

private:
    void helper(int x,int y,int m,int n,int k,vector<vector<int>> &vec,int& count){
        if(x >= m || y >= n || vec[x][y] ||sumCount(x) + sumCount(y) > k) return;
        else{
            ++count;
            vec[x][y] = 1;
        }
        helper(x + 1,y,m,n,k,vec,count);
        helper(x,y + 1,m,n,k,vec,count);
    }

    int sumCount(int m){
        int count = 0;
        while(m){
            count += m % 10;
            m /= 10;;
        }
        return count;
    }
};
```