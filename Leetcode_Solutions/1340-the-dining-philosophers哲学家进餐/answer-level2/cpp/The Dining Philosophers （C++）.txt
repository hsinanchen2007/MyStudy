```
// https://blog.csdn.net/thelostlamb/article/details/80741319
// Plan B

#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

class DiningPhilosophers {
public:
    DiningPhilosophers() = default;

    void wantsToEat(int philosopher, std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork, std::function<void()> eat,
                    std::function<void()> putLeftFork, std::function<void()> putRightFork) {
        auto left = philosopher % N;
        auto right = (philosopher + 1) % N;
        andLock.lock();
        std::lock_guard<std::mutex> leftLock(forkMutex[left]);
        std::lock_guard<std::mutex> righLock(forkMutex[right]);
        pickLeftFork();
        pickRightFork();
        andLock.unlock();
        eat();
        putLeftFork();
        putRightFork();
    }

private:
    static constexpr int N = 5;
    std::mutex forkMutex[N];
    std::mutex andLock;
};

int main() {
    auto pickLeftFork = []() { std::cout << "[" << std::this_thread::get_id() << ", 1, 1], "; };
    auto pickRightFork = []() { std::cout <<  "[" << std::this_thread::get_id() << ", 2, 1], "; };
    auto eat = []() { std::cout << "[" << std::this_thread::get_id() << ", 0, 3], "; };
    auto putLeftFork = []() { std::cout << "[" << std::this_thread::get_id() << ", 1, 2], "; };
    auto putRightFork = []() { std::cout << "[" << std::this_thread::get_id() << ", 2, 2], "; };
    auto execute = [&](int n) {
        DiningPhilosophers diningPhilosophers;
        std::thread t1(&DiningPhilosophers::wantsToEat, &diningPhilosophers, 1, pickRightFork,
            pickRightFork, eat, putRightFork, putRightFork);
        std::thread t2(&DiningPhilosophers::wantsToEat, &diningPhilosophers, 2, pickRightFork,
            pickRightFork, eat, putRightFork, putRightFork);
        std::thread t3(&DiningPhilosophers::wantsToEat, &diningPhilosophers, 3, pickRightFork,
            pickRightFork, eat, putRightFork, putRightFork);
        std::thread t4(&DiningPhilosophers::wantsToEat, &diningPhilosophers, 4, pickRightFork,
            pickRightFork, eat, putRightFork, putRightFork);
        std::thread t5(&DiningPhilosophers::wantsToEat, &diningPhilosophers, 5, pickRightFork,
            pickRightFork, eat, putRightFork, putRightFork);
        t1.join(); t2.join(); t3.join(); t4.join(); t5.join();
    };

    execute(1);
    std::cout << std::endl;
}
```