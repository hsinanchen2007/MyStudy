
题目：给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
第一反应是用Integer.toString()将整数转为字符串,然后将字符串反转reverse(),再用Integer.parseInt)(将字符串转换为整数输出,这样好像有点low？反正我看没人这么做。。。所以综合了各个大神的code，总结如下

比如
int x = 56;
想要反转的话，结果应该是65，所以，分别对该数取余，貌似可以。
好，先设定一个变量ans，用来存储反转后的数字。
int ans = 0;
然后开始逐个得到x取余结果
while (x != 0){
    int pop = x % 10;//6
    ans = ans * 10 + pop;//6
    x /= 10;//5
}
一次计算完后，ans = 6,x = 5 ,再执行第二次，结果是  pop = 5 , ans = 65, x = 0;
x = 0 ,不满足条件，不再循环
之后 return ans,即可
貌似到这里，我们正常反转了这个整数，但是题目中有一个限制，32位，所以，取值范围是 [−2的31次方,  2的31次方 − 1]，所以要ans进行限定
if (ans > Integer.MAX_VALUE / 10 || ans == Integer.MAX_VALUE / 10 + pop && pop > 7){
return 0
}
if (ans < Integer.MIN_VALUE / 10 || ans == Integer.MIN_VALUE / 10 + pop && pop < -8{
return 0
}

Mark：
INT_MAX,INT_MIN由标准头文件<limits.h>定义。
INT_MAX=2^31-1(2,147,483,647)
INT_MIN=-2^31(-2,147,483,648)

所以，完整代码如下：
 public int reverse(int x){
        int ans = 0;//ans是计算结果
        while (x != 0) {
            int pop = x % 10;
            System.out.println(pop);
            if (ans > Integer.MAX_VALUE / 10 || (ans == Integer.MAX_VALUE / 10 && pop > 7))
                return 0;
            if (ans < Integer.MIN_VALUE / 10 || (ans == Integer.MIN_VALUE / 10 && pop < -8))
                return 0;
            ans = ans * 10 + pop;
            x /= 10;
        }
        return ans;
 }