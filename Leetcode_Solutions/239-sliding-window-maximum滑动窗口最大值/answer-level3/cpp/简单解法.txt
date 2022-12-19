提交结果：
![图片.png](https://pic.leetcode-cn.com/811c22f75b3cc5e08f66c2936b757ffdb184f3e586e27e6ccc9124ef8e1e1f43-%E5%9B%BE%E7%89%87.png)

思路简述：
一开始选用的解法是纯粹使用C++里面的双端队列容器deque来按照题意编写代码。提交之后发现，这种解法速度很慢，且内存占用很高。于是抛弃这种解法，转而使用移动的下标，构造窗口的两端。具体代码分解见代码。
代码：
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 输入无效情况下。
        if (!nums.size() || k < 0)
		return vector<int>(0);

		// k==1 时。返回原vector
		if (k == 1)
		{
			return nums;
		}
		// k==nums.size()时,返回整个vector的最大值。
		if (k == nums.size())
		{
            //这里直接使用STL中的算法:max_element来获取原vector中最大值的迭代器。
			auto res = std::max_element(nums.begin(), nums.end());
            // 根据获取到的最大值，返回一个vector。
			return vector<int>(1, *res);
		}
        //其他情况
		vector<int> result;
        // delta用于记录每次j的步进值。
		int delta = k - 1;
        //tag用于记录当前窗口最大值的下标。
		int tag = 0;
        //开始循环，循环size()-k+1次。（假如size == 8,k == 3,那么会有6个最大值，所以应该循环6次）
		for (int i = 0; i <= nums.size() - k; i++)
		{
            //每次循环，都用j来获取右界下标。i则是左界下标。
			int j = i + delta;
			//刚开始进入循环时，i==0。
            //先找到第一个窗口的最大值及其下标，使用tag记录。
            //每次i>tag时，说明由tag标注之前的窗口的最大值已经在窗口之外了
            //所以需要重新调用下面的循环来重新获取当前的窗口的最大值及下标，仍由tag来记录下标。
			if (!i||i>tag)
			{
				for (int ite = i+1,k = i; ite <= j; ite++)
				{
					if (nums[ite] > nums[k])
					{
						k = ite;
					}
					tag = k;
				}
				// 找到第一次/后面的不知道第几次的最大值的下标，记录为tag。
                //记录最大值
				result.push_back(nums[tag]);
				continue;// 结束后面的循环，直接进入下一个比较。
			}
			// 后面的处理步骤
			// 未越界————i<=tag，即说明当前最大值还在窗口之中
            // 在这种情况下，只需要每次比较右界的新值（j标志其下标）和旧有最大值即可。
			if (i<=tag)
			{
				// 新来的小于老大（旧有新值）
				if (nums[j] < nums[tag])
				{
					result.push_back(nums[tag]);//老大再进去
					continue;
				}
				// 新来的大于老大
				else
				{
					result.push_back(nums[j]);
					//重置tag
                    //tag从始至终，都是记录最大值的下标的。
					tag = j;
				}

			}
			
		}
        //最后返回结果vector。
		return result;
    }
};
```

