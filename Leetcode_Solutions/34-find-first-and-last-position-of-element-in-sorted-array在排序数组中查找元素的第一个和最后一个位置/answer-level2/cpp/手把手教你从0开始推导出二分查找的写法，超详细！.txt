# 手把手教你从0开始推导出二分查找的写法，超详细！

几乎所有讲二分查找的文章，都会引用Knuth这样的一句话

	Although the basic idea of binary search is comparatively straightforward, 
	the details can be surprisingly tricky..
	
通俗简单的翻译一下就是 **思路很简单，细节是魔鬼** 。相信很多人都被二分查找里要不要加等号搞的头晕眼花。
看了正确答案后又恍然大悟，到了下次做题却又忘掉了某处细节而陷入泥潭···

这篇文章的目的就是带你彻底搞懂二分查找的 **代码** 里的原理是如何来的(不是二分查找自身的原理)，而不再是局限是对二分查找死记硬背。
只要搞懂了原理，再写二分查找自然便是手到擒来。

> ### 0.一些基本参数的含义

* left 左边界
* right 右边界
* mid 当前检查点

>### 1.二分查找最最最最基本的模板

	int binary_search(vector<int> nums,int target){
		if(nums.size()==0) return -1;
		int left=?,right=?;
		while(left??right){
			int mid=(left+right+??)/2;
			if(nums[mid]==target){
				?????;
			}else if(nums[mid]<target){
				left=mid+?;
			}else if(nums[mid]>target){
				right=mid+?;
			}
		}
		return ?;
	}
	
在上面的模板中，两处`??`是可以改变的，而他们的改变便会影响到`?`该填的内容。
空缺的`?????`则和我们使用二分查找要解决的问题有关。

> ### 2.二分查找能解决的三种问题

学过二分查找的人都知道，二分查找是用来找某个数在有序数组中的位置的。这是二分查找能够解决的最基本的问题。

但是，如果要查找的那个数在这个数组中可能不止一个而是多个呢？这个时候的要求可能就不是随便找一个就了事了，
而是要你来找出这个数字所在位置比较特殊的两个————最左边的和最右边的，也就是寻找左边界和右边界。
这两种问题只需要在第一种问题的基础上做少许改动便可以用二分查找来解决。

> ### 3.假如有一名小白···

对于一名刚刚了解了二分查找算法，想要把它转换为代码的小白，我相信他肯定会一边感叹二分查找算法的简单，
一边自信的写出下面的片段

	if(nums[mid]<target){
		left=mid;
	}else if(nums[mid]>target){
		right=mid;
	}

但他写好代码，自信的点下运行。或许有的情况可以给出正确的答案，但可能更多的是莫名其妙的死循环。

然后他眉头一皱，改了改代码，运行，错误，然后抓耳挠腮，再改······

到底发生了什么让我们的小白写不出明明很简单的二分查找呢。我们先来看看上面模板中`??`的部分。

> ### 3.mid=(left+right)/2和mid=(left+right+1)/2

由简单的算术知识我们可以知道，在`left+right`为偶数时，这两个算式得到的结果是一样的。
而在`left+right`是奇数时，前者是向下取整，后者是向上取整。

在这里我们要了解一个基本事实：无论是用哪个算式，在二分查找中，除了只有一个数和提前return命中的情况(只有第一种问题的情况才能提前命中)，不断使用二分查找
必然会到`left=n,right=n+1`的情况。可以自己在纸上写一写试一试。在后面我们会把这种情况写作`n\n+1` 。

那么也就是说：在使用`mid=(left+right)/2`时算到了`left=n,right=n+1`,此时`mid=(n+n)/2=n`,如果下一步是`left=mid`,
我们就会发现我们不幸的陷入了死循环。

而在`mid=(left+right+1)/2`时算到了`left=n,right=n+1`,此时`mid=(n+n+1)/2=n+1`,如果下一步是`right=mid`,
我们也会不幸的陷入死循环。

> ### 4.while(left<right)和while(left<=right)

如果你侥幸的逃脱了上面陷阱，来到了`left==right`的情况。要是你在之前足够幸运，选择了前一种判断条件，那么恭喜你，起码你不会被困在死循环了。

