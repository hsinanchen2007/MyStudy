# 论跳跃游戏的n种解法


>给定一个非负整数数组，你最初位于数组的第一个位置。
>数组中的每个元素代表你在该位置可以跳跃的最大长度。
>判断你是否能够到达最后一个位置。

>示例 1:
>输入: [2,3,1,1,4]
>输出: true

这道题很有意思，相当有趣。有趣之处就在于它的解法很多，花样十足。我们从思路最简单的开始说起。

## 解法一 遍历递归（回溯法）

我们来看题目，好啊，既然每格的数字代表所跳的最大长度，那我就从**第一个格子开始**，**每个长度**我都去试一试，看是否能有一种情况跳到最后的位置。

问题就很简单了，对于值为$num[i]$的第$i$个方块，我们从0-1逐个尝试，如果跳不到最后一格，返回false，可以则返回true。

```cpp
bool canJump(vector<int> nums)
{
	if(nums.size()==0||nums.size()==1) return true;
	bool flag=false;
	for(int i=1;i<=nums[0];++i)
	{
        if(i<=nums.size())
        {
        vector<int> temp=nums;
        temp.erase(temp.begin(),temp.begin()+i);
		if(canJump(temp))
			flag=true;

		}
	}
	return flag;
}

```

## 解法二：带备忘录的自顶向下

众所周知，直接递归很容易出现一个问题，那就是重复子问题。对于不同的情况，有时候会求解相同的子问题，导致大量重复工作的出现，导致超时。因此衍生出了带备忘录的动态规划。

本题里面，对一个确定的数组，它的长度是一个特征值，因此我们可以用这个值来储存当$nums$为该长度时，能否跳到终点。

我们通过c++标准库的map进行储存（试图偷懒

其实不是，为什么不用int或者vector呢，因为bool不是很好表示，不如直接把map抬上来。

```cpp
map<int,bool> maps;

bool canJump(vector<int> nums)
{
	if(nums.size()==0||nums.size()==1) return true;
	bool flag=false;
	auto it=maps.find(nums.size());
	if(it!=maps.end())
		return it->second;
	for(int i=1;i<=nums[0];++i)
	{
        if(i<=nums.size())
        {
        vector<int> temp=nums;
        temp.erase(temp.begin(),temp.begin()+i);
        maps.emplace(temp.size(),canJump(temp));
		if(canJump(temp))
			flag=true;

		}
	}
	return flag;
}
```

然而很遗憾的事情发生了，没有超时，但是超出了内存限制，所以需要更恰当的方法。

## 解法三： 动态规划 自底向上

好，终于到了动态规划登场的时候（不是，我们把能跳到最后一格的位置标记为1，不能跳到的则标记为0，那么从后往前看，如果某一格能跳到后面标记为1的格子，证明它肯定也能跳到最后，标记为1.

也即是：**子问题** *能否跳到最近一个标记为1的方格上*

最后如果第一个方块也标记为1，那么结果就很显然了。

```cpp
bool canJump(vector<int> nums)
{
	if(nums.size()==0||nums.size()==1) return true;
	bool flag=false;
	int n=nums.size();
	int *value=new int[n];
	for(int i=0;i<n;++i)
	{
		value[i]=-1;
	}
	value[n-1]=1;
	for(int j=n-2;j>=0;--j)
	{	
		for(int i=1;i<=nums[j];++i)
		{
			if(j+i>=nums.size())
			{
				value[j]=1;
				break;
			}
			else if(value[j+i]==1)
			{
				value[j]=1;
				break;	
			}
		}
	}
	return value[0]==1;
}
​```
```

然而这执行用时，忒长了。看来还有比这更巧妙的办法。

## 解法四： 能跳多远跳多远

诶，我们想想。我们的目的不就是跳到最后一格吗，那当然是有多远跳多远，考虑那么多干啥呢。~~跳就完事了~~

对于每一个能作为起跳点的格子，依次遍历，都跳最远距离。储存最大值并不断更新，看能否跳到最后一格。

其核心思想是：**如果我能到达某一格，那么左侧的所有位置，我都可以到达！**

```cpp
bool canJump(vector<int>& nums) 
{
	int k = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > k) return false;  //如果当前位置超过了你能到达的最远位置，返回false
		k = max(k, i + nums[i]);
        if(k>nums.size()-1)
            break;
	}
	return true;
}

```

链接：https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/

## 解法五： 别拦着我，我倒着往回跳

这种做法和动态规划的思路一脉相承，但是更加简单，也即是**贪婪法**

其实也和解法四相关，同样的思想：**我能跳到某格，那么左侧的位置我都能到**

因此从后往前遍历，如果该位置能跳到最后，就把数组从该位置**“截断”**，也即是将该位置视为终点。看遍历结束时，终点是否等于起点，如果是，则可以。

```cpp
bool canJump(vector<int>& nums) 
{
	int n=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]+i>=n)
            {
                n=i;
            }
        }
        return n==0;
    }
```



## 解法六： 把0跳过去了就没人能拦住我！！

再换个思路想想。

如果，我说如果，数组中的每个元素都大于零，那能不能跳到终点？很显然可以。

所以之所以跳不到终点，是因为数组里出现了0！

那问题简单了，我们检测每一个零能不能跳过去不就完事了。都能跳过去，那好，完美。有一个不能，~~那没事了~~。

```cpp
bool canJump(vector<int>& nums) 
{
        if(nums.size()==1){ 
            return true;
        }
        if(nums[0]==0){
            return false;
        }
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i]==0){
                int count = 0;
                for(int j = i-1; j>=0; j--){
                    if(nums[j] > i-j){
                        break;
                    }else{
                        count++;
                    }
                }
                if( count==i){
                    return false;
                }             
            }
        }
        return true;
    }
```

综上所述，我认为解法四是最巧妙的，需要有一些想法。

参考：
https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/

https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode/



