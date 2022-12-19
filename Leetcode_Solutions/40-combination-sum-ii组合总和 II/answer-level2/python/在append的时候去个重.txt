def combinationSum( candidates, target):
	res=[]
	candidates.sort()
	def helper(t,ans,begin):
		if t==0 and ans not in res:
			res.append(ans)
			return
		for i in range(len(candidates))[begin:]:
			if t<candidates[i]:
				continue
			helper(t-candidates[i],ans+[candidates[i]],i+1)
	helper(target,[],0)
	return res