就算你选择了后一种，如果之前选择是`mid=(left+right+1)/2`，那么只要再运算你依然可以摆脱这该死的循环。

但是···如果你偏偏做了最差的选择，那又是无穷无尽的死循环···

while循环中的内容还有个重要的作用，那就是它确定了我们循环停止的条件。对于`while(left<right)`，退出循环时我们有`left==right` ，
而对于`while(left<=right)`,退出循环时我们有`left-1=right`。这里必须要切记，这对我们后面的分析很有用。

> ### 5.解决死循环

我们相信多一事不如少一事，所以我们选择形式相比来说最简单的`mid=(left+right)/2`和`while(left<right)`搭配，解决最简单的第一个问题。

如果提前命中返回的情况没什么好说了，我们现在关注的情况应该是必须到到最后才能得到答案的情况，也就是说我们将要面对`n/n+1`这个该死的情况。

怎么解决呢？最后，我们把目光放到了这段代码上

	if(nums[mid]<target){
		left=mid;
	}else if(nums[mid]>target){
		right=mid;
	}

我们不是可能会卡在`left=mid`这段代码上吗？那么我们写成`left=mid+1`呗。

于是我们得到了下面这段代码(假设我们要找的数一定存在)

	int binary_search(vector<int> nums,int target){
		if(nums.size()==0) return -1;
		int left=0,right=nums.size()-1;
		while(left<right){
			int mid=(left+right)/2;
			if(nums[mid]==target){
				return mid;
			}else if(nums[mid]<target){
				left=mid+1;
			}else if(nums[mid]>target){
				right=mid;
			}
		}
		return left;
	}

再运行，好像就行了。但是它没有办法处理寻找的数不存在的情况。但解决方法也很简单，在最后再多加一个判断，判断nums[right]是不是我们要找的数就行了。

现在我们来解决寻找左边界的问题。

寻找左边界，意味着我们要把右边这样的数视为"不是这个数"。所以命中这个数后我们不能立即返回，那么我们该干什么呢？
命中时左边界应该是在左边或者是本身，所以我们就可以让右界的right等于这个位置来继续寻找。也就是：

	if(nums[mid]==target){
		right=mid;
	}
	
得到代码：

	int binary_search(vector<int> nums,int target){
		if(nums.size()==0) return -1;
		int left=0,right=nums.size()-1;
		while(left<right){
			int mid=(left+right)/2;
			if(nums[mid]==target){
				right=mid;
			}else if(nums[mid]<target){
				left=mid+1;
			}else if(nums[mid]>target){
				right=mid;
			}
		}
		return left;
	}
	
这段代码也是可行的，我们似乎势如破竹，一下子就来到了最后一个问题，寻找右边界。
按照上面的思路对代码做一些小小的修改，把`right=mid`替换为`left=mid+1`,攻破二分查找似乎近在眼前。

但是一个问题的出现阻止了我们前进的脚步：如果mid直接命中右边界，我们却不幸的执行了`left=mid+1`,直接把右边界跳了过去。

前面的代码为什么没有出现这样的问题？因为寻找的是左边界，而相等时移动的是右界right，小于target时移动的是左界left，所以左边界肯定逃不出我们的手掌心。

冷静下来仔细思考后，我们发现有挽回的余地：left最多只能到右边界再右边一个，再仔细思考我们会意识到，left肯定会到右边界的右边一个。

因为left到了由和target相等的数组成的"平台"后，会在这个平台上逐渐(当然也可能马上)滑到最右边。但不可能没有到平台最右边就直接出平台，因为平台右边的数都是大于target的。

mid到了右边界后，执行left+1，到了右边界下一个。有了这个强有力的结论，我们只需要把返回条件改成 `return left-1`就可以了。

问题解决了吗？大多数情况下是的。但是，右边界是数组里的最后一个数呢？我们的left能到达数组里最后一个数，然后在`return left-1`中遗憾的错失了右边界。
这或许是爱情故事的好题材，但我们显然不想让代码中有这样的悲剧。

