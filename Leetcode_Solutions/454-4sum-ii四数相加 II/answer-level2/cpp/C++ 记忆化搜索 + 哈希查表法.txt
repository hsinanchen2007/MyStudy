### 

### 1. 记忆化搜索

使用记忆化回溯的方式进行搜索，每次搜完一个位置，将当前四个数组的长度连接在一起形成字符串，作为 map 的索引，存储当前位置的答案，每次搜索若搜到这个位置就直接返回。

但是效率还是不够高，只通过了 **20 / 48** 个测试用例。。

```cpp
class Solution {
public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                   vector<int>& D) {

    unordered_map<string, int> map;
    int ans = 0;
    search(A, B, C, D, map, ans);
    return ans;
  }
  void search(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D,
              unordered_map<string, int>& map, int& ans) {
    if (A.empty() || B.empty() || C.empty() || D.empty()) return;
    int lena = A.size(), lenb = B.size(), lenc = C.size(), lend = D.size();
    string key
      = to_string(lena) + to_string(lenb) + to_string(lenc) + to_string(lend);
    if (map.count(key) > 0) { return; }

    if (A[0] + B[0] + C[0] + D[0] == 0) { ans++; }
    vector<int> ta(A.begin() + 1, A.end());
    search(ta, B, C, D, map, ans);

    vector<int> tb(B.begin() + 1, B.end());
    search(A, tb, C, D, map, ans);

    vector<int> tc(C.begin() + 1, C.end());
    search(A, B, tc, D, map, ans);

    vector<int> td(D.begin() + 1, D.end());
    search(A, B, C, td, map, ans);

    map[key] = ans;
  }
};
```

 

### 2. 哈希查表法

哈希表 `H<A[i]+B[j],计数>`。对 `A[i]+B[j]` 的值进行计数。

计算 `t=C[u]+D[v]`。如果 `H` 中有 `-t`，那么， `A[i]+B[j] + C[u]+D[v] == 0`。

一开始用的是 `multiset<int>` 来模拟哈希表，结果最后一个测试用例超时了。估计是因为内部用红黑树排序，取数时使用 count() 花费较大吧。

然后改成了用纯哈希表 `unordered_map<int, int>`，就可以通过了。

```cpp
class Solution {
public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                   vector<int>& D) {
    if (A.empty() || B.empty() || C.empty() || D.empty()) return 0;
    unordered_map<int, int> ab;
    for (int a : A) {
      for (int b : B) { ab[a + b]++; }
    }
    int ans = 0;
    for (int c : C) {
      for (int d : D) {
        int t = c + d;
        ans += ab[-t];
      }
    }
    return ans;
  }
};
```

