好吧，我的递归实在是太菜了，大家不用看了，我把评论里面一位大佬的粘贴出来，真的是强！！！！
```
class Solution:
    def digitsCount(self, d: int, low: int, high: int) -> int:
        def find(x,tar): #这个find函数简洁优美，赏心悦目，值得大家收藏。
            if tar<10:
                if x<=tar:
                    return 1
                else:
                    return 0
            else:
                q=tar//10
                res=tar-q*10
                result=q+find(x,res)
                result+=(find(x,q-1)-find(x,0))*10+(find(x,q)-find(x,q-1))*(res+1)
                return result
        return find(d,high)-find(d,low-1)
```

### 前言
我发现，对于这类题目我每次都要花很长的时间才能做的出来，然后看阅读量最高的题解，讲真，确实很优美，但是你知道的，数学法不是每次都能马上想出来的，对于这类题目到底有没有通用的模板呢，如何才能在短时间内做出来的呢？

### 形式化
这类题目有一个统一的特点，就是十进制表示的数字，比如233，讨论它每一个位之间的关系，想着到，让你统计d的数量，前面还有一道，然你统计180度翻转之后任然有效的总数什么的，统一来说，就是统计每位数上满足某某条件的在某个范围内的总数。

### 我的模板

暂时是递归版本的，后续想想dp版本的，当然，递归开销就算是有重叠子问题影响也不大，因为最多不就10位数吗，一次递归就少了一位，效率上并不会有多大的影响。

`void count_all(int N, long& total_without_zero, long &total_with_zero, int d)`

以这道题为例，N是上限，比如233,我们统计的是[1:233]的满足条件的数量。total_without_zero就是我们要的解，total_with_zero这个是带前缀0的也统计在内，具体怎么用后续会说。

模板把[1:233]分成两个子问题，统计[100:233]的数量,[1:99]直接递归求解，也就是说，我们每一次递归核心程序求的是某一位数的总数，例如这个就是求满足条件的三位数的数量。

针对这道题，我们把k>0和k==0成两大类讨论。
大家可以先看一下，我为了统计[100:233]中d的数量分成了多少类。其中肯定是有冗余的，但为了逻辑清晰，忍忍吧。

1. **k>0,例如,k=5** 注意，这一部分里面,total_with_zero 不用统计。
先求出233首位数字high_bit=2和剩余量rest=33,接下来就分成两部分计算
    1. **[100:199],首位是小于最高位**
        每一次统计，继续会分成两部分，d出现在最高位的次数，d出现在低位的次数
        1. **d出现在最高位的次数**
            然后我们还要继续分类，因为d和high_bit的大小关系决定了d能否出现在最高位
            1. **high_bit>d**
                d可以出现在最高位，例如取d==1,那么[100:199]，也就是100个数字里面的最高位的1,可以统计进去
            1. **high_bit==d**
                这一部分我们放在后面统计，因为这一部分最高位就是d了，我们说好把这一部分放在[200:233]里面统计的。
            1. **high_bit<d**
                不可能出现在最高位，所以为0
        2. **d出现在低位中的次数**
            在这里就是子问题[1:99]中的次数
    2. **[200:233],首位就是最高位**
        每一次统计，继续会分成两部分，d出现在最高位的次数，d出现在低位的次数
        1. **d出现在最高位的次数**
            1. **high_bit==d**
                只有这种情况，才能出现在最高位，例如d==2.
                奇数的话，显然是rest+1,也就是说[200:233]里面数字的百位数的2都可以统计进来。
        2. **d出现在低位中的次数**
            rest=33,显然又是子问题f(rest)

1. **k==0**
    1. **[100:199],首位是小于最高位**
        每一次统计，继续会分成两部分，d出现在最高位的次数，d出现在低位的次数
        1. **d出现在最高位的次数**
        显然,0是不可能出现在最高位的，这个时候，我们统计的就是total_with_zero，也就是说，我们会把001也看成三位数，total_with_zero 总计的不是小于[1:N]的0出现的次数，而是[100:233]出现0的次数，也就是说，001,002,里面的四个0都会统计进来。
为什么统计这个，后续有用。
        2. **d出现在低位中的次数**
		子问题f(99)*high_bit
    2. **[200:233],首位就是最高位**
        每一次统计，继续会分成两部分，d出现在最高位的次数，d出现在低位的次数
        1. **d出现在最高位的次数**
			不可能出现在最高位，因为显然high_bit>0
        2. **d出现在低位中的次数**
			重点来了，total_with_zero就是为了统计这一部分准备的。

