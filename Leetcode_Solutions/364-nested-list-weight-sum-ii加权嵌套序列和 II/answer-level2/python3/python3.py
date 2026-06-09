	def depthSumInverse(self, nestedList: List[NestedInteger]) -> int:
		res = 0
		# 索引是深度（第一层深度为0），值是同一个深度下所有数字的和
		depth_weight = {}

		def getDepth(nest, depth, depth_weight):
			# 深度加1
			if depth >= len(depth_weight):
				depth_weight[depth] = 0
			# 同一个深度下总的数字和
			if nest.isInteger():
				depth_weight[depth] = depth_weight.get(depth, 0) + nest.getInteger()
			else:
				for n in nest.getList():
					getDepth(n, depth + 1, depth_weight)

		# 第一次遍历，都当做是0层深度
		for nest in nestedList:
			getDepth(nest, 0, depth_weight)
		for key, value in depth_weight.items():
			res += (len(depth_weight) - key) * value
		return res