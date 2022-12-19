
    class Foo {
    public:
        Foo() {
        }

        void first(function<void()> printFirst) {
            // printFirst() outputs "first". Do not change or remove this line.
            printFirst();
            one.set_value();
        }

        void second(function<void()> printSecond) {
            one.get_future().wait();
            // printSecond() outputs "second". Do not change or remove this line.
            printSecond();
            two.set_value();
        }

        void third(function<void()> printThird) {
            two.get_future().wait();
            // printThird() outputs "third". Do not change or remove this line.
            printThird();
        }
    private:
        std::promise<void> one;
        std::promise<void> two;
    };