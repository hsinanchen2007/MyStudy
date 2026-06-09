
定义：N = arr1.length(), M = arr2.length()
`dp[i][j]`定义：对于子数组`arr[0,..,i]`（左右都包含），在使用**不多于**`j`次赋值使得子数组变得有序的所有方法中，`arr1[i]`所能达到的最小值。如果不存在这样的方法，则为`MAX_INT`。
例如，对于样例`arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]`而言：
- dp[0][0] = 1，dp[1][0] = 5 因为不能使用赋值操作，从而dp[i][0]的值就是原数组arr1[i]的值
- dp[2][0] = MAX_INT，因为子数组[1,5,3]不是有序的
- dp[1][1] = 3，因为可以将arr1[1]换成3

根据这个定义，容易知道对于任何一个给定的i而言，dp[i][i+1] <= dp[i][i] <= ... <= dp[i][0]。这个很容易理解，因为dp[i][j+1]一定蕴含了dp[i][j]所覆盖的所有情况。因此，我们说dp数组具有单调性。

现在假设我们已经求出了dp[i-1][0], dp[i-1][1], ..., dp[i-1][i]的所有值，现在要计算dp[i][j]，我们可以简单地分两种情况讨论：
- 不替换arr1[i]，则arr1[i]不占用替换次数。因此如果子数组arr1[0,...,i-1]能够在不多于j次赋值变得有序，且存在一种方法，能让替换后的arr1[i-1]（dp[i-1][j])小于arr1[i]，这样子数组arr1[0,...,i]就有序了，此时dp[i][j]就为arr1[i]。否则，dp[i][j]为`MAX_INT`
- 替换arr1[i]，则arr1[i]占用一次替换次数。要把arr1[i]替换成哪个值呢？显然任何一个比dp[i-1][j-1]大的值都可以。但如果替换成的值过大，留给后面的余地就小了，因此，要替换成arr2中比dp[i-1][j-1]大的值中，最小的那一个。

对于第二种情况而言，对每一个dp[i][j]，我们都要从arr2中找到满足条件的最小值，这样是log(M)的复杂度。这样，总体的复杂度就是O(N^2log(M))。

我们还可以做的更好。根据上面提到的dp数组的单调性，我们只需先在arr2中找到比dp[i-1][i]大的那个元素，此后只要向右扫描，就能找到比dp[i-1][i-1]更大的元素。因此，在求dp[i][j]的所有情况时，我们只要二分查找一次，再线性向右扫描一次arr2数组即可。这样，总体的复杂度就是O(N*max(N,M))。

```
class Solution {
public:
    int firstLargerThan(vector<int>& arr, int n) {
        int l = 0, r = arr.size();
        while(r - l > 1) {
            int mid = (r + l) / 2;
            if(arr[mid] > n) {
                r = mid;                
            } else {
                l = mid;
            }
        }

        if(arr[l] > n) return l;
        else return l + 1;;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        const int MAXINT = 2147483647;

        sort(arr2.begin(), arr2.end());
        int size1 = arr1.size(), size2 = arr2.size();
        vector<vector<int>> dp(size1, vector<int>(size1 + 1, MAXINT));

        dp[0][0] = arr1[0];
        dp[0][1] = min(arr1[0], arr2[0]);
        for(int i = 1; i < size1; i++) {
            for(int j = 0; j <= i; j++) { // 不替换
                if(arr1[i] > dp[i-1][j]) {
                    dp[i][j] = arr1[i];
                }
            }
            dp[i][i+1] = dp[i][i];

            int minV = dp[i-1][i];
            int idx = firstLargerThan(arr2, minV);
            for(int j = i + 1; j >= 1; j--) { // 不替换
                while(idx < arr2.size() && arr2[idx] <= dp[i-1][j-1]) idx++;
                if(idx == arr2.size()) break;
                dp[i][j] = min(dp[i][j], arr2[idx]);
            }
            if(dp[i][i+1] == MAXINT) return -1;
        }

        for(int i = 0; i <= size1; i++) {
            if(dp[size1-1][i] < MAXINT) return i;
        }
        return -1;
    }
};
```

