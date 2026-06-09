如果点q和点w在直线L1上，点q和点e也在直线L1上，那么q, w, e这三个点都在直线L1上。
可以想到，将直线L作为散列表的key, 用散列表的value统计在直线L上的点的个数。
即`直线L上点的个数 = HashMap[直线L]`.

如何表示一个直线呢？简单地，可以想到直线方程`y=kx+b`, 用`(k, b)`就能表示一条直线。
但是，由于`k`和`b`都是浮点数，在计算机中，浮点数计算存在误差，可能出现散列表中的两个key的差小于浮点数数据误差eps， 不适合作为key.

为了解决这个问题，我们可以使用直线的一般式。

二维平面上的直线可以用直线的一般式`Ax + By + C = 0`表示。
两点式`(x - x1) / (x2 - x1) = (y - y1) / (y2 - y1)`可以化为`Ax + Bx + C = 0`的直线的一般式，此时`A = y2 - y1, B = x1 - x2, C = A * x1 + B * y1`, A, B, C都为整数。

需要对A, B, C，其中一个等于0的情况进行特殊处理，并且需要对A, B, C进行约分。
比如4x + 2y = 0和2x + y = 0其实是同一条直线，对A,B,C约分后: A=2, B=1, C=0.

计算C时可能会溢出，因此使用long long类型。
使用变量`dup`处理两个同样位置的点的情况。


```c++
// 记录直线上的点的个数，以及最小的两个编号
struct Record {
  vector<int> ids;
  int cnt;
  Record() : cnt(0) {

  }
};

using LL = long long;

LL gcd(LL a, LL b) {
  LL r;
  do {
    r = a % b;
    a = b;
    b = r;
  } while (r != 0);
  return a;
}

class Solution {
public:
  vector<int> bestLine(vector<vector<int>>& points) {
    // (x - x1) / (x2 - x1) = (y - y1) / (y2 - y1)
    // (y2 - y1) x + (x1 - x2) y = (y2 - y1) * x1 + (x1 - x2) * y1
    int n = points.size();
    map<array<LL, 3>, Record> ABC_ma;

    int best = 0;
    vector<int> ans;

    // 如果A与B和A与C都在一条直线上，那么B与C也在该条直线上
    for (int i = 0; i < n; ++i) {
      vector<int> &pi = points[i];
      int dup = 0; // 与pi位置相同的点数
      ABC_ma.clear();
      int local_best = 0;
      vector<int> local_ans;
      for (int j = i + 1; j < n; ++j) {
        vector<int> &pj = points[j];
        LL A = (LL)pj[1] - pi[1];
        LL B = (LL)pj[0] - pi[0];
        if (A == 0 && B == 0) {
          // pi与pj相同
          ++dup;
          if (local_ans.empty()) local_ans = {i, j};
          continue;
        }
        LL C = A * pi[0] + B * pi[1]; 

        if (A == 0) {
          if (C == 0) {
            B = 1;
          } else {
            LL g = gcd(B, C);
            B /= g;
            C /= g;
          }
        } else if (B == 0) {
          if (C == 0) {
            A = 1;
          } else {
            LL g = gcd(A, C);
            A /= g;
            C /= g;
          }
        } else {
          // A != 0 and B != 0
          LL g = gcd(A, B);
          if (C == 0) {
            A /= g;
            B /= g;
          } else {
            LL w = gcd(g, C);
            A /= w;
            B /= w;
            C /= w;
          }
        }

        Record &r = ABC_ma[{A, B, C}];
        if (r.cnt == 0) {
          r.ids = {i, j};
        }
        ++r.cnt;

      }
      update_ans(ABC_ma, local_best, local_ans);
      local_best += dup;
      if (local_best > best) {
        ans = std::move(local_ans);
        best = local_best;
      }
    }

    return ans;
  }
  template <typename T>
  void update_ans(map<T, Record> &ma, int &best, vector<int> &ans) {
    for (auto &p : ma) {
      Record &r = p.second;
      if (r.cnt > best) {
        best = r.cnt;
        ans = std::move(r.ids);
      } else if (p.second.cnt == best) {
        // 如果穿过相同数量的点
        if (r.ids[0] < ans[0] || (r.ids[0] == ans[0] && r.ids[1] < ans[1])) {
          ans = std::move(r.ids);
        }
      }
    }
  }
};
```