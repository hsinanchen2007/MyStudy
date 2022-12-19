class Foo(object):
    def __init__(self):
        self.a=1
        pass


    def first(self, printFirst):
        """
        :type printFirst: method
        :rtype: void
        """
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.a=2


    def second(self, printSecond):
        """
        :type printSecond: method
        :rtype: void
        """
        while self.a!=2:
            continue
        # printSecond() outputs "second". Do not change or remove this line.
        printSecond()
        self.a=3
            
            
    def third(self, printThird):
        """
        :type printThird: method
        :rtype: void
        """
        while self.a!=3:
            continue
        # printThird() outputs "third". Do not change or remove this line.
        printThird()