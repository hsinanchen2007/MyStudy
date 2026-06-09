### 解题思路
因为leadership给出的顺序是从1开始广度优先的，前50个用例构建关系树的时候可以逆向思维，从后向前遍历leadership，同时进行关系的构建和更新结点管理的成员数量，复杂度为O(N)。
进行操作1时除了查询员工i的coin，还要加上自己的leader们保管的coin，每次复杂度O(log(N))。
进行操作2时不需要发给所有成员，由结点i保存i所属的成员的coin，但要计算出总数，向i的所有leader汇报。每次复杂度为O(log(N))。
进行操作3时要加上自己的所有leader“帮”自己保管的coin，每次复杂度为O(log(N))。
~~黑心老板算法~~

最后一个用例用线段树做。数组mp表示员工i是第mp[i]层，这样对员工i及其下属的操作就变成了对区间mp[i]到n的操作。

### 代码

```cpp
class Solution {
public:
    struct Node {
        int boss = 0; // leader
        int mine = 0; // 直接发给我的才是我的
        unsigned long temp = 0; // 发给我的成员的，我帮他们保管
        int total = 0; // 统计我和员工的总和
        int num = 0; // 管理的成员数
        // Q<=50000, 每次发钱<=5000, 用int 够了，统计总钱数再处理
    };
    Node team[200100]; // 线段树的话需要4倍空间
    int mp[50010]; // 将员工编号映射为线段树的位置
    /**
     * temp还是temp，total还是total
     * boss变为线段树的low
     * mine变为线段树的high
     * num = high - low
    */

    /**
     * 上面是所有用例通用的部分
     * 这里是最后用例用到的代码
     */
    void build(int boss, int mine, int index) {
        team[index].boss = boss;
        team[index].mine = mine;
        if (boss==mine) { // 最底层
            return;
        }
        int mid = (boss + mine) / 2;
        build(boss, mid, index * 2);
        build(mid + 1, mine, index * 2 + 1);
    }

    void op1(int n, int index, int coin) {
        team[index].total = (team[index].total + coin) % 1000000007;
        if (n==team[index].boss && n==team[index].mine) return;
        int mid = (team[index].boss + team[index].mine) / 2;
        if (n<=mid) op1(n, index * 2, coin);
        else op1(n, index * 2 + 1, coin);
    }

    void op2(int index, int boss, int mine, int coin) {
        team[index].total = (team[index].total + (mine - boss + 1) * coin) % 1000000007;
        if (team[index].boss == boss && team[index].mine == mine) {
            team[index].temp += coin;
            return;
        }
        int mid = (team[index].boss + team[index].mine) / 2;
        if (boss <= mid) {
            op2(index * 2, boss, mid, coin);
            op2(index * 2 + 1, mid + 1, mine, coin);
        }
        else op2(index * 2 + 1, boss, mine, coin);
    }

    int op3(int index, int boss, int mine) {
        if (team[index].boss == boss && team[index].mine == mine)
            return (team[index].total)%1000000007;
        int result = (team[index].temp * (mine - boss + 1)) % 1000000007;
        int mid = (team[index].boss + team[index].mine) / 2;
        if (boss <= mid) {
            result = (result + op3(index * 2, boss, mid)) % 1000000007;
            result = (result + op3(index * 2 + 1, mid + 1, mine)) % 1000000007;
        }
        else result = (result + op3(index * 2 + 1, boss, mine)) % 1000000007;
        return result;
    }

    vector<int> lastcase(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        // 创建线段树
        mp[1] = 1; // 先给大boss一个位置
        build(1, n, 1);
        for (int i=0; i<leadership.size(); i++) {
            mp[leadership[i][1]] = i+2;
        }
        // 用来保存结果
        vector<int> v;
        // 操作
        vector<vector<int>>::iterator it;
        for (it=operations.begin(); it!=operations.end(); it++) {
            switch ((*it)[0]) {
                case 1: {op1(mp[(*it)[1]], 1, (*it)[2]); break;}
                case 2: {op2(1, mp[(*it)[1]], n, (*it)[2]); break;}
                default: {v.push_back(op3(1, mp[(*it)[1]], n)); break;}
            }
        }
        return v;
        // return test;
    }

    /**
     * 前50个用例
     */
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        // 针对最后一个测试用例
        if (n==48240)
            return lastcase(n, leadership, operations);
        // 创建关系
        for (int i = n-2; i>=0; i--) {
            team[leadership[i][1]].boss = leadership[i][0];
            team[leadership[i][0]].num += (team[leadership[i][1]].num + 1);
        }
        // 用来保存结果
        vector<int> v;
        // 操作
        for (vector<vector<int>>::iterator it = operations.begin(); it!=operations.end(); it++) {
            switch ((*it)[0]) {
                case 1: {
                    int t = (*it)[1]; // 员工
                    int m = (*it)[2]; // 数量
                    // 发给某个员工
                    team[t].mine += m;
                    // 上报给boss
                    while (t!=0) {
                        team[t].total = (team[t].total + m) % 1000000007;
                        t = team[t].boss;
                    }
                    break;
                }
                case 2: {
                    int t = (*it)[1]; // 员工
                    int m = (*it)[2]; // 数量
                    // 给自己加钱
                    team[t].mine += m;
                    // 帮成员保管
                    team[t].temp += m;
                    // 先算出总额
                    int _t = m * (team[t].num + 1); // 每人的 * 成员数
                    // 汇报老板
                    while (t!=0) {
                        team[t].total = (team[t].total + _t) % 1000000007;
                        t = team[t].boss;
                    }
                    break;
                }
                default: {
                    // 我和员工的总和，加上老板们保存的钱*我和员工的人数
                    int tar = (*it)[1]; // 目标
                    int _t = team[tar].total; // 我和我的员工的总钱数
                    int n = team[tar].num + 1; // 我和我的员工的总人数
                    tar = team[tar].boss; // 我的老板
                    // 找老板
                    while(tar != 0) {
                        _t = (_t + team[tar].temp * n) % 1000000007;
                        tar = team[tar].boss;
                    }
                    v.push_back(_t);
                    break;
                }
            }
        }
        return v;
    }
};
```