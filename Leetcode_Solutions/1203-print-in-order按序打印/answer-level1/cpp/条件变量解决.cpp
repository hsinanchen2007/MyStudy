就解决这个问题来说应该是复杂了一点，看到这题我第一想到了生产者消费者问题，这类控制线程顺序的问题应该都有类似点吧。
```
class Foo
{
public:
    Foo()
    {
        m_isFirstThreadComplete = false;
        m_isSecondThreadComplete = false;
    }

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        unique_lock<mutex> lock(m_firstMutex);
        m_firstCond.notify_one();
        m_isFirstThreadComplete = true;
    }

    void second(function<void()> printSecond)
    {
        while(!m_isFirstThreadComplete)
        {
            unique_lock<mutex> lock(m_firstMutex);
            m_firstCond.wait(lock);
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        unique_lock<mutex> lock2(m_secondMutex);
        m_secondCond.notify_one();
        m_isSecondThreadComplete = true;
    }

    void third(function<void()> printThird)
    {
        while(!m_isSecondThreadComplete)
        {
            unique_lock<mutex> lock(m_secondMutex);
            m_secondCond.wait(lock);
        }

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    mutex m_firstMutex;
    condition_variable m_firstCond;
    bool m_isFirstThreadComplete;

    mutex m_secondMutex;
    condition_variable m_secondCond;
    bool m_isSecondThreadComplete;

};
```