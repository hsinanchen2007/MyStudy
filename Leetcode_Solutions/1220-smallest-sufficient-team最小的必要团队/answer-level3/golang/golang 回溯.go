回溯算法，效率较低

核心点：
把每个skill看成一个位，比如["aa","bb","cc"], 即 1，10，100。当计算的结果为‘111’时，说明成功。

计算每个人的能力， 比如 people[0]的技能为["aa", "cc"], 转换为数字就是 101。

然后我们可以通过回溯去计算结果，回溯算法本身比较简单，所以不详细介绍。这里主要介绍几个优化点，因为直接暴力回溯会超时。

1. 记录某个技能是否只有一个人有， 如果只有一个同学有这个技能，我们可以直接把他加到最终结果，不用再到回溯中计算
```
only := make(map[string][]int)
for i := 0; i < len(people); i++ {
	t := 0
	for j := 0; j < len(people[i]); j++ {
		if v, ok := add[people[i][j]]; ok {
			t = t | (1 << uint(v))
		}
		only[people[i][j]] = append(only[people[i][j]], i) // 记录有该技能的同学
	}
	peopleSkill[i] = t
}
```
2. 判断两个人的技能是否有完全包含的关系，如果有，可以直接不计算另一个人，减小回溯的大小
```
for i := 0; i < len(peopleSkill); i++ {
	for j := i + 1; j < len(peopleSkill); j++ {
		if (peopleSkill[i] | peopleSkill[j]) == peopleSkill[i] {
			peopleSkill[j] = 0
		}
	}
}
```

完整代码：
```
func smallestSufficientTeam(req_skills []string, people [][]string) []int {
	add := make(map[string]int)
	suc := 0
	for i := 0; i < len(req_skills); i++ {
		add[req_skills[i]] = i + 1
		suc |= 1 << uint(i+1) // 计算所有技能的值
	}
	visited := make([]bool, len(people))
	peopleSkill := make([]int, len(people))
	only := make(map[string][]int)
	for i := 0; i < len(people); i++ {
		t := 0
		for j := 0; j < len(people[i]); j++ {
			if v, ok := add[people[i][j]]; ok {
				t = t | (1 << uint(v)) // 计算单个同学的技能
			}
			only[people[i][j]] = append(only[people[i][j]], i) // 统计哪些同学有对应的技能
		}
		peopleSkill[i] = t
	}
	for i := 0; i < len(peopleSkill); i++ {
		for j := i + 1; j < len(peopleSkill); j++ {
			if (peopleSkill[i] | peopleSkill[j]) == peopleSkill[i] {
				peopleSkill[j] = 0 // 如果j的技能i全部有，不需要计算j
			}
		}
	}
	now := 0
	ret := map[int]bool{}
	r := make([]int, 0)
	// 检查哪些技能只有一个人有，直接把这个同学添加到结果集中
	for _, v := range only {
		if len(v) == 1 {
			now |= peopleSkill[v[0]]
			peopleSkill[v[0]] = 0
			ret[v[0]] = true
		}
	}
	for k := range ret {
		r = append(r, k)
	}
	min := 20
	_, ret1 := backtrack(peopleSkill, []int{}, visited, now, suc, &min, 0) // 回溯
	r = append(r, ret1...)
	sort.Ints(r)
	return r
}

func backtrack(people, nowPeople []int, visited []bool, now, suc int, min *int, count int) (bool, []int) {
	if now == suc { 
		if *min > count {
			*min = count
			ret := make([]int, len(nowPeople))
			copy(ret, nowPeople)
			return true, ret
		}
		return false, nil
	}
	if count >= *min {
		return false, nil
	}
	ret := []int{}
	for i := 0; i < len(people); i++ {
		if people[i] == 0 || visited[i] {
			continue
		}
		if now == (now | people[i]) {
			continue
		}
		visited[i] = true
		if ok, v1 := backtrack(people, append(nowPeople, i), visited, (now | people[i]), suc, min, count+1); ok {
			ret = v1
		}
		visited[i] = false
	}
	if len(ret) > 0 {
		return true, ret
	}
	return false, nil
}


```
