### 解题思路
这道题 使用递归就可以了，递归到nums[i][j] 求这个点慢不满足K，不满足说明这个点不能通过 所以将其标志为1，下次就不走这个点，满足的话 sum = sum+1；并将nums[i][j] = 1;防止重复计算！然后移动这个点可能的四个方向，如此类推，代码如下：

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {

        int sum = 0;
        if(m == 0) return 0;
        vector<vector<int>> nums(m,vector<int>(n,0));

        sumCount(nums,0,0,sum,k);
        return sum;
    }

    void sumCount(vector<vector<int>>& nums,int x,int y, int&sum,int k){

        if(x<0||x>=nums.size()||y<0||y>=nums[0].size()||nums[x][y] == 1){
            return ;
        }

        int a = x;
        int b = y;
        int val = 0;

        while(1){
            val += a%10;
            a = a/10;
            if(a == 0) break;
        }

         while(1){
            val += b%10;
            b = b/10;
            if(b == 0) break;
        }

        if(val>k){
            nums[x][y] = 1;
            return;
        }
        sum = sum + 1;
        nums[x][y] = 1;

        sumCount(nums,x-1,y,sum,k);
        sumCount(nums,x+1,y,sum,k);
        sumCount(nums,x,y-1,sum,k);
        sumCount(nums,x,y+1,sum,k);
    }
};
```