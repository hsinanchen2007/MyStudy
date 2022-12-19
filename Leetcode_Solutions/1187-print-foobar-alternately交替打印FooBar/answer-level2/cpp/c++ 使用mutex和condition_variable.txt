1.获取锁
2.判断step_为0时打印foo,step为1时打印bar
3.解锁
4.修改step_
5.通知等待线程
```
class FooBar {
 public:
  FooBar(int n) : step_(0) { this->n = n; }

  void foo(std::function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      std::unique_lock<std::mutex> lk(mu_);
      cv_.wait(lk, [this] { return step_ == 0; });
      printFoo();
      step_ = 1;
      lk.unlock();
      cv_.notify_one();
    }
  }

  void bar(std::function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      std::unique_lock<std::mutex> lk(mu_);
      cv_.wait(lk, [this] { return step_ == 1; });
      printBar();
      step_ = 0;
      lk.unlock();
      cv_.notify_one();
    }
  }

 private:
  int n;
  int step_;
  std::mutex mu_;
  std::condition_variable cv_;
};
```