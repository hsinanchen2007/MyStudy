```
from typing import List

import numpy as np
import numpy.random as npr


class Solution:

	def __init__(self, rects: List[List[int]]):
		self.rects = rects
		self.k = len(rects)
		self.sum_area = sum([(rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1) for rect in rects])
		self.probs = []
		for rect in rects:
			self.probs.append((rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1) / self.sum_area)
		self.Prob, self.Alias = self.alias_setup(self.k, self.probs)

	def alias_setup(self, k, probs):
		Prob = np.zeros(k)
		Alias = np.zeros(k, dtype=np.int)
		smaller, larger = [], []
		for kk, prob in enumerate(probs):
			Prob[kk] = k * prob
			if Prob[kk] < 1.0:
				smaller.append(kk)
			else:
				larger.append(kk)

		# 通过拼凑将各个类别凑为1
		while smaller and larger:
			small, large = smaller.pop(), larger.pop()

			Alias[small] = large
			Prob[large] = Prob[large] - (1.0 - Prob[small])
			if Prob[large] < 1.0:
				smaller.append(large)
			else:
				larger.append(large)
		return Prob, Alias

	def pick(self) -> List[int]:
		# 随机取一列
		kk = int(np.floor(npr.rand() * self.k))
		if npr.rand() < self.Prob[kk]:
			rect = self.rects[kk]
		else:
			rect = self.rects[self.Alias[kk]]
		return [npr.randint(rect[0], rect[2]+1), npr.randint(rect[1], rect[3]+1)]

        


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
```
