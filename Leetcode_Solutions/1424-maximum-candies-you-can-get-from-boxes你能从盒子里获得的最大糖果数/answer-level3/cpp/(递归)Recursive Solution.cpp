

##### Algorithm (Recursion with controlled side effects)
1. The $V$ be the set of boxes that are available now from which we can take candies. Then the problem is then reduced to finding $f(V_0)$, where $V_0$ is the initial set.
2. Note that we have 
$$
\begin{aligned}
f(V) = \begin{cases} 
\texttt{candies[$x$]} + f(\text{open}(V, x)) & \text{if } V\neq \emptyset \\
0 & \text{if } V = \emptyset
\end{cases}
\end{aligned}
$$
3. Now we just need to routinely implement the `open` subroutine in order to get the answer. When we open a box, we collect all its candies and nested boxes and keys and store them in a preallocated cache. Then we iterate throught the currently collected boxes and compare them with currently held keys; if there are any matches, we then update $V$. 
4. The above subroutine could either return a new $V$ in a persistent manner or a pointer of one static version. We chose the second one for efficiency purposes.

##### Code 

```c++
template <class F>
struct recursive {
  F f;
  template <class... Ts>
  decltype(auto) operator()(Ts&&... ts)  const { return f(std::ref(*this), std::forward<Ts>(ts)...); }
  
  template <class... Ts>
  decltype(auto) operator()(Ts&&... ts)  { return f(std::ref(*this), std::forward<Ts>(ts)...); }
};

template <class F> recursive(F) -> recursive<F>;
auto const rec = [](auto f) { return recursive{std::move(f)}; };

class Solution {
public:
    int maxCandies(vector<int>& status,
                   vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {


      const auto N = size(status);

      const auto keyset = [&](vector<unordered_set<int>> self = {}) {
        self.assign(N, unordered_set<int> {});
        for (int i = 0; i < N; ++i) 
          std::copy(begin(keys[i]), end(keys[i]), std::inserter(self[i], begin(self[i])));
        return self;
      }();

      auto open = [&,
                   kept = unordered_set<int> (begin(initialBoxes), end(initialBoxes)),
                   used = unordered_set<int> {},
                   keys_in_hand = unordered_set<int>{}] (unordered_set<int> * current, int id) mutable  {
        used.insert(id);
        current->erase(id);
        std::copy(begin(containedBoxes[id]), end(containedBoxes[id]), std::inserter(kept, begin(kept)));
        std::copy(begin(keys[id]), end(keys[id]), std::inserter(keys_in_hand, begin(keys_in_hand)));
        for (const auto box : kept) {
          if (used.count(box) > 0)
            continue;
          else if (keys_in_hand.find(box) != end(keys_in_hand) or status[box] == 1)
            current->insert(box);
        }
        return current;
      };

      auto initial_available_boxes = [&](unordered_set<int> self = {}) {
        for (const auto box : initialBoxes) 
          if (status[box] == 1)
            self.insert(box);
        return self;
      }();

      auto f = rec([&](auto &&f, unordered_set<int> * available_boxes) -> int {
        if (available_boxes->size() == 0)
          return 0;
        else {
          const auto id = *(available_boxes->begin());
          return candies[id] + f(open(available_boxes, id));
        }
      });

      return f(&initial_available_boxes);
    }
};

};
```
