发现和国际版大佬思路一样，只是我用 vector 代替了 hash_map
https://leetcode.com/problems/longest-well-performing-interval/discuss/334565/JavaC%2B%2BPython-O(N)-Solution-Life-needs-996-and-669
```c++
    int longestWPI(vector<int>& hours) {
        vector<int> vt; 
        int n = hours.size(), ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            cur += hours[i] > 8 ? -1 : 1;
            int len = vt.size(); 
            if (cur > len) {
                vt.push_back(i); 
            } else if (cur < len) {
                ans = cur < 0 ? i+1 : max(ans, i - vt[cur]);
            }
        }
        return ans;
    }
```
