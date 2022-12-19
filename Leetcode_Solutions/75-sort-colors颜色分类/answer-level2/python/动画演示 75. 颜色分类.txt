# 计数+重写数组
我们定义三个变量a，b，c分别记录0，1，2出现的次数。然后遍历一次数组。    
之后再次遍历一遍数组，按照0出现的次数，1出现的次数，2出现的次数重写这个数组。重写完一遍后，整个数组就是有序的了。   
代码如下：   
```java []
class Solution {
	public void sortColors(int[] nums) {
		if(nums==null || nums.length==0) {
			return;
		}
		int zero = 0;
		int one = 0;
		int two = 0;
		int j = 0;
		//遍历一次数组，统计0,1,2出现的次数
		for(int i=0;i<nums.length;i++) {
			if(nums[i]==0) {
				++zero;
			} else if(nums[i]==1) {
				++one;
			} else {
				++two;
			}
		}
		//重写一遍数组，先写若干个0，再写若干个1，最后是若干个2
		//重写完之后，整个数组就是有序的了
		while(j<zero) {
			nums[j] = 0;
			++j;
		}
		while(j<zero+one) {
			nums[j] = 1;
			++j;
		}
		while(j<zero+one+two) {
			nums[j] = 2;
			++j;
		}
	}
}
```   
```python []
Solution(object):
	def sortColors(self, nums):
		"""
		:type nums: List[int]
		:rtype: None Do not return anything, modify nums in-place instead.
		"""
		if(not nums):
			return 
		zero = 0
		one = 0
		two = 0
		# 遍历一次数组，统计0,1,2出现的次数
		for i in nums:
			if( i==0 ):
				zero +=1
			elif( i==1 ):
				one += 1
			else:
				two += 1
		i = 0
		# 重写一遍数组，先写若干个0，再写若干个1，最后是若干个2
		# 重写完之后，整个数组就是有序的了
		while( i<zero ):
			nums[i] = 0
			i += 1
		while( i<one+zero ):
			nums[i] = 1
			i += 1
		while( i<two+one+zero ):
			nums[i] = 2
			i += 1
```
   
   
   
   
# 借助快速排序思想
快速排序的一个思想是在一个乱序的数组中，先确定一个**待分割的数字**记做x，之后将所有小于等于x的元素放到x的左边，所有大于x的元素放到x的右边，然后按照同样的逻辑递归处理数组的左半边，右半边。   
这里我们稍稍修改一下快速排序的思想，确定一个待分割的数字，这里待分割的数字很容易确定，就是0。   
我们用两个指针迭代遍历数组，j指针不断往前走，当j指针指向的元素==0的时候，就交换两个指针指向的元素   
    
