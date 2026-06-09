入队的时候直接把数据放入in栈中
出队的时候如果out栈为空，则把所有in栈中数据弹入out栈，否则，直接弹出

```
class CQueue {
  public:
    CQueue() {}

    void appendTail(int value) { in.push(value); }

    int deleteHead() {
        if (out.empty()) {
            while (not in.empty()) {
                out.push(in.top());
                in.pop();
            }
            if (out.empty()) return -1;
        }
        auto tmp = out.top();
        out.pop();
        return tmp;
    }

  private:
    std::stack<int> in;
    std::stack<int> out;
};

```