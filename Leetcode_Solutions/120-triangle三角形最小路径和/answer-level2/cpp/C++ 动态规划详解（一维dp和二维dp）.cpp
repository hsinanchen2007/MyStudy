终于自己写出来一个动态规划问题，大佬们解析中所说的一维的二维的dp都明白了一些，总结一下。

可以看出这个问题可以从下而上的分解成若干小问题，在填表的时候，重新使用输入数据的二维vector初始化了一个dp用于填表，为了避免污染原始数据。其实也可以在原始输入中进行填表。

从倒数第二行开始的原因是，只有至少存在两行才可以构建出三角形。这里也可以看出，dp表初始化就是倒数第一行的数据和输入数据的相同。

状态转移方程如下：

dp[i][j] = data[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);

因为这里是使用二维数组形式的dp，因此如上所示。也可以使用一维的dp来填表，只是说数据会被不断地覆盖。

二维的dp，最后需要的是dp[0][0]，一维的最后需要的是dp[0]，一样的道理。
```
/*测试用例
4
2
3 4
6 5 7
4 1 8 3
 */
#include <iostream>
#include <vector>
using namespace std;
int main() {
    // 数据输入
    int N;
    cin >> N;
    vector<vector<int>> data;
    for (int i = 0; i < N; ++i) {
        vector<int> line;
        for (int j = 0; j < i + 1; ++j) {
            int a;
            cin >> a;
            line.push_back(a);
        }
        data.push_back(line);
    }
    vector<vector<int>> dp(data); // 使用输入数据的二维vector初始化了一个dp用于填表，为了避免污染原始数据
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = data[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}

```
有错误的欢迎指出
