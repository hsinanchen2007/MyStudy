
>输入

matrix1 = [
    [1,  2,  3,  4],
    [12, 13, 14, 5],
    [11, 16, 15, 6],
    [10,  9,  8, 7]
]

> 输出

result = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]

> 解题思路

按层遍历, 由于是顺时针, 所以每一层按top, right, bottom, left的次序遍历. 遍历完一层, 更新top, right, down, left值.
以第一层为例:
第一层	top: 	(0, 0), (0,1), (0,2), (0,3) ---> 	(r_min, 		[c_min, c_max])
第一层	right: 	(1,3), (2,3), (3,3) 		---> 	([r_min+1, r_max], 		c_max)
第一层	bottom: (3, 2), (3, 1), (3,0) 		---> 	(r_max, 		[c_max-1, c_min])
第一层	left: 	(2,0), (1,0) 			    ---> 	([r_max-1, r_min+1], 	c_min)
一层结束时不要忘记更新边界值:
r_min += 1
r_max -= 1
c_min += 1
c_max -= 1

> 图解

![WechatIMG1.jpeg](https://pic.leetcode-cn.com/5eb14976e5e61ca65c93c4e328cfce8fee26836b184ddb6d777bb8479bf357a0-WechatIMG1.jpeg)

> 代码实现


```
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        def generate_coordinates(r_min, r_max, c_min, c_max):
            # top
            for c_c in range(c_min, c_max + 1):
                yield r_min, c_c
            # right
            for c_r in range(r_min + 1, r_max + 1):
                yield c_r, c_max
            if r_min < r_max and c_min < c_max:
                # bottom
                for c_c in range(c_max - 1, c_min - 1, -1):
                    yield r_max, c_c
                # left
                for c_r in range(r_max - 1, r_min, -1):
                    yield c_r, c_min

        if not matrix: return []
        result = []
        r_min = 0;c_min = 0
        r_max = len(matrix) - 1;c_max = len(matrix[0]) - 1
        while (r_min <= r_max and c_min <= c_max):
            for r, c in generate_coordinates(r_min, r_max, c_min, c_max):
                result.append(matrix[r][c])
            r_min += 1
            r_max -= 1
            c_min += 1
            c_max -= 1

        return result
```
> 测试结果

![image.png](https://pic.leetcode-cn.com/3422eeadbc53abe7b736b017ab1962124d843046374dc0daa0ba3a803a0af6e9-image.png)


> 总结 

这个练习加深了对python生成器的理解, 解题思路参考了官方题解.


