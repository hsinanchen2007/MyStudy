1、定义栈，最大值为0，stack用于存储heights的索引，stack = [-1]
   之所以初始化为-1，由于单独的一跟柱子也会计算面积。
   例如输入为[1]时，只有一个元素，需要计算最大面积，则需要计算【索引0-（-1）】* heights[0]的值为面积
2、循环heights
  （1）当height[栈顶索引]大于当前的height[i]，弹出栈顶，并进行计算，直到栈顶不为-1且height[栈顶索引]<= height[i]
         弹出栈顶，计算以heights[栈顶索引]为最短柱子的最大面积，跟最大值进行比较
         长（i-1到栈顶前一个的索引差值）* 高（heights[栈顶索引]）
  （2）将索引i压入栈
3、循环stack
  （1）当栈顶元素不为-1，说明还有剩余索引未计算，需要计算以heights[栈顶索引]为最短柱子的最大面积，跟最大值进行比较
       此时的面积等于长（heights的长度-当前索引）*高（heights[栈顶索引]）
  （2） 注意：以下代码中是h_len - stack[-1] - 1，由于stack已经pop弹出，所以多减1
4、返回最大值

        

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [-1]
        max_value = 0
        h_len = len(heights)
        for i in range(h_len):
            while stack[-1] != -1 and heights[stack[-1]] > heights[i]:
                max_value = max(heights[stack.pop()]*(i - 1 - stack[-1]), max_value)
            stack.append(i)
        while stack[-1] != -1:
            max_value = max(heights[stack.pop()]*(h_len - stack[-1] - 1), max_value)
        return max_value