![1.jpg](https://pic.leetcode-cn.com/ff3ee402862e5f2410f83050b4260557213c72e946c7ea5a89c25c5298838e4f-1.jpg)
等一遍遍历完之后，0这个元素就相对有序了    
![2.jpg](https://pic.leetcode-cn.com/339c3d1911822b539b8a72eb467ddac22714ee812b1c014a0a55f208045d9d4e-2.jpg)
按照同样的方式再判断nums[j]==1，第二次遍历后，1的元素也是相当有序了，这样整个数组就是有序状态了。   
![快速排序改变.gif](https://pic.leetcode-cn.com/4ff01311844f58b83124a449e24857e9d02fd6c04067e9551fda6bccbe59b87e-%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F%E6%94%B9%E5%8F%98.gif)

代码实现如下：   
```java []
class Solution {
	public void sortColors(int[] nums) {
		if(nums==null || nums.length==0) {
			return;
		}
		int i = 0;
		//第一次遍历数组，处理所有0元素，将他们放到合适的位置
		//j指针不断往前走，如果指向的的元素==0，就交换i，j指向的元素
		for(int j=0;j<nums.length;j++) {
			if(nums[j]==0) {
				swap(nums,i,j);
				++i;
			}
		}
		//这里有一个优化，j不用重头开始遍历了，第一次遍历完之后i前面的元素都已经排好序了
		//所以直接从i开始遍历就可以了
		for(int j=i;j<nums.length;j++){
			if(nums[j]==1) {
				swap(nums,i,j);
				++i;
			}
		}
	}
	
	void swap(int[] arr,int i,int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}
```
```python []
class Solution(object):
	def sortColors(self, nums):
		"""
		:type nums: List[int]
		:rtype: None Do not return anything, modify nums in-place instead.
		"""
		if not nums or len(nums)==0:
			return
		i = 0
		# 第一次遍历数组，处理所有0元素，将他们放到合适的位置
		# j指针不断往前走，如果指向的的元素==0，就交换i，j指向的元素
		for j in xrange(len(nums)):
			if nums[j]==0:
				nums[j],nums[i] = nums[i],nums[j]
				i += 1
		# 这里有一个优化，j不用重头开始遍历了，第一次遍历完之后i前面的元素都已经排好序了
		# 所以直接从i开始遍历就可以了
		for j in xrange(i,len(nums)):
			if nums[j]==1:
				nums[j],nums[i] = nums[i],nums[j]
				i += 1
```
   
   
   
   
## 荷兰国旗问题
这道题其实是一个经典的算法问题：**荷兰国旗问题**      
”荷兰国旗问题“是计算机科学中的一个程序难题，它是由Edsger Dijkstra提出的。荷兰国旗是由红、白、蓝三色组成的。   
![1572690923(1).jpg](https://pic.leetcode-cn.com/939eb7b1f543dc83df0784430b4aa3d40c52e91348baacdedb8c3ae6a6b9f332-1572690923\(1\).jpg)
现在有若干个红、白、蓝三种颜色的球随机排列成一条直线。现在我们的任务是把这些球按照红、白、蓝排序。   
当整个元素排好序的时候，数组是分成三部分的，左边一片区域是0，中间的区域是1，右边区域是2。      
快速排序改进方案的实现中，我们定义了两个变量，这里我们可以定义三个变量p0，cur，p2。      
 
![a.jpg](https://pic.leetcode-cn.com/862f5461550e92a4be5bdfe8d872147a7aa2ab3300344e0ef7316abd83ea4bcd-a.jpg)
p0的初始位置是0，在遍历的时候如果发现有元素==0，就把这个元素跟p0交换，于是0元素就被交换到左边了。   
p2的初始位置是数组最右边，也就是len(nums)-1的位置，如果发现有元素==2，就把这个元素跟p2交换，于是2元素就被交换到右边了。   
如果碰到元素1就不交换
![荷兰国旗-动态图.gif](https://pic.leetcode-cn.com/391d94d828bb6336c9a3fb2d59ae0c34791902a85577810480433b873869b5ea-%E8%8D%B7%E5%85%B0%E5%9B%BD%E6%97%97-%E5%8A%A8%E6%80%81%E5%9B%BE.gif)

代码实现：   
```java []
class Solution {
    public void sortColors(int[] nums) {
		if(nums==null || nums.length==0) {
			return;
		}
		//定义三个变量，p0表示数组最左边，0的区域，p2是数组最右边2的区域
		//cur就是当前遍历的指针
		int p0 = 0;
		int p2 = nums.length-1;
		int cur = 0;
		while(cur<=p2) {
			//如果当前指向的是0，就把这个元素交换到数组左边
			//也就是跟p0指针交换，之后cur，p0就往前一动一位
			if(nums[cur]==0) {
				swap(nums,cur,p0);
				++cur;
				++p0;
			//如果当前指向的是2，就把这个元素交换到数组右边
			//也就是跟p2指针交换，注意此时cur指针就不用移动了
			//因为右边的一片区域都是2，只要把元素交换过去就可以了，cur不用移动
			} else if(nums[cur]==2) {
				swap(nums,cur,p2);
				--p2;
			//如果是1的话，就不用交换	
			} else {
				++cur;
			}
		}
    }
	
	void swap(int[] arr,int i,int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}	
```   
```python []
class Solution(object):
	def sortColors(self, nums):
		"""
		:type nums: List[int]
		:rtype: None Do not return anything, modify nums in-place instead.
		"""
		if not nums or len(nums)==0:
			return
		# 定义三个变量，p0表示数组最左边，0的区域，p2是数组最右边2的区域
		p0,cur,p2 = 0,0,len(nums)-1
		while cur<=p2:
			# 如果当前指向的是0，就把这个元素交换到数组左边
			# 也就是跟p0指针交换，之后cur，p0就往前一动一位
			if nums[cur]==0:
				nums[cur],nums[p0] = nums[p0],nums[cur]
				p0 += 1
				cur += 1
			# 如果当前指向的是2，就把这个元素交换到数组右边
			# 也就是跟p2指针交换，注意此时cur指针就不用移动了
			# 因为右边的一片区域都是2，只要把元素交换过去就可以了，cur不用移动
			elif nums[cur]==2:
				nums[cur],nums[p2] = nums[p2],nums[cur]
				p2 -= 1
			# 如果是1的话，就不用交换	
			else:
				cur += 1
```
      
(全文完)     
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)