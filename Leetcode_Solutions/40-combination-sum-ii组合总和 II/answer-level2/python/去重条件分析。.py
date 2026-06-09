写完之后，看答案发现了更简单的方法，直接改一下三数之和部分去重的判断条件就可以了，我这个方法反而想复杂了。
不过还是不删了，留在这当个记录吧。

只是当做笔记记录一下细节部分思考的心得。可能有写的不准确的地方，欢迎批评指正~

**这题的一个难点是如何去重**
在[三数之和](https://leetcode-cn.com/problems/3sum-closest/solution/fen-xi-yi-xia-yao-bu-yao-xiang-san-shu-zhi-he-na-d/)那道题中，去重是通过在for循环之后加上判断，是否当前与上一个相同，如果相同，则pass
for i in range(length-3):            
            if i>0 and nums[i]==nums[i-1]: continue    
            ……

对于本题
如果输入是： 1 1 2 3 
按照排序之后搜索的思路，第二个1会被遍历两次：
第一次被遍历是： 以第一个1作为根节点，第二个1是中间节点；
第二次被遍历是： 以第二个1为根节点，2、3为后续搜索节点。
详细如图：
![image.png](https://pic.leetcode-cn.com/7577b83e99ee6ae19d86b6cbd1f66e907531e38941ae8ac28c77d4db2b9de262-image.png)

如果像在三数之和问题一样，简单的用nums[i]==nums[i-1]来去重，由于这里的实现使用的是对同一个函数的递归，所以两次遍历都会运行到同一个判断语句，导致两次遍历都被pass,也就是说，第一次遍历也被pass了,而这必然会导致漏解。（至于为什么一定要保留重复数中第一个出现的数的搜索过程，pass后面重复数的搜索过程，可以看我在三数之和问题中对去重的分析。[点这里](https://leetcode-cn.com/problems/3sum-closest/solution/fen-xi-yi-xia-yao-bu-yao-xiang-san-shu-zhi-he-na-d/)）

而在三数之和中，因为是用的for循环实现，所以只有第二个1作为根节点时的那次遍历，才会遇到去重的判断语句。详细的可以看三数之和的代码。 

所以在这里简单的复制三数之和的去重方法是不行的。
那么问题出在哪呢？
问题出在我们没有把这两次遍历区分开来。
那么怎么才能把这两次遍历区分开来，只对第二次遍历去重呢？
再仔细思考一下，我们会发现这两次遍历最大的不同之处在于，在两次遍历中，第二个1的父节点是不一样的。
第一次遍历，其父节点是第一个1。
第二次遍历，其父节点是第一个1的父节点。（因为第二次遍历，两个1是在树的同一层的。）
所以我们只要在递归的时候传递一个父节点的信息（father），在去重时加一个判断条件，
即若father==index-1,则说明是第一次遍历，不pass。
如果father！= index-1,说明是在同一层，pass。

代码细节：
注意初始值的设置
为什么要排序？ 
    排序是为了剪枝效率更高，去重更方便
去重是怎么实现的？ 
    有两个地方是为了去重：
    1.每次不从头搜索，而是按顺序往后搜索；（这是为了去掉重复遍历带来的组合重复）
    2.上面讨论的去重判断条件；（这是为了去掉相同数字带来的组合重复）
```
class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        length = len(candidates)
        

        candidates = sorted(candidates)       

        def help(path,sum,cur,father):
            if cur>0 and candidates[cur]==candidates[cur-1] and cur-1!=father: return
            if sum==target:
                ans.append(path)
            if sum<target:
                #向后搜索 
                for i in range(cur+1,length):
                                       
                    temp = sum+candidates[i]
                    if temp>target: return #break
                    else:
                        father = cur
                        help(path+[candidates[i]],temp,i,father) 

        ans = []
        #cur的意义是指向下一次要遍历的数字的前一个索引
        #而在第一层的时候，我们需要遍历数组里所有的数
        #所以cur的初始值应该设置为-1
        help([],0,-1,-1)
        return ans
```
