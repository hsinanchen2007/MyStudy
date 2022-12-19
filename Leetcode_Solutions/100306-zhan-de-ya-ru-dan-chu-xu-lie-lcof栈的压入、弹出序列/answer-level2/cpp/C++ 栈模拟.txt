```c++
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    std::stack<int> s;
    int j = 0;
    for (auto v : pushed) {
        s.push(v);
        while (!s.empty() && j < popped.size() && s.top() == popped[j]) {
            s.pop();
            ++j;
        }
    }
    return s.empty();
}
```