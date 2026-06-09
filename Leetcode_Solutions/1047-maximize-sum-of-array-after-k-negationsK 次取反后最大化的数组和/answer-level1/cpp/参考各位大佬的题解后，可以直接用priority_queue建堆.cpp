```cpp
int largestSumAfterKNegations(vector<int>& A, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    for (int num : A) {pq.push(num); sum += num;}
    while (K--) {
        int cur = pq.top();
        pq.pop();
        pq.push(-cur);
        sum -= cur * 2;
    }
    return sum;
}
```