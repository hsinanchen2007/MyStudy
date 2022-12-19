class H2O {
 public:
  H2O() : hy_count_(0), ox_count_(0) {}

  void hydrogen(std::function<void()> releaseHydrogen) {
    int expected1 = 0;
    int expected2 = 1;

    while (!hy_count_.compare_exchange_weak(expected1, 1) &&
           !hy_count_.compare_exchange_weak(expected2, 2)) {
      expected1 = 0;
      expected2 = 1;
      std::this_thread::yield();
    }
    releaseHydrogen();

    if (hy_count_== 2 && ox_count_ == 1) {
      hy_count_ = 0;
      ox_count_ = 0;
    }
  }

  void oxygen(std::function<void()> releaseOxygen) {
    int expected = 0;
    while (!ox_count_.compare_exchange_weak(expected, 1)) {
      expected = 0;
      std::this_thread::yield();
    }
    releaseOxygen();
     if (hy_count_ == 2) {
      hy_count_ = 0;
      ox_count_ = 0;
    }
  }

 private:
  std::atomic<int> hy_count_;
  std::atomic<int> ox_count_;
};