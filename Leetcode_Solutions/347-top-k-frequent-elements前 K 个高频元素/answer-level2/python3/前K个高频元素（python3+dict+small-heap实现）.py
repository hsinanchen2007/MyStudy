小白第一次写题解，还请各位大神们不吝赐教。算法没有调用python的heapq和collection库

#正文：本题感觉是topK类的问题的一个小变种。topk问题是为了解决在一个大的数据集合里寻找topk个最大/最小的子集合。通常可以采用快速排序的partition和堆来解决，各自的时间复杂度为O(N)和O(NlogK)。这题我采用的构建小顶堆的方法。

# 思路：
# 1》先用hashmap建立数组中的数字和其出现频次的映射，在python里面就是用dict字典结构。
# 2》然后根据给出的参数topk，从得到发哈希表中选取前topk元素，建立一个一个大小为topk的小顶堆。
# 3》然后遍历hashmap中剩余len(hashmap)-topk个元素，与小顶堆的第一个元素进行比较（频次之间的比较），如果前者大于小顶堆的第一个元素，则将这两个元素进行交换，交换之后需要维护这个**小顶堆**。
# 4》最后按顺序依次打印出topk大小顶堆中的元素（打印数字，不是频次）

时间复杂度为O(NlogK)
具体的细节看代码
```
class Solution_3:
    def topKFrequent(self, nums, k):
        """要求：使用时间复杂度小于O(nlogn)的方法来解题， 所以不考虑用排序的方式来解决"""
        if len(nums) == 1:
            return nums
        
        # 构建hashmap
        hashmap = dict()
        for item in nums:
            hashmap[item] = 1 + hashmap.get(item, 0)

        # 获取hashmap的长度信息，用于后面的遍历
        length_hash = len(hashmap)

        # 将hashmap列表化（形式为[(数字，频次),(数字， 频次), …]）
        hash_array = list(hashmap.items())
        # 获取hash_array中的前k个元素，作为小顶堆。
        map_array = hash_array[:k]

        # 构建小顶堆
        for i in range((k - 1)//2, -1, -1): 
            self.heap_create_adjust(map_array, i, k)

        # 遍历从第K个到hash_array列表末尾的元素
        for j in range(k, length_hash):
            if hash_array[j][1] > map_array[0][1]: # 比较频次的大小
                hash_array[j], map_array[0] = map_array[0], hash_array[j]
                self.heap_create_adjust(map_array, 0, k)  # 维护交换元素之后top_k小顶堆
        return [map_array[key][0] for key in range(k)]  # 返回结果，返回的是数字，而不是频次

    def heap_create_adjust(self, nums, node, length):
        # 这个函数既可以构建小顶堆，又可以维护小顶堆
        # nums 是数据格式[(数字，频次),(数字， 频次), …]
        if len(nums) == 1:
            return
        temp = nums[node]  
        j = 1 + 2 * node   
        while j < length:
            if j < length-1 and nums[j][1] > nums[j+1][1]:
                j += 1
            if nums[j][1] > temp[1]:
                break
            nums[node] = nums[j]
            node = j
            j = 1 + j*2
        nums[node] = temp
```

# 第二种方法是使用快速排序里面的partition函数来功能来解答：
# 在快速排序中，有一个partition的分割部分，分割得到的结果是在pivot元素一边的元素全部比pivot大，
# 另一边的元素全部比pivot元素小，partition函数返回的是pivot元素的位置索引-index。那么可以使用这个pivot元素的index来判断，当index=k-1（index从0开始）, 即前面的k个数据就是topK（大/小）当index < k-1的时候，继续划分，划分的起点为low=index+1， 终点为high； 当index>k时， 划分的起点为low， 终点为index-1。直到index=k为止
#算法的时间复杂度为O(logN)
所以算法如下：
```
 def partition(self, nums, low, high):
        # partition部分，和快排里面的partition一样
        pivot = nums[low]
        while low < high:
            while low < high and nums[high][1] <= pivot[1]:
                high -= 1
            nums[low], nums[high] = nums[high], nums[low]
            while low < high and nums[low][1] >= pivot[1]:
                low += 1
            nums[low], nums[high] = nums[high], nums[low]
        return low

def topKFrequent_1(self, nums, k):
        hashmap = dict()
        # build hash map
        for item in nums:  
            hashmap[item] = 1 + hashmap.get(item, 0)

        low = 0
        high = len(hashmap) - 1
        hash_array = list(hashmap.items())
        index = self.partition(hash_array, low, high)  # 获得一个划分
        while index != k - 1:  # 当index=k - 1时，说明前面的数字就是topk的内容了
            if k > index:  # 如果k > index, 向右扩大范围继续搜， low=index + 1
                low = index + 1
            else:  # 如果topk < index， 向左缩小范围， high = index -1
                high = index - 1
            index = self.partition(hash_array, low, high)

        return [hash_array[k][0] for k in range(k)]
```

   
