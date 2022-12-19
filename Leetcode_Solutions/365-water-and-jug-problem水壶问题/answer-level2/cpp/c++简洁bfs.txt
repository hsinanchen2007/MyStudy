class Solution {
  struct Node {
    Node(int x_, int y_) : x(x_), y(y_) {}
    int x;
    int y;
  };

  long GetKey(int x, int y) { return static_cast<long>(x) << 32 | y; }

  void Try(int x, int y) {
    long key = GetKey(x, y);
    if (visit.find(key) == visit.end()) {
      visit.insert(key);
      q.emplace(x, y);
    }
  }

  unordered_set<long> visit;
  queue<Node> q;

 public:
  bool canMeasureWater(int x, int y, int z) {
    visit.insert(0);
    q.emplace(0, 0);
    while (!q.empty()) {
      Node cur = q.front();
      q.pop();

      if (cur.x + cur.y == z) return true;

      Try(x, cur.y);
      Try(cur.x, y);
      Try(0, cur.y);
      Try(cur.x, 0);
      int x_left = x - cur.x;
      int y_left = y - cur.y;
      if (y_left >= cur.x) {
        Try(0, cur.y + cur.x);
      } else {
        Try(cur.x - y_left, y);
      }
      if (x_left >= cur.y) {
        Try(cur.x + cur.y, 0);
      } else {
        Try(x, cur.y - x_left);
      }
    }
    return false;
  }
};