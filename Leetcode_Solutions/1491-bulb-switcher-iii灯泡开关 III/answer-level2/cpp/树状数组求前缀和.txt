### 解题思路
**最基本的思路**：每点亮一只灯，查询当前已点亮的最大位置的灯泡的前面所有的灯泡是否已变亮。

根据上面最基本的思路，可以转化为求前缀和，前缀和[i]表示位置i前面(包括位置i)共有多少只亮灯

若前缀和[i] == i，则当前满足所有灯泡都是蓝色

又此处遍历求前缀和会超时，故采用树状数组求前缀和

### 代码

```cpp
class Solution {
public:
    const int maxn = 5e4+5;
    int tree[50005];
    int numTimesAllBlue(vector<int>& light) {
        int ans = 0;
        int max_pos = 0;
        for(int i = 0; i < light.size(); i++) {
            add(light[i]);  //位置light[i]处+1
            max_pos = max(max_pos, light[i]);   //更新最大位置
            if(check(max_pos, getsum(max_pos))) ans++;
        }
        return ans;
    }

    bool check(int pos, int num) {
        return pos == num;
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int pos) {
        while(pos < maxn) {
            tree[pos] += 1;
            pos += lowbit(pos);
        }
    }
    // 得到位置pos的前缀和
    int getsum(int pos) {
        int sum = 0;
        while(pos > 0) {
            sum += tree[pos];
            pos -= lowbit(pos);
        }
        return sum;
    }
};
```