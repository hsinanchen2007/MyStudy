在每一个点上从 8 个方向收集信息，建立两个数组循环使用，减少空间复杂度
```
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<int>> dxy{{-1,-2}, {-2,-1}, {1,-2}, {-2,1}, {-1,2}, {2,-1}, {1,2}, {2,1}};
        double arr[N][N], brr[N][N];
        memset(arr, 0, sizeof(arr));
        arr[r][c] = 1;
        for(int k=0; k<K; k++){
            memset(brr, 0, sizeof(brr));
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    for(int l=0; l<8; l++){
                        int x = i+dxy[l][0], y = j+dxy[l][1];
                        if(x >= 0 && y >= 0 && x < N && y < N) brr[i][j] += arr[x][y]/8.0;
                    }
            memcpy(arr, brr, sizeof(arr));
        }
        double res = 0;
        for(auto& it:arr)
            for(auto& i:it)
                res += i;
        return res;
    }
};
```

还可以进一步，把二维坐标转换成一维坐标，精简代码，不过并没有改变时间和空间复杂度
```
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<int>> dxy{{-1,-2}, {-2,-1}, {1,-2}, {-2,1}, {-1,2}, {2,-1}, {1,2}, {2,1}};
        double arr[N*N], brr[N*N];
        memset(arr, 0, sizeof(arr));
        arr[r*N+c] = 1;
        for(int k=0; k<K; k++){
            memset(brr, 0, sizeof(brr));
            for(int i=0; i<N*N; i++)
                for(int j=0; j<8; j++){
                    int x = i/N+dxy[j][0], y = i%N+dxy[j][1];
                    if(x >= 0 && y >= 0 && x < N && y < N) brr[i] += arr[x*N+y]/8.0;
                }
            memcpy(arr, brr, sizeof(arr));
        }
        double res = 0;
        for(auto& it:arr) res += it;
        return res;
    }
};
```


