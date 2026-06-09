### 解题思路
1.a,b,c按从大到小排序
2.a与b之间的距离d1，b与c之间的距离d2
3.最小移动次数是0或1或2，最多移动次数是d1+d2

### 代码

```cpp
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> ans;
        int a1=min(a,min(b,c));
        int c1=max(c,max(a,b));
        int b1=a+b+c-a1-c1;
        a=b1-a1-1; b=c1-b1-1;
        c=max(a,b);
        int d=min(a,b);
        if(d==0&&c==0)
        {
            ans.push_back(0);
        }
        else if(d<=1)
        {
            ans.push_back(1);
        }
        else
        {
            ans.push_back(2);
        }
        ans.push_back(c+d);
        return ans;
    }
};
```