这个题是维特比算法的一个典型应用，为了求全局最短路径，必须知道从初始位置到当前各位置的最短路径，再从当前位置，依次找到到达下一位置的最短路径。


为什么通过找到当前可到达位置的局部最优路径最终就能得到全局最短路径呢？设这条路径需要经过t个点，每个点的权重不相同，最后找到了一条路径，这条路径上的t个点的权值之和最小。令这条路径上的第i个点($0 < i < t$)的位置为$l_{i}$，这个点将整条路径分为两部分：$l_{0},\cdots,l_{i}$和$l_{i+1},\cdots,l_{t}$。那么如果我们假设$l_{0},\cdots,l_{i}$这条路径不是从位置0到位置i的权值最小路径，就必然存在另一条从位置0到位置i的权值最小路径，这样就说明从位置0到位置t的最小权值还可以更小，这和我们的假设是矛盾的，由此可证，$l_{0},\cdots,l_{i}$这条路径必须是从位置0到位置i的局部最优路径。

```python 
import numpy as np

class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        
        if len(triangle) == 0:
            return 0
        
        viterbi = [-1] * len(triangle)
        
        for index, elements in enumerate(triangle):
            # print('elements--', elements)
            if index == 0:  # 如果是第一行,直接给第一个值赋值
                viterbi[0] = elements[0]
            else: #如果不是第一行，则根据当前的局部最短路径分别寻找到达当前位置的最短路径
                
                tmp_viterbi = np.copy(viterbi)
                # print('tmp_viterbi---', tmp_viterbi)
                for i, element in enumerate(elements):
                    if i == 0:  # 每一行的0元素位置只能从上一行的0元素位置处过来
                        viterbi[i] = tmp_viterbi[i] + element
                        print('tmp_viterbi[{}]={}, element={}'.format(i, tmp_viterbi[i], element))
                        continue
                    
                    if i == len(elements) - 1:  # 当前行的最后一个元素只能从上一行的最后一个位置处到达
                        viterbi[i] = tmp_viterbi[i-1] + element
                        # print('tmp_viterbi---', tmp_viterbi)
                        continue
                        
                    # 0 < i < len(element) - 1
                    viterbi[i] = min(tmp_viterbi[i-1], tmp_viterbi[i]) + element
                    # print('tmp_viterbi---', tmp_viterbi)

            # print(viterbi)
                
            # 如果已经到了最后一行，则找出其中最小的值返回即可    
            if index == len(triangle) - 1: 
                return min(viterbi)
          


```