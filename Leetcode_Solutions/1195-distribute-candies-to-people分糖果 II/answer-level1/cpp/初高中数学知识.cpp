这题分糖果的过程是个等差数列，比如11个糖，等差数列为1 2 3 4 1，前4项为等差数列，最后一项是剩余的糖果。我们只要求出前n项为等差数列，循环n次每次给第n%num_people个数组元素加上i(i表示循环次数），最后再将剩余糖果分给后一个小朋友就好了。
由倒叙相加法（高斯小学时候就想到的）得到等差数列求和公式n*(n+1)/2,令n*(n+1)/2=candies，化简可得n^2+n-2candies = 0;一元二次方程的对称轴为-1/2，所以不会出现在非负数区间有两个解，由一元二次方程求根公式（初中数学）可得n=(-1+sqrt(1+8*candies))向下取整就是所要求的n。

vector<int> distributeCandies(int candies, int num_people) {
    long long int n{ 0 };  //等差数列项数,不用long long int会溢出
    n = (-1 + sqrt<long long int>((long long int)1 + (long long int)8 * candies)) / 2;  //计算得到n
    int  Remainder = candies - (n * (n + 1)) / 2;  //得到剩余的糖果
    vector<int> peopleCandies(num_people);
    auto itr{ peopleCandies.begin() };
    for (int i = 1; i <= n; i++)  //发糖果
    {
        *itr += i;
        itr++;
        if (itr == peopleCandies.end())  //给最后一个孩子发完了
            itr = peopleCandies.begin();  //再回到第一个孩子
    }
    *itr += Remainder;  //把剩余的糖果发给孩子
    return peopleCandies;  //返回结果
}