d==0部分待更。先把完整代码放出来。

```
void count_all(int N, long& total_without_zero, long &total_with_zero, int d)//计算1<=x<=N的满足某个条件的x的总数 total_without_zero 不统计包含前缀0的 total_with_zero 统计包括前缀0的
	{
		if (N <= 9)
		{
			total_without_zero += N >= d;//0 1 8
			total_with_zero = N >= d;
			return;
		}
		long div = 1;
		int n = 1;//至少两位数
		while (N >= div * 10)// 统计位数 如 N=123 则div=100
		{
			n++;
			div *= 10;
		}
		int first_num = N / div;
		int rest = N - first_num * div;

		//先统计当前位的数量 [100:123]

		long cur_bit_sum1 = 0, cur_bit_sum2 = 0;
		long sum_tmp1 = 0, sum_tmp2 = 0;

		if (d == 0)
		{
			//不包含first_num
			sum_tmp1 = 0, sum_tmp2 = 0;
			count_all(div - 1, sum_tmp1, sum_tmp2, d);
			cur_bit_sum1 += (first_num - 1)*sum_tmp2;
			cur_bit_sum2 += first_num * sum_tmp2+div;

			//包含first_num
			int old_div = div;
			div /= 10;
			int n = 0;
			while (rest < div)
			{
				n++;
				div /= 10;
			}
			if (rest == 0)
			{
				cur_bit_sum1 += n * (rest + 1);
				cur_bit_sum2 += n * (rest + 1);

				count_all(old_div - 1, total_without_zero, total_with_zero, d);
				total_without_zero += cur_bit_sum1;
				total_with_zero = cur_bit_sum2;
				return;
			}
			else
			{ 
				cur_bit_sum1 += n * (rest + 1);
				cur_bit_sum2 += n * (rest + 1);


				sum_tmp1 = 0, sum_tmp2 = 0;
				count_all(rest, sum_tmp1, sum_tmp2, d);

				cur_bit_sum1 += sum_tmp2;
				cur_bit_sum2 += sum_tmp2;
				count_all(old_div - 1, total_without_zero, total_with_zero, d);

				//再加上当前[100:123]部分
				total_without_zero += cur_bit_sum1;
				total_with_zero = cur_bit_sum2;
				return;
			}



		}

		if (first_num > d)
		{
			//不包含first_num
			sum_tmp1 = 0, sum_tmp2 = 0;
			count_all(div - 1, sum_tmp1, sum_tmp2, d);
			cur_bit_sum1 += div + (first_num - 1)*sum_tmp1;
			cur_bit_sum2 += div + first_num * sum_tmp1;

			//包含first_num
			sum_tmp1 = 0, sum_tmp2 = 0;
			count_all(rest, sum_tmp1, sum_tmp2, d);
			cur_bit_sum1 += sum_tmp1;
			cur_bit_sum2 += sum_tmp1;
		}
		else if (first_num == d)
		{
			//不包含first_num
			sum_tmp1 = 0, sum_tmp2 = 0;
			count_all(div - 1, sum_tmp1, sum_tmp2, d);
			cur_bit_sum1 += (first_num - 1)*sum_tmp1;
			cur_bit_sum2 += (first_num)*sum_tmp1;

			//包含first_num
			sum_tmp1 = 0, sum_tmp2 = 0;
			count_all(rest, sum_tmp1, sum_tmp2, d);
			cur_bit_sum1 += rest + 1 + sum_tmp1;
			cur_bit_sum2 += rest + 1 + sum_tmp1;

		}
		else if (first_num < d)
		{
			//不包含first_num
			sum_tmp1 = 0, sum_tmp2 = 0;
			count_all(div - 1, sum_tmp1, sum_tmp2, d);
			cur_bit_sum1 += (first_num - 1)*sum_tmp1;
			cur_bit_sum2 += first_num * sum_tmp1;

			//包含first_num
			sum_tmp1 = 0, sum_tmp2 = 0;
			count_all(rest, sum_tmp1, sum_tmp2, d);
			cur_bit_sum1 += sum_tmp1;
			cur_bit_sum2 += sum_tmp1;
		}

		//到此为止 当前位的计算完毕

		//先加上[1:99]部分
		count_all(div - 1, total_without_zero, total_with_zero, d);

		//再加上当前[100:123]部分
		total_without_zero += cur_bit_sum1;
		total_with_zero = cur_bit_sum2;
	}
```

