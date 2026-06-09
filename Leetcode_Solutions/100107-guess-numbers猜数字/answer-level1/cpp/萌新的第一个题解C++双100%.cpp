```
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int count(0);
        for(int i(0);i<3;i++)
        {
            if(answer[i]==guess[i])
            {
                count++;
            }
        }
        return count;
    }
};
```
100%没啥好说的
![image.png](https://pic.leetcode-cn.com/b471486a935cd2d947a85c5b938010c1f8137081fbbb8e66e82f86041a83a2f8-image.png)