怎么办呢？思考后我们会发现right是我们的悲剧的罪魁祸首：因为right的限制，让left不能到右边界的下一个。那么我们就直接解决它，让right的初值多1 ，取到nums.size()。

得到代码

	int binary_search(vector<int> nums,int target){
		if(nums.size()==0) return -1;
		int left=0,right=nums.size();
		while(left<right){
			int mid=(left+right)/2;
			if(nums[mid]==target){
				left=mid+1;
			}else if(nums[mid]<target){
				left=mid+1;
			}else if(nums[mid]>target){
				right=mid;
			}
		}
		return left-1;
	}

为什么把right的初值赋到数组之外却不会出现错误呢？我们之前提前，结束循环时`left==right`，也就是说我们可以把return的内容写成`return right-1`，就算right没有向左移动，也不会返回它出界的原值。

我们写出了三种情况对应的解法了。这时我们来总结一下经验：

* 如果出现死循环，我们就把被卡的left或right在循环内的移动加1或减1，即把 "left=mid"改为"left=mid+1"或把"right=mid"改为"right=mid-1"
* 如果是要找边界，把nums[mid]==target里面的内容改变一下
* 如果遇到了把边界排除掉了的情况，只需要在return处处理一下
* 如果因为数组边界而酿成悲剧，就把初始的左界left或右界right扩大一些

按照这些经验，我们来试试`mid=(left+right+1)/2`和`while(left<right)`的组合

> ### 6.尝试新组合

现在试试第一种问题，单纯的寻找一个数。显然我们只需要考虑第一条经验。如何运用这条经验呢？我们只需直接考虑`n\n+1`的情况。

根据第3节的经验，我们可能会卡右界right，那么按照经验改，可以得到代码

	int binary_search(vector<int> nums,int target){
		if(nums.size()==0) return -1;
		int left=0,right=nums.size()-1;
		while(left<right){
			int mid=(left+right+1)/2;
			if(nums[mid]==target){
				return mid;
			}else if(nums[mid]<target){
				left=mid;
			}else if(nums[mid]>target){
				right=mid-1;
			}
		}
		return left;
	}

和前面一样，如果数字不在数组内我们需要多做一个if判断

再寻找左界。这时我们发现边界可能会被漏掉，同时利用3，4点经验改变一下代码，可以得到：

	int binary_search(vector<int> nums,int target){
		if(nums.size()==0) return -1;
		int left=-1,right=nums.size()-1;	//left边界修改
		while(left<right){
			int mid=(left+right+1)/2;
			if(nums[mid]==target){
				right=mid-1;
			}else if(nums[mid]<target){
				left=mid;
			}else if(nums[mid]>target){
				right=mid-1;
			}
		}
		return left+1;		//回到边界
	}
	
最后是右界。我们只需要第2点经验就可以了，代码：

	int binary_search(vector<int> nums,int target){
		if(nums.size()==0) return -1;
		int left=0,right=nums.size()-1;	
		while(left<right){
			int mid=(left+right+1)/2;
			if(nums[mid]==target){
				right=mid-1;
			}else if(nums[mid]<target){
				left=mid;
			}else if(nums[mid]>target){
				right=mid-1;
			}
		}
		return left;		
	}
	
依靠四点经验，我们很迅速的就完成了这种情况的写法！

> ### 7.更简便的寻找一个数

前面我们解决第一类问题，寻找一个数时都不得不在最后再加上一个判断才能避免target不在数组中的尴尬。
其原因在于`left==right`时已经结束了循环，没有对最后那个值做出判断。顺便提一句，后面的寻找边界的代码也没有处理这个问题。

那么有没有可以不用加判断的方法呢，当然，只要我们把while条件改为left<=right,两者相等时便会继续进入循环。

同样的，按照经验和第4节的分析，我们如果使用`mid=(left+right)/2`和`while(left<=right)`的组合。
左右界left和right都会被卡，所以我们把它们都处理一下，可以得到代码。

	int binary_search(vector<int> nums,int target){
		if(nums.size()==0) return -1;
		int left=0,right=nums.size()-1;
		while(left<=right){
			int mid=(left+right)/2;
			if(nums[mid]==target){
				return mid;
			}else if(nums[mid]<target){
				left=mid+1;
			}else if(nums[mid]>target){
				right=mid-1;
			}
		}
		return -1;
	}
	
