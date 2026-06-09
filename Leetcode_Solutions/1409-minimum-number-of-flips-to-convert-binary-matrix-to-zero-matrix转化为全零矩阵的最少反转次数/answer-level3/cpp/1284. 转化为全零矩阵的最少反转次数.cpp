1.第一行的翻转有1<<w种方法
2.接下来每一行翻转的目的是将上一行全部置0
3.判断最后一行是否全部为零，记录最小次数
```c++
class Solution {
public:
    const int dir[5][2] = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int minFlips( vector<vector<int>>& mat ) {
        int h = mat.size(), w = mat[0].size();
        int maxn = 1 << w;
        int ret = INT_MAX;

        for( int cur = 0; cur < maxn; cur++ ) {
            int cnt = 0;
            vector<vector<int>> tmp = mat;

            for( int j = 0; j < w; j++ ) {
                if( cur & ( 1 << j ) ) {
                    convert( tmp, 0, j );
                    cnt++;
                }
            }

            for( int i = 1; i < h; i++ ) {
                for( int j = 0; j < w; j++ ) {
                    if( tmp[i - 1][j] ) {
                        convert( tmp, i, j );
                        cnt++;
                    }
                }
            }

            bool flag = true;

            for( int j = 0; j < w; j++ ) {
                if( tmp[h - 1][j] ) {
                    flag = false;
                    break;
                }
            }

            if( flag ) {
                ret = min( ret, cnt );
            }
        }

        return ret == INT_MAX ? -1 : ret;
    }
    void convert( vector<vector<int>>& mat, int i, int j ) {
        int h = mat.size(), w = mat[0].size();

        for( int n = 0; n < 5; n++ ) {
            int ni = i + dir[n][0], nj = j + dir[n][1];

            if( ni >= 0 && ni < h && nj >= 0 && nj < w ) {
                mat[ni][nj] ^= 1;
            }
        }
    }
};