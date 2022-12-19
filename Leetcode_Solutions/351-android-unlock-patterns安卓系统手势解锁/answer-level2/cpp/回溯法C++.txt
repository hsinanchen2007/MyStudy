回溯法，在每个未知轮流放置1 2 3 4 5 6 7 8 9，观察发现，其实就是全排列，不过排列的个数是收到限制的，当大于n时就没必要继续排列了，而大于等于m小于等于n时，统计结果后可以继续排列，而且手势滑动受到连接的影响，简单粗暴，观察图形：
1->3 必须先访问过2；
3->7 必须先访问过5；
...
以此类推，写的代码比较简单粗暴。

```
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int cnt = 0;
        vector<int> ans;
        vector<bool> isUsed(10, false);
        backStract(isUsed, ans, cnt, m, n);
        return cnt;
    }
    
    void backStract(vector<bool> &isUsed, vector<int> &ans, int &cnt, int m, int n)
    {
        if (ans.size() >= m && ans.size() <= n) {
            cnt++;
        }
        if (ans.size() > n) {
            return;
        }
        
        for (int i = 1; i <= 9; i++) {
            if (!isCanPush(isUsed, ans, i)) {
                continue;
            }
            ans.push_back(i);
            isUsed[i] = true;
            backStract(isUsed, ans, cnt, m, n);
            ans.pop_back();
            isUsed[i] = false;
        }
    }
    
    bool isCanPush(vector<bool> &isUsed, vector<int> &ans, int i)
    {
        if (isUsed[i]) {
            return false;
        }
        
        if (ans.size() == 0) {
            return true;
        }
        
        int lastData = ans[ans.size() - 1];
        if ((lastData == 1 && i == 3) || (lastData == 3 && i == 1)) {
            return isUsed[2];
        }
        
        if ((lastData == 3 && i == 9) || (lastData == 9 && i == 3)) {
            return isUsed[6];
        }
        
        if ((lastData == 7 && i == 9) || (lastData == 9 && i == 7)) {
            return isUsed[8];
        }
        
        if ((lastData == 1 && i == 7) || (lastData == 7 && i == 1)) {
            return isUsed[4];
        }
        
        if ((lastData == 1 && i == 9) || (lastData == 9 && i == 1)) {
            return isUsed[5];
        }
        
        if ((lastData == 3 && i == 7) || (lastData == 7 && i == 3)) {
            return isUsed[5];
        }
        
        if ((lastData == 4 && i == 6) || (lastData == 6 && i == 4)) {
            return isUsed[5];
        }
        
        if ((lastData == 2 && i == 8) || (lastData == 8 && i == 2)) {
            return isUsed[5];
        }
        return true;
    }
};
```
比较耗时
![image.png](https://pic.leetcode-cn.com/47c02fc619f24427de8bdd67c6f1924823ac8253040953cfb8c2cfc0d0bdf57b-image.png)
