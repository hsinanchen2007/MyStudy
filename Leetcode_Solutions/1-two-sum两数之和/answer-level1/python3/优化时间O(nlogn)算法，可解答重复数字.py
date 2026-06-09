思路：
通过把数组排序，可以用贪婪算法解决此题。
1. 创建字典，遍历nums，把nums里所有的数字作为key存到字典里，value是其对应的index(value也是list形式)
- 时间复杂度是O(n)
2. 把nums排序
- 时间复杂度是O(nlogn)
3. 通过贪婪算法把nums首尾数字相加，和target比较：
- 如果大于target，把末尾index减一
- 如果小于target，把首部index加一
- 如果等于target，在原来字典里查找这两个数字对应原有的index。如果index相同，那么说明这个数字出现了多次，那么返回字典里value(是个list)的下一个元素
- 时间复杂度是O(n)

综上，时间复杂度是O(nlogn)，具体算法如下
class Solution(object):
    def twoSum(self,nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        start = 0
        end = len(nums) - 1
        dict = {}
        for i in range(end+1):
            numberToBeAdded = nums[i]
            if dict.get(numberToBeAdded):
                newArr = dict[numberToBeAdded]
                newArr.append(i)
                dict[numberToBeAdded] = newArr
            else:
                dict[numberToBeAdded] = [i]

        nums.sort()

        while True:
            currVal = nums[start] + nums[end]

            if currVal == target:
                start_index = dict[nums[start]][0]
                end_index = dict[nums[end]][0]
                
                if end_index == start_index:
                    end_index = dict[nums[end]][1]
                return [start_index,end_index]
            elif currVal > target:
                end -= 1
            elif currVal < target:
                start += 1