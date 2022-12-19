&emsp;&emsp;常规的思路解决这个问题，不要想太复杂，题目的意思就是从数组中查找两个数字，使得它们相加的和等于目标数字。  
&emsp;&emsp;幸好数组已经是有序的了，不然还得排个序，果然有序数组对数组内找元素有很大的好处，这将会是以后遇到这样的问题的一个思路。

#### 思路一：双指针做法
前后双指针分别指向数组的首尾，如果首尾元素相加大于目标，则尾指针向前一位；反之，如果首尾元素相加小于目标，则首指针向后一位。最差情况下，整个数组也只会遍历一遍，所以时间复杂度为O(N)。
#### 思路二：双指针+二分搜索
回顾思路一，当前指针指向某个元素时，后指针向前移动，实际上是为了找到某个元素，使得两者之和刚好大于等于目标。既然是在有序数组内查找某个元素，那就可以考虑采用二分查找的办法，直接将尾指针定位到相应元素。想法是丰满的，现实是骨感的，最坏情况下时间复杂度会达到O(NlogN)，还不如前面的做法呢。
#### 思路三：双指针+首尾都用二分
综合前面两个思路，当我定位了首指针的时候，采用二分查找的方式定位了尾指针；同时，在定位了尾指针之后，同样也可以通过二分查找的方式定位首指针。于是，就有了思路三的解法。有了思路二更差的复杂度之后，我已经不会计算这个的复杂度了，感觉应该还是没有解法一好。所以，该解法仅供参考。哪位帮忙算一下该解法的时间复杂度。


```双指针 []
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> vecAns;
		for (int l = 0, r = numbers.size() - 1; l < r;) {
			if (numbers[l] + numbers[r] == target) {
				vecAns.push_back(l + 1);
				vecAns.push_back(r + 1);
				break;
			} else if (numbers[l] + numbers[r] < target) {
				++l;
			} else {
				--r;
			}
		}
		return vecAns;
	}
};
```
```双指针加二分 []
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> vecAns;
		vector<int>::iterator it = numbers.begin();
		vector<int>::iterator itEnd = numbers.end();
		for (; it != itEnd; ++it) {
			vector<int>::iterator itFind = std::lower_bound(it + 1, itEnd, target - (*it));
			if (itFind != numbers.end() && (*it) + (*itFind) == target) {
				vecAns.push_back(std::distance(numbers.begin(), it) + 1);
				vecAns.push_back(std::distance(numbers.begin(), itFind) + 1);
				break;
			} else {
				itEnd = itFind;
			}
		}
		return vecAns;
	}
};
```
```双指针加首尾都用二分 []
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> vecAns;
		vector<int>::iterator itLeft = numbers.begin();
		vector<int>::iterator itRight = numbers.end();
		vector<int>::iterator itFind;
		while (itLeft != itRight) {
			itFind = std::lower_bound(itLeft + 1, itRight, target - (*itLeft));
			if (itFind != numbers.end() && (*itLeft) + (*itFind) == target) {
				vecAns.push_back(std::distance(numbers.begin(), itLeft) + 1);
				vecAns.push_back(std::distance(numbers.begin(), itFind) + 1);
				break;
			}

			itRight = itFind;
			itFind = std::lower_bound(itLeft + 1, itRight, target - (*(itRight - 1)));
			if (itFind != numbers.end() && (*itFind) + (*(itRight - 1)) == target) {
				vecAns.push_back(std::distance(numbers.begin(), itFind) + 1);
				vecAns.push_back(std::distance(numbers.begin(), itRight));
				break;
			}

			itLeft = itFind;
		}

		return vecAns;
	}
};
```
我果真不适合写题解，写文章啊！