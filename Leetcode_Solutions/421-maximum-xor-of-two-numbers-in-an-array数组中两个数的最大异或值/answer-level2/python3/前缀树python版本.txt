1、遍历数组，将数字解析为二进制，从高位到低位构建前缀树
2、再次遍历数组，使每个元素延前缀树找到异或最大值，规则如果当前位为1找0分支，如果为0找1分支，保证每个位置异或后的结果最大
3、比较当前最大值与存储的最大值，如果大于替换最大值

因为使用32位int作为构建前缀树，所以树最长为32,时间复杂度为O(2 * 32 * N)，遍历了2次数组

代码如下：

    class FindMaximumXOR(object):
        """
        给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231 。

        找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。

        你能在O(n)的时间解决这个问题吗？
        """

        def findMaximumXOR(self, nums: List[int]) -> int:
            # 第一步将数据插入到前缀树
            trie = Trie()
            for num in nums:
                trie.insert(num)

            max_val = float('-inf')
            # 遍历所有数据在前缀树中寻找对应的异或最大值
            for num in nums:
                value = trie.search(num)
                max_val = max(value, max_val)
            return max_val


    class Trie(object):

        def __init__(self):
            self.root = TreeNode()

        def insert(self, num: int) -> None:
            # 从高位开始插入
            cur = self.root
            for i in range(31, -1, -1):
                is_one = (num >> i) & 1

                # 高位为1的情况
                if is_one:
                    if cur.one is None:
                        cur.one = TreeNode()
                    cur = cur.one
                else:
                    if cur.zero is None:
                        cur.zero = TreeNode()
                    cur = cur.zero

        def search(self, num: int) -> int:
            cur = self.root
            # 从高位开始检测到低位
            res = 0
            for i in range(31, -1, -1):
                # 当前位是否为1
                is_one = (num >> i) & 1
                if is_one:
                    if cur.zero is not None:
                        # 为1找位为0的，切换到该分支，异或操作，1 ^ 0 = 1，能使结果最大
                        cur = cur.zero
                        res += 1 << i
                    else:
                        # 因为都有32位，所有不用判断one、zero都为空的情况
                        # 没有0的情况，只能切换到1，切换后值为0不用计算
                        cur = cur.one
                else:
                    if cur.one is not None:
                        # 为0找位为1的，切换到该分支，异或操作，1 ^ 0 = 1，能使结果最大
                        cur = cur.one
                        res += 1 << i
                    else:
                        # 因为都有32位，所有不用判断one、zero都为空的情况
                        # 没有1的情况，只能切换到0，切换后值为0不用计算
                        cur = cur.zero
            return res


    class TreeNode(object):

        def __init__(self):
            self.zero = None
            self.one = None 
    
