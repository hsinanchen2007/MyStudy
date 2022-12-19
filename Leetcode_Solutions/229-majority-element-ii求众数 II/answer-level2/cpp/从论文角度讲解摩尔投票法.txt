## 参考资料

1. [论文MJRTY A Fast Majority Vote Algorithm](https://www.cs.ou.edu/~rlpage/dmtools/mjrty.pdf)
2. [算法演示网站](https://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html)
3. [维基百科](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm)

## 算法解读

### 概述

> ![](https://pic.leetcode-cn.com/2eb3d29fada9e61debb577a0b0b5e7665ba6a002e06937fc8b06110168830fdc.png)


摩尔投票法(Boyer–Moore majority vote algorithm)出自[论文](https://www.cs.ou.edu/~rlpage/dmtools/mjrty.pdf)，算法解决的问题是如何在任意多的候选人（选票无序），选出获得票数最多的那个。常见的算法是扫描一遍选票，对每个候选人进行统计的选票进行统计。当候选人的数目固定时，这个常见算法的时间复杂度为：$O(n)$，当候选人的数目不定时，统计选票可能会执行较长时间，可能需运行$O(n^2)$的时间。当选票有序时，可以很容易编出$O(n)$的程序，首先找到中位数，然后检查中位数的个数是否超过选票的一半。这篇论文针对无序且侯选人不定的情形，提出了摩尔投票算法。算法的比较次数最多是选票（记为n）的两倍，可以在$O(n)$时间内选出获票最多的，空间开销为$O(1)$。

### 算法

> ![](https://pic.leetcode-cn.com/cf3d5c84505378c2260e9331ac7f673bd4e55e2dbe7c79093eda184700d29b7f.png)

- 形象化描述

想象着这样一个画面：会议大厅站满了投票代表，每个都有一个牌子上面写着自己所选的候选人的名字。然后选举意见不合的（所选的候选人不同）两个人，会打一架，并且会同时击倒对方。显而易见，如果一个人拥有的选票比其它所有人加起来的选票还要多的话，这个候选人将会赢得这场“战争”，当混乱结束，最后剩下的那个代表（可能会有多个）将会来自多数人所站的阵营。但是如果所有参加候选人的选票都不是大多数（选票都未超过一半），那么最后站在那的代表（一个人）并不能代表所有的选票的大多数。因此，当某人站到最后时，需要统计他所选的候选人的选票是否超过一半（包括倒下的），来判断选票结果是否有效。

> ![](https://pic.leetcode-cn.com/f3892e566761614f22a5d669d172bfa9a5c4c1e07926e468c523ed19b8f45c0e.png)

- 算法步骤

算法分为两个阶段：**pairing**阶段和**counting**阶段。

1. **pairing**阶段：两个不同选票的人进行对抗，并会同时击倒对方，当剩下的人都是同一阵营，相同选票时，结束。

2. **counting**阶段：计数阶段，对最后剩下的下进行选票计算统计，判断选票是否超过总票数的一半，选票是否有效。

> ![](https://pic.leetcode-cn.com/8d6cc40262af20b3291d20bebdf8f67f77e09ecb3ea9f7b557ad752aa2cc558d.png)

- **pairing**阶段的简化

选票不同就要大干一架，太过粗鲁，这里提供一种更加现代化的文明方式。
在场的有个叫`onwaier`的，他很聪明，他想到一个方法。他用他那犀利人目光扫一遍所有代表们的选票，在脑子记住两件事，当前的候选人的名字`cand`和他对应的计数`k`（并不是他的选票数）。起始时，`k`的值为0，看每个人的选票时，先想想现在`k`是否为0，如果是0就将`cand`更新为他将看到的候选人的名字并且将`k`的值更新为1。观察每个人选票的过程，如果这个人的选票与`cand`相同，则将`k`的值加1；否则，将`k`的值减1。最后的`cand`可能胜选，还需统计他的总选票数是否超过一半。

### 算法证明

> ![](https://pic.leetcode-cn.com/7f4a0bc91df176a8856dd1ca336f339885634ecfb4d7926c8d17b24bc390f001.png)

**证明**：

假设共有n个代表（一人一票，选票总数为n）。当`onwaier`看到第i个代表的选票时$(1 \leq i \leq n)$，前面他已经看到的所有选票可以分为两组，第一组是`k`个代表赞同`cand`；另一组是选票可以全部成对（选票不同）抵销。当处理完所有的选票时，如果存在大多数，则`cand`当选。
假设存在一个`x`其不同于`cand`，但拥有的选票超过$n/2$。但因为第二组的选票可以全部成对抵销，所以`x`最多的选票数为$(n - k) / 2$，因此`x`必须要收到第一组的选票才能超过一半，但是第一组的选票都是`cand`的，出现矛盾，假设不成立。
所以，如果存在大多数，`cand`就是那个。

### 算法演示

来自[网站](https://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html)

选票情况为：
A A A C C B B C C C B C C
结果应该是`C`

- 算法执行过程
![](https://pic.leetcode-cn.com/76ab0f592cceba613016d5b9c6b5eb6a5e4607dc12d50deab1de33debd4604ff.gif)
### 算法代码

- 伪代码

伪代码来自[维基百科](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm)
> ![](https://pic.leetcode-cn.com/a6bb42871f3f07df5d37fb3472f393bca6584c30c274080a95176752bbb880fe.png)

- c++代码

```cpp
/*
根据多数元素出现的次数大于n/2且超过其它元素出现次数之和这一特点，进行统计

时间复杂度为：O(n)
空间复杂度为：O(1)
*/
int majorityElement(vector<int>& nums) {
	int k = 0, cand = 0;
	//成对抵销阶阶段
	for(auto num:nums){
		if(k == 0){
			cand = num;
			k = 1;
		}
		else{
			if(num == cand){
				++k;
			}
			else{
				--k;
			}
		}
	}
	//计数阶段 判断cand的个数是否超过一半
	k = 0;
	for(auto num:nums){
		if(num == cand){
			++k;
		}
	}
	if(k <= nums.size() / 2){
		cand = -1;//表示未超过一半 
	}
	return cand;
}
```

## 算法应用

摩尔投票法的一大应用就是求众数。
相关题目有：

1. [169. 多数元素](https://leetcode-cn.com/problems/majority-element/)

其中题1的代码和上面的c++代码相同，它就是摩尔选票法的直接应用。
```cpp
/*
根据多数元素出现的次数大于n/2且超过其它元素出现次数之和这一特点，进行统计

时间复杂度为：O(n)
空间复杂度为：O(1)

摩尔选票法的直接应用，因为题目说明一定存在大多数，所以不用进行第二阶段
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, res = 0;
        for(auto num:nums){
            if(cnt == 0){
                res = num;
                cnt = 1;
            }
            else{
                if(num == res){
                    ++cnt;
                }
                else{
                    --cnt;
                }
            }
        }
        return res;
    }
};
```

2. [229. 求众数 II](https://leetcode-cn.com/problems/majority-element-ii/)

题2的代码则是摩尔选票法的变形。

题2可以看成这样一个情形：一个班里要选副班长，至多2位。每一个投一票，成为副班长得票必须超过总票数的三分之一。
因为可能会产生两名。所以候选人$cand$与计数$cnt$都转成相应的数组形式$cands$与$cnts$，长度都为2。
第一阶段成对抵销时，`cands[0]`与`cands[1]`的选票不相互抵销，即如果代表将票投给了`cands[0]`，则`cands[1]`对应的`cnts[1]`的值不变化。
投给`cands[1]`也是同样的道理。这样就转化成摩尔投票法的原始情形了。
第二阶段计数时，除了要判断两个候选的票数是否超过三分之一，还需判断两个候选是否相同。
```cpp
/*
时间复杂度为：O(n)
空间复杂度为：O(1)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        vector<int>res, cands, cnts;
        if(len == 0){//没有元素，直接返回空数组
            return res;
        }
        cands.assign(2, nums[0]);
        cnts.assign(2, 0);
        //第1阶段 成对抵销
        for(auto num: nums){
            bool flag = false;
            for(int i = 0; i < cands.size(); ++i){
                if(num == cands[i]){
                    ++cnts[i];
                    flag = true;
                    break;
                }
            }
            if(!flag){
                bool flag2 = false;
                for(int j = 0; j < cands.size(); ++j){
                    if(cnts[j] == 0){
                        flag2 = true;
                        cands[j] = num;
                        cnts[j]++;
                    }
                }
                if(!flag2){
                    for(int j = 0; j < cnts.size(); ++j){
                        --cnts[j];
                    }
                }
            }
        }

        //第2阶段 计数 数目要超过三分之一
        cnts[0] = cnts[1] = 0;
        if(cands[0] == cands[1])
            cands.pop_back();
        for(auto num:nums){
            for(int i = 0; i < cands.size(); ++i){
                if(cands[i] == num){
                    ++cnts[i];
                    break;
                }
            }
        }
        for(int i = 0; i < cands.size(); ++i){
            if(cnts[i] > len / 3){
                res.push_back(cands[i]);
            }
        }
        return res;
    }
};
```

3. 至多选出m个代表，每个选票数大于n / (m + 1)

只需要将题2的判断最后候选是否相同代码进行修改即可。

**欢迎访问[个人博客](www.onwaier.com)**