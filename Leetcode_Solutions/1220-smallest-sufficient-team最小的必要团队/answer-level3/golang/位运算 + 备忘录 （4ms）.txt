# 3种方式解决方式
1. 位运算+动态规划
1. 位运算+回溯
1. 位运算+备忘录

前两种其他题解已经涉及了，这里就说下第3种，也可查看: [最小的必要团队](https://github.com/zywaited/leetcode/tree/master/1101_1150/1125)(3种方式都有实现)，第3种原始逻辑，比回溯效率快，比优化后的回溯慢，但是优化后非常快。

## 优化点：
1. 去除可以被替代的人员
```
// ps 代表各人员的技能
for i := 0; i < pl; i++ {
	for j := i + 1; j < pl; j++ {
		if ps[i]|ps[j] == ps[i] {
			// i 包含 j
			ps[j] = 0
			continue
		}
		if ps[i]|ps[j] == ps[j] {
			// j 包含 i
			ps[i] = 0
			break
		}
	}
}
```
2. 找到独有技能的人员
```
// sp 代表各技能的人员详情
// cs 当前已找到的技能
// cp 找到的独有技能人员
for _, p := range sp {
	// 可能一个同学拥有多个独有技能，所以去重
	if len(p) > 1 || ps[p[0]] == 0 {
		continue
	}
	cp = append(cp, p[0])
	cs |= ps[p[0]]
	ps[p[0]] = 0
}
```

## 备忘录
- 每次查找只需要知道当前已经找到那些技能，还差哪些技能，直到一个人能满足差的技能
- 最终判断逻辑： dp[x|y] = min(dp[x|y], dp[x]+dp[y])
-
```
// 无技能或者被包含
if ps[j] == 0 || now != 0 && ps[j]|now == now {
	continue
}
// 一个人
if ps[j]|need == ps[j] {
	mp[need] = []int{j}
	break
}
// 注意：剩余技能必须先与已经有的技能now做或运算，然后再和所有的技能做异或，这样才能保证结果是差的技能（对应位为1）
tmp := dp(j, now|ps[j], (now|ps[j])^fs)
// 找不到对应人员或者人数比现在还多
if len(tmp) == 0 || len(mp[need]) != 0 && len(tmp) >= len(mp[need])-1 {
	continue
}
mp[need] = append([]int{j}, tmp...)
```

## 完整代码
```
func smallestSufficientTeam(skills []string, people [][]string) []int {
	// 技能点位置
	skillIndex := make(map[string]uint)
	for i, skill := range skills {
		skillIndex[skill] = uint(i)
	}

	// 技能拥有人数
	sp := make(map[string][]int)

	// 先计算每个同学的技能点
	pl := len(people)
	ps := make([]int, pl)
	for i, ss := range people {
		for _, skill := range ss {
			if _, ok := skillIndex[skill]; !ok {
				continue
			}
			ps[i] |= 1 << skillIndex[skill]
			sp[skill] = append(sp[skill], i)
		}
	}

	// 替代人员
	for i := 0; i < pl; i++ {
		for j := i + 1; j < pl; j++ {
			if ps[i]|ps[j] == ps[i] {
				// i 包含 j
				ps[j] = 0
				continue
			}
			if ps[i]|ps[j] == ps[j] {
				// j 包含 i
				ps[i] = 0
				break
			}
		}
	}
	// 添加单独的技能人员
	cs := 0
	var cp []int
	for _, p := range sp {
		// 可能一个同学拥有多个独有技能，所以去重
		if len(p) > 1 || ps[p[0]] == 0 {
			continue
		}
		cp = append(cp, p[0])
		cs |= ps[p[0]]
		ps[p[0]] = 0
	}

	// 记住中间状态
	mp := make(map[int][]int)
	// 所有技能
	fs := (1 << uint(len(skills))) - 1
	var dp func(int, int, int) []int
	dp = func(i, now, need int) []int {
		if _, ok := mp[need]; ok {
			return mp[need]
		}

		for j := i + 1; j < pl; j++ {
			// 无技能或者被包含
			if ps[j] == 0 || now != 0 && ps[j]|now == now {
				continue
			}
			// 一个人
			if ps[j]|need == ps[j] {
				mp[need] = []int{j}
				break
			}
			tmp := dp(j, now|ps[j], (now|ps[j])^fs)
			// 找不到对应人员或者人数比现在还多
			if len(tmp) == 0 || len(mp[need]) != 0 && len(tmp) >= len(mp[need])-1 {
				continue
			}
			mp[need] = append([]int{j}, tmp...)
		}
		// 没找到则置空
		if len(mp[need]) == 0 {
			mp[need] = make([]int, 0)
		}
		return mp[need]
	}
	// 优化后只要找到除cp的其他人
	return append(cp, dp(-1, cs, cs^fs)...)
}
```

