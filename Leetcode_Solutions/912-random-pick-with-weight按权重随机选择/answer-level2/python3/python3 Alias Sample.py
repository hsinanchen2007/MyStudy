```
from typing import List

import numpy as np
import numpy.random as npr


class Solution:

	def __init__(self, w: List[int]):
		# 类别个数
		self.k = len(w)
		#每个数占总和的权重
		self.probs = []
		self.sum = sum(w)
		for ww in w:
			self.probs.append(ww/self.sum)
		self.Prob,self.Alias = self.alias_setup(self.k,self.probs)

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

		# 通过拼凑，将各个类别都凑为1
		while len(smaller) > 0 and len(larger) > 0:
			small = smaller.pop()
			large = larger.pop()

			Alias[small] = large
			Prob[large] = Prob[large] - (1.0 - Prob[small])  # 将大的分到小的上

			if Prob[large] < 1.0:
				smaller.append(large)
			else:
				larger.append(large)
		return Prob, Alias

	def pickIndex(self) -> int:
		#随机取一列
		kk = int(np.floor(npr.rand()*self.k))
		if npr.rand() < self.Prob[kk]:
			return kk
		else:
			return self.Alias[kk]
```
