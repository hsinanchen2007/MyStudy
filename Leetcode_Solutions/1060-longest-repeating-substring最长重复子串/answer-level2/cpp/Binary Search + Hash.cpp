先看了下答案，都是用 binary search + rolling hash 的。看了半天没看懂 rolling hash 怎么写，索性抱着试试看的心态，不 roll 了，直接 `unordered_set<string>`，竟然也通过了。40ms.

```c++
class Solution {
public:
    int longestRepeatingSubstring(string S) {
        unordered_set<string> history;

        // Binary search:
        // 1. Attempt to check if there exists repeating substrings with window size (mid) = (0 + S.size()) / 2
        // 2. If yes, update the best record so far, and attempt an even higher window size = (mid + 1 + S.size()) / 2.
        // 3. If no, attempt a narrower window size = (0 + mid) / 2;
        // 4. Repeat
        int left = 0;
        int right = S.size();
        int best = 0;  // the best record so far
        while (left < right) {
            int mid = (left + right) / 2;
            bool hasRepeating = repeatingWithLength(S, mid, &history);
            if (hasRepeating) {
                best = max(best, mid);
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // We do not accept a single letter as a substring.
        if (best == 1) return 0;

        return best;
    }

private:
    // Check if there is a repeating substring with size `n`.
    // Idea: Create a sliding window of size `n`. Slide it while inserting visited substrings
    //       into a hash set called `history`. If the substring created by a window has appeared
    //       in `history`, return true immediately. Otherwise, if all substrings are unique, then
    //       return false;
    // Arguments:
    //   - s: the source string
    //   - n: size of the sliding window
    //   - history: a temporary buffer used to store visited substrings.
    bool repeatingWithLength(const string& s, int n, unordered_set<string>* history) {
        history->clear();
        string sub;
        for (int i = 0; i <= s.size() - n; ++i) {
            sub = s.substr(i, n);
            if (history->find(sub) != history->end()) return true;
            history->insert(sub);
        }
        return false;
    }
};
```