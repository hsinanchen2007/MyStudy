产生氢原子的线程：当前所产生的氢原子数量小于2就可以产生1个氢原子，
之后检查是否产生了2个氢原子和1个氧原子，如果是则重置数量。

产生氧气子的线程：当前所产生的氧原子数量为0就可以产生一个氧原子，
之后检查是否已经产生了2个氢原子，如果是则重置数量。

```
class H2O {
 public:
  H2O() : hy_count_(0), ox_count_(0) {}

  void hydrogen(std::function<void()> releaseHydrogen) {
    std::unique_lock<std::mutex> lk(mu_);
    cv_.wait(lk, [this] { return hy_count_ < 2; });
    releaseHydrogen();
    ++hy_count_;
    if (ox_count_ == 1 && hy_count_ == 2) {
      ox_count_ = 0;
      hy_count_ = 0;
    }
    lk.unlock();
    cv_.notify_one();
  }

  void oxygen(std::function<void()> releaseOxygen) {
    std::unique_lock<std::mutex> lk(mu_);
    cv_.wait(lk, [this] { return ox_count_ < 1; });
    releaseOxygen();
    ++ox_count_;
    if (hy_count_ == 2) {
      ox_count_ = 0;
      hy_count_ = 0;
    }
    lk.unlock();
    cv_.notify_one();
  }

 private:
  int hy_count_;
  int ox_count_;
  std::mutex mu_;
  std::condition_variable cv_;
};
```