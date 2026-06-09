### 解题思路
观察10个数字的英文, 发现根据包含独特字母这一特点, 可以分为3组:
{0, 2, 4, 6, 8}
{1, 3, 5, 7}
{9}

经过三层筛选, 每一层的字母都有着独特的辨识字母, 即可统计得到原始数字的分布.

### 代码

```golang
func offset(c rune) int {
	return int(c - 'a')
}

type digitParser struct {
	index int
	seq   []rune
}

func originalDigits(s string) string {
	// zero, one, two, three, four, five, six, seven, eight, nine
	// z          w           u            x           g
	// one three five seven nine
	//   o   r    f     s
	// nine
	// i
	alpha := make([]int, 26)
	count := make([]int, 10)
	minusAlpha := func(rs []rune, delta int) {
		for _, r := range rs {
			alpha[int(r-'a')] -= delta
		}
	}
	type parserMap map[rune]digitParser

	addCount := func(c rune, m parserMap, delta int) {
		parser, ok := m[c]
		if !ok {
			return
		}
		minusAlpha(parser.seq, delta)
		count[parser.index] += delta
	}
	r1 := parserMap{
		'z': digitParser{0, []rune("zero")},
		'w': digitParser{2, []rune("two")},
		'u': digitParser{4, []rune("four")},
		'x': digitParser{6, []rune("six")},
		'g': digitParser{8, []rune("eight")},
	}
	for _, c := range s {
		alpha[offset(c)]++
		addCount(c, r1, 1)
	}
	r2 := parserMap{
		'o': digitParser{1, []rune("one")},
		'r': digitParser{3, []rune("three")},
		'f': digitParser{5, []rune("five")},
		's': digitParser{7, []rune("seven")},
	}
	for i, v := range alpha {
		if v == 0 {
			continue
		}
		addCount(rune(i+'a'), r2, v)
	}
	count[9] += alpha[int('i'-'a')]

	numTable := []rune{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
	var b strings.Builder
	for num, cnt := range count {
		fmt.Println("Num=", num, "Count=", cnt)
		for i := 0; i < cnt; i++ {
			b.WriteRune(numTable[num])
		}
	}
	return b.String()
}

```