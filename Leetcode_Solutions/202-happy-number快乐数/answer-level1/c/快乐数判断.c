# 解法1：使用Hash集合，编程语言Java语言
思想：首先编写求一个数各位平方和的函数。在判断它是否是快乐数的函数中，构建一个<Integer>类型的哈希集合。如果这个数是1，终止循环，返回是快乐数。否则，求它的各位平方和若哈希集合中没有，则将其加入，若已经存在，说明已经构成循环，返回不是快乐数即可。
```
public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>();
        while (n != 1) {
            n = toSumOfSquares(n);
            if (set.contains(n)) {
                return false;
            } else {
                set.add(n);
            }
        }
        return true;
    }

    private int toSumOfSquares(int n) {
        int sum = 0;
        do {
            int num = n % 10;
            sum += num * num;
            n = n / 10;
        } while (n > 0);

        return sum;
    }
```
# 解法2：快慢指针法，编程语言C/C++,本题类似于环形链表。具体解析请见注释。
```
int getSquareNumber(int n)  //得到平方和
{
    int num=0;
    while(n)
    {
        int tmp=n%10;  //分离出末尾数
        num=num+tmp*tmp;
        n=n/10;
    }
    return num;
}


bool isHappy(int n){
   int slow=n,fast=n;
   while(n!=1)
   {
       //慢指针走一步，快指针走两步。判断是否出现循环。（类似环形链表例题）
       //如果出现环（快慢指针相遇），退出循环，这时要判断是1形成的环还是由其他原因形成的环。如果是由1形成的则是快乐数。否则不是
       slow=getSquareNumber(slow);
       fast=getSquareNumber(fast);
       fast=getSquareNumber(fast);
       if(slow==fast)
        break;
   }
   return slow==1? true:false;
}
```
