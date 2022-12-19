##### Algorithm (Math)
* One key observation is the following. 
* **Proposition.** A board $B$ could be transformed to a chessboard by swapping rows and columns if and only if 
     1. It has two unique columns and two unique rows.
     2. Each one of the unique columes has evenly splitted 0's and 1's. (In the odd dimension case, this translate to the difference between 0's and 1's is 1)
* **Proof.** 
* $\Rightarrow$. Suppose $B$ is transformable. Then the result follows by definition. 
* $\Leftarrow$. We prove the contrapositive. 
    * Suppose $B$ is not transformable. Then it follows that for any set of transformation applied to $B$, there would exists an adjacent pair has identical labels. Without loss of generality, we let the label be 1 on column, say $B[i][c], B[i+1][c]$. 
    * Suppose condition 1 and 2 hold. Then we can apply a set of transformation to evenly distribute the two unique rows of $B$. Since there are only two rows and row $i$ and row $i+1$ are not the same by construction, it follows that all of column $c$ os 1, i.e, $B[j][c] = 1$ for all $j = 1,...,N$. 
    * But then this would result a contradiction because the 1'0 and 0's are not evenly splitted. 
* Using this observation, is it trivial to come up with an algorithm to check feasibility.

##### Code

```c++[]
namespace utils::dynamic_bitset {
template <typename set_t = int, typename... Ts, typename std::enable_if_t<std::conjunction_v<std::is_same<int, Ts>...>>* = nullptr>
int flip(set_t mask, Ts... arg) { return ((mask ^= (1 << arg)), ...); }

template <typename set_t = int, typename... Ts, typename std::enable_if_t<std::conjunction_v<std::is_same<int, Ts>...>>* = nullptr>
bool test(set_t mask, Ts... arg) { return ((mask & (1 << arg)) && ...); }

template <typename set_t = int, typename T, typename std::enable_if_t<std::conjunction_v<std::is_same<int, T>>>* = nullptr>
int count_upto(set_t mask, T n) {
  int acc = 0;
  for (int i = 0; i < n; i++)
    if ((mask & (1 << i)) > 0) acc++;
  return acc;
};

template <typename set_t = int>
void assign_inplace(set_t* mask, int pos, int n) {
  if ((test(*mask, pos) and n == 0)
      or (not test(*mask, pos) and n == 1))
    *mask = flip(*mask, pos);
}
}  // namespace utils::dynamic_bitset
class Solution {
 public:
  int movesToChessboard(vector<vector<int>>& board) {
#define ALL(x) begin(x), end(x) 
    using namespace utils::dynamic_bitset;
    const int N = size(board);

    auto get_column = [&](int i) {
      auto result {vector<int>{}};
      for (int r = 0; r < N; ++r) 
        result.emplace_back(board[r][i]);
      return result;
    };

    auto bit_representation = [&](const vector<int>& x) {
      int acc = 0;
      for (int i = 0; i < size(x); ++i)
        assign_inplace(&acc, i, x[i]);
      return acc;
    };

    const auto row_bitmap = [&](vector<int> self = {}) {
      self.resize(N);
      for (int r = 0; r < N; ++r)
        self[r] = bit_representation(board[r]);
      return self;
    }();

    const auto col_bitmap = [&](vector<int> self = {}) {
      self.resize(N);
      for (int c = 0; c < N; ++c) {
        self[c] = bit_representation(get_column(c));
      }
      return self;
    }();

    auto admissable_config = [&](int input) -> optional<vector<int>> {
      const auto one_count = count_upto(input, N);
      const auto head_one  = [&](int acc = 0) {
        for (int i = 0; i < N; i += 2)
          assign_inplace(&acc, i, 1);
        return acc;
      }();
      const auto head_zero = [&](int acc = 0) {
        for (int i = 1; i < N; i += 2)
          assign_inplace(&acc, i, 1);
        return acc;
      }();
      auto result = optional<vector<int>>{};
      if (std::abs(one_count - (N - one_count)) > 1)
        result = std::nullopt;
      else if (N % 2 == 1 and one_count > N - one_count)
        result.emplace({head_one});
      else if (N % 2 == 1 and one_count < N - one_count)
        result.emplace({head_zero});
      else if (N % 2 == 0 and std::abs(one_count - (N - one_count)) == 0)
        result.emplace({head_zero, head_one});
      return result;
    };

    auto cost = [&](int to, int from) { return count_upto(to ^ from, N) / 2; };

    const int solution = [&] {
      if (size(unordered_set<int>(ALL(col_bitmap))) != 2 or size(unordered_set<int>(ALL(row_bitmap))) != 2)
        return -1;
      else {
        const auto row_config = admissable_config(row_bitmap[0]);
        const auto col_config = admissable_config(col_bitmap[0]);
        if (not row_config or not col_config)
          return -1;
        else {
          const auto row_cost = [&](vector<int> self = {}) {
            for (const auto x : row_config.value())
              self.emplace_back(cost(x, row_bitmap[0]));
            return self;
          }();
          const auto col_cost = [&](vector<int> self = {}) {
            for (const auto x : col_config.value())
              self.emplace_back(cost(x, col_bitmap[0]));
            return self;
          }();
          return *min_element(ALL(row_cost)) + *min_element(ALL(col_cost));
        }
      }
    }();
    return solution;
  }
};
```