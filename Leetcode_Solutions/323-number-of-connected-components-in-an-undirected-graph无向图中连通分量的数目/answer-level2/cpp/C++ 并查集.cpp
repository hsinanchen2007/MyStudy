```
class UF {
private:
  vector<int>parents;
public:
  int cnt;
  UF(int n) {
    parents = vector<int>(n);
    int i = 0;
    for_each(parents.begin(), parents.end(), [&i](auto& num) {num = i++; });
    cnt = n;
  }

  int find_op(int node) {
    while (parents[node] != node) {
      parents[node] = parents[parents[node]];
      node = parents[node];
    }
    return node;
  }

  void union_op(int node1, int node2) {
    auto root1 = find_op(node1);
    auto root2 = find_op(node2);
    if (root1 != root2) {
      parents[root2] = root1;
      cnt--;
    }
  }

  bool isConnected(int node1, int node2) {
    return find_op(node1) == find_op(node2);
  }
};

bool vector_cmp(const vector<int>& v1, const vector<int>& v2) {
  if (v1[0] != v2[0]) {
    return v1[0] < v2[0];
  }
  else {
    return v1[1] < v2[1];
  }
}

class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    if (n <= 0) {
      return 0;
    }
    if (edges.empty() && n > 0) {
      return 0;
    }
    if (edges.empty() && n <= 0) {
      return 0;
    }
    UF uf(n);
    sort(edges.begin(), edges.end(), vector_cmp);
    for (size_t i = 0; i < edges.size(); i++)
    {
      const auto& edge = edges[i];
      int node1 = edge[0];
      int node2 = edge[1];
      if (!uf.isConnected(node1, node2)) {
        uf.union_op(node1, node2);
      }
      else {
        continue;
      }
      for (size_t j = 0; j < i; j++)
      {
        if (!uf.isConnected(edges[i][0], node1)) {
          uf.union_op(edges[i][0], node1);
        }
      }
    }
    return uf.cnt;

  }
};
```
