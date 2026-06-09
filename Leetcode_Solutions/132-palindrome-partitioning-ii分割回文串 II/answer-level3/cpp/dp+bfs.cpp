### 解题思路
动态规划+广度优先搜索。用动态规划求解各子串是否是回文，用广度优先搜索求解最小划分次数
### 代码

```cpp
class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if ( len <= 1 ) return 0;
        //  第一步，用动态规划的方法求得是否是回文字符串，这里check[i][j]表示s中第i到第i+j位置这j+1长度字符串是否是回文
        bool ** check = new bool * [len];
        for ( int i=0; i<len; i++ )
            check[i] = new bool[len-i];
        for ( int i=0; i<len; i++ ) check[i][0] = true;
        for ( int i=0; i<len-1; i++ ) check[i][1] = ( s[i] == s[i+1] );
        for ( int j=2; j<len; j++ )
            for ( int i=0; i<len-j; i++ )
                check[i][j] = check[i+1][j-2] && ( s[i] == s[i+j] );
        //  第二步，用bfs计算划分次数，先把0位置入队列，然后按bfs的思路去考察每一个与队列中元素“连接”的位置，并把连接位置的下一个位置入队
        queue <int> q;
        q.push ( 0 );
        bool * used = new bool [len]();
        used[0] = true;
        int cnt = 0;
        while ( !q.empty() ) {
            int num = q.size();
            for ( int i=0; i<num; i++ ) {
                int k = q.front();
                q.pop();
                for ( int j=len-1; j>=k; j-- ) {
                    if ( check[k][j-k] ) {
                        if ( j == len - 1 ) return cnt;
                        if ( !used[j+1] ) {
                            q.push ( j + 1 );
                            used[j+1] = true;
                        }
                    }
                }
            }
            cout << endl;
            cnt++;
        }
        return len - 1;
    }
};
```