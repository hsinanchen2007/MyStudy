class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.dict = {}
        
    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        self.dict[1] = printFizz
        self.res()
    	

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        self.dict[2] = printBuzz
        self.res()
    	

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        self.dict[3] = printFizzBuzz
        self.res()
		

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        self.dict[0] = printNumber
        self.res()
        
    def res(self):
        if len(self.dict) == 4:
            for i in list(range(1,self.n+1)):
                #if (i%3)== 0 and (i%5)==0:  #求15的余数比上边并列判断竟然还慢了；
                if (i%15) == 0:
                    self.dict[3]()
                elif (i%3)==0:
                    self.dict[1]()
                elif (i%5)==0:
                    self.dict[2]()
                else:
                    self.dict[0]()