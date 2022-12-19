
原理：
用一个数组保存n个节点的颜色，如果没涂色，就涂色，如果涂了色，后面发现要修改，就返回false，直到扫描完了整个dislike，最后返回true。
例如案例2
：
输入：N = 3, dislikes = [[1,2],[1,3],[2,3]]
输出：false
1着色为-1，2着色为1，然后1已经着色为-1了，3就着色为1，然后2已经着色为1，那么3就该着色为-1，但是3已经着色为1了，矛盾所以，false
```
bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
    int zuose[N + 1];
    for (int i = 0; i < N; ++i)
        zuose[i] = 0;

    int size = dislikes.size();

    for (int i = 0; i < size; ++i) {
        int m = dislikes[i][0];
        int n = dislikes[i][1];

        if (zuose[m] == 0 && zuose[n] == 0) {
            zuose[m] = -1;
            zuose[n] = 1;
        }
        else {
            if (zuose[m] == 0 || zuose[n] == 0) {
                if (zuose[m] == 1 && zuose[n] == 0) {
                    zuose[n] = -1;
                    continue;
                }
                if (zuose[m] == -1 && zuose[n] == 0) {
                    zuose[n] = 1;
                    continue;
                }
                if (zuose[m] == 0 && zuose[n] == 1) {
                    zuose[m] = -1;
                    continue;
                }
                if (zuose[m] == 0 && zuose[n] == -1) {
                    zuose[m] = 1;
                    continue;
                }
            }
            else {
                if (zuose[m] == zuose[n])
                    return false;
                else
                    continue;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> v = {{1, 2},
                             {1, 3},
                             {2, 3}};
    int i = possibleBipartition(3, v);
    cout << i << endl;
    cout << false;
}
```

很奇怪，我在自己的编译器上运行若干案例，没有问题，但是leetcode上面就是一直如下错误，我把这个案例用来自己编译器运行，没有问题。希望有大佬来答疑解惑！！！！！
![image.png](https://pic.leetcode-cn.com/3936411a29af5d85227bce99bc962dc909e6c3b45edfca96bd10fd7973761a44-image.png)
