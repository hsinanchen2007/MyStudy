首先我们知道当n=1 时，只有一种情况，即["()"]；
当n=2的时候，也很容易知道为["(())","()())"];
那么当n=3的时候呢？
它是在n=2的基础上进行构建，在n=2时候的每一个括号组合的每一个间隔里面插入"()"就可以了。
比如以"(())"为例：
n=3的构造方法为："(())"索引分分别对应0,1,2,3.
在0与1的位置中间插入"()"得到"(()())";
1与2的位置之间："((()))";
2与3之间："(()())",与之前情况有重复，跳过；
所以由"(())"构造出的n=3的情况有"(()())","((()))"这2种;
同理，由"()()"构造出的有"(())()","()()()","()(())"3种，所以n=3的组合总共有5种。
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n==0:
            return ['']
        if n==1:
            return ['()']
        if n==2:
            return ['(())','()()']
        memo={}
        memo[0]=['']
        memo[1]=['()']
        memo[2]=['(())','()()']
        for i in range(3,n+1):
            memo[i]=[]
            for j in range(len(memo[i-1])):
                for k in range(1,(i-1)**2):
                    if memo[i-1][j][:k+1]+'()'+memo[i-1][j][k+1:] in memo[i]:
                        continue
                    else:
                        memo[i].append(memo[i-1][j][:k+1]+'()'+memo[i-1][j][k+1:])
        return memo[n]


