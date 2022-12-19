

### 更新思路
这道题主要是要找到**最短**无序的子数组，那么在考虑起点的时候一定要考虑到如下这种情况：
我们找到最小的点是为了找到最短子数组的起点：如果之后有个下降点比第一个点大，那么第一个即为起点（图一），但是如果下降的点最小的那一个都比第一个点大，那么我们并没有必要从第一个点开始算作无序，那么就得遍历数组，找到第一个比最小点大的元素，即为起点（图二）
但是我们不能找整个数组的最小点，而必须要找降序开始之后的最小点，因为有可能出现`[1,2,3,4]`这样的序列，我们首先得找到降序
![image.png](https://pic.leetcode-cn.com/8b8650b3d8edb3f0ba2e76f125f0884398ae0afa4c53423df08983167aa2c3c8-image.png)

同理，我们也要这样找到逆序时升序的最大点
![image.png](https://pic.leetcode-cn.com/c3802d288ab05dcb4aa6b281c2dfdd4e507d9f65926e4d284a372fbd5b77f7a9-image.png)



## 分割线
这个题我拿到简直是经历了很多次的“解答错误”，主要是没有考虑重复数字的情况，思路不正确写太多if else也没用，看了官方题解的第五种解法（这是我初始考虑的思路很相似，但是我考虑太少了）但是并没有看太懂，捋了好久才捋清楚


### 1.双指针，四次循环找到边界

只要数组开始降序，那么我就去找到降序后的最小值，因为这个是一个最小边界，在这之前，只要有一个比这个最小值大的元素，就说明乱序了需要从这第一个比min大的元素开始去逆序，如第二个图，为什么min是4而不是2，因为2是处在一个升序的状态【2,6】，说明如果后面没有比6小的数，那肯定就是正确的顺序状态，那如果有比6小的数，说明就出现了乱序，但是我乱序的一个边界是什么呢，就是所有降序中的最小值，这个值代表了一个最低边界，所以条件是**顺序遍历只要有降序，那就去更新降序中的最小值，遍历数组记录最后的最小值**

同理，我们逆序考虑，逆序其实应该是一个降序的过程（正确情况下），那么我们就去找，如果逆序有了升序，就说明有乱序，那么这个最大边界是多少呢，就是每一个升序的最大值，比如逆序【9，15】逆向没有升序，不考虑，【10,9】逆向升序，那说明有了乱序，所有升序中的最大值，代表了最高的边界，所以条件是**逆序遍历只要有升序，那就去更新升序中的最大值，遍历数组记录最后的最大值**

![image.png](https://pic.leetcode-cn.com/c540f8d9882b740d91d12963d7685e7b87c7e8aec10ecda739373a3e359a1bdc-image.png)
![image.png](https://pic.leetcode-cn.com/46cc92eb6f8f45c1e1bde35d52557a9a60e42672f699d2dd6474fc8044801279-image.png)

拿到了最低边界和最高边界之后，那么我们就要考虑，这是一个结果想要升序的数组，那么应该从小到大的顺序，**那么顺序遍历，第一个比最小边界大的值就应该是乱序的起点，逆序遍历的时候，第一个比最大边界小的值就应该是乱序的终点**
因为左边的值都应该比最小边界小，右边的值都应该比最大边界大

![image.png](https://pic.leetcode-cn.com/4dacfa0335c92db8a8be17e236793155925b9909c2aff7af7cb9b632345505c9-image.png)

于是这样就可以写出四层遍历的代码：

```
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        
        min_n = max(nums)
        max_n = min(nums)

        '''找到顺序数组第一次降序之后的最小值'''
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                min_n = min(nums[i], min_n)

        '''找到逆序数组第一次升序之后的最大值'''
        for i in range(len(nums)-2, -1, -1):
            if nums[i] > nums[i+1]:
                max_n = max(nums[i], max_n)

        low = 0
        high = len(nums)-1

        '''顺序找到第一个比min_n大的数，代表从这里开始乱序需要排序'''
        while low <= len(nums) - 1:
            if nums[low] > min_n:
                break
            low += 1

        '''逆序找到第一个比max_n小的数，代表从这里开始乱序需要排序'''
        while high >= 0:
            if nums[high] < max_n:
                break
            high -= 1

        # 有可能是一个不需要排序的数组
        return max(high - low + 1, 0)
```
![image.png](https://pic.leetcode-cn.com/c1ecc279f7f6283236e8c563c9941018a4576cfb4b24a905c1a4dc5c647e5e3b-image.png)



### 2.考虑排序：因为要让这个数组变成一个排序数组，可以考虑能不能先排序再判断

然后看到题解说先排序，然后去找到左边第一个与原数组不一致的元素的index，和从右边去找到第一个和原数组不一致的元素的index，这就是需要调整顺序的范围

【！！！我为什么就没有想到！！！弱鸡的泪水滴滴答答。。。还是要多写题才会有意识。。】

这样就很简单的能够找到边界，只是需要一个额外的空间来存储数组，并且排序的时间复杂度其实也比较高，但是没想到提交之后的时间还挺快的。。。比我四次循环的O(n)时间复杂度的上一个办法要快很多。。天意吧

```
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = sorted(nums)
        
        low = 0
        
        while low <= len(nums)-1:
            if nums[low] != n[low]:
                break
            low += 1
            
        
        high = len(nums)-1
        while high >= 0:
            if nums[high] != n[high]:
                break
            high -= 1
            
        return max(high-low+1, 0)
```

【生活艰难，还需要等一周。。希望能得偿所愿，plz】

![image.png](https://pic.leetcode-cn.com/737196895a85d5957183034cf49a310e3cbd87fe1eb736a0f9fed7d2feb5f4da-image.png)