这里的巧妙之处就在于循环会检查所有可能的数，而如果出了循环必然target在数组中不存在。

> ### 8.继续使用我们的经验

原本到此就应该结束了，剩下的情况相信大家都可以自行推导。但是因为前面还有一个易错点，所以我们对二分查找的攻克还没有结束。

继续考虑7中我们使用的组合。如果我们依靠这个组合来解决右边界呢。此时左右界left和right都做了改变，那么3,4点经验我们要怎么运用呢？

答案是不需要运用，因为此时最后根本就不会出界：left会滑到平台右侧，然后到右边界加1的位置，随后left肯定不会再有任何的移动，直到right等于left。
这时mid是大于target，我们直接返回right就可以了。

对于左边界也是如此，直接返回left。

这时候我们也注意到我们不能随便选择返回值了，因为left和right不再相等。

> ### 9.总结

现在我们回到那个最开始的最最最最基本的模板，相信现在我们已经对其中的`?`怎么取已经了解了。如果还不熟悉可以看看下面的总结

	int binary_search(vector<int> nums,int target){
		if(nums.size()==0) return -1;
		int left=?,right=?;		//经验4，如果因为数组边界限制需要扩大
		while(left??right){		//自选 "<"或"<="
			int mid=(left+right+??)/2;		//自选 取0或1
			if(nums[mid]==target){
				?????;				//经验2，根据是不是边界问题选择
			}else if(nums[mid]<target){
				left=mid+?;			//经验1，避免死循环
			}else if(nums[mid]>target){
				right=mid+?;		//经验1，避免死循环
			}
		}
		return ?;	//经验3，挽救我们失去的边界。如果while里是<=则需要注意返回的是哪一个
	}

> ### 10.换种思路思考

我们从细节推出了二分查找的写法，但我们能不能从整体来分析二分查找呢？也能！而且在掌握了整体的思维后你能对二分查找的了解更上一层。

我们可以把二分查找看作一个这样的过程：有一个集合区间，我们把区间不断缩小来寻找目标。

区间可能是全闭的，那么只要左右界相等即命中；可能是半开半闭的，左右边界相等时目标在加1或者减1的位置。

什么！目标值在加1或减1的位置，听起来好熟悉！这不就是经验3吗！为什么它会和经验3如此的相似？

为了找出原因，我们回顾一下要使用经验3的原因："为了避免死循环我们在经验1中做了多加1或多减1的操作"，以及使用它的后果："还要考虑经验4，把边界扩大"。

等等！敏感的你可能已经发现了他们的联系：经验4扩大单边区间，对应的是半开半闭区间，使用经验3是说明我们在进行这样的操作：
把闭区间向前推，因为检验过的值显然不是我们需要的答案，而开区间不需要。

而我们继续把目光放大可以发现：当我们取`while(left<right)`时意味着我们在使用一个半开半闭区间，而使用 `while(left<=right)`时意味着我们在使用一个全闭的区间。

这也可以很好的解释为什么第7节我们可以不用判断。毕竟一个闭区间的左右界都在同一个数，那么肯定就是了，如果他们左区间直接大于右区间了还没找到答案，那么说明目标不存在。

至于`mid=(left+right)/2`和`mid=(left+right+1)/2`?其实两个在宏观上并没有什么区别，我甚至觉得写二分查找改变不要考虑写成`mid=(left+right+1)`。

> ### 11.一个小细节

为什么最后才提这个细节，是因为这个细节在绝大多数的情况下不需要考虑(但是在LeedCode里你可能会经常碰到这个问题)，我经常觉得这种因为计算机或语言而造成错误破坏了算法的最纯洁的美感(其实是懒的改代码了hhh)。
我们如果数非常非常多，那么我们在第一次做`left+right`时可能会溢出，所以我们可以使用`left+(right-left)/2`来替代`(left+right)/2`。

> ### 12.最后

相信看到这里，就算是前文提到的小白也已经对二分查找了如指掌了。




