### 解题思路
stack + 递归处理 

当前双百

### 代码

```golang

type item struct {
	index int
	value byte
}

func decodeString(s string) string {
	sb := []byte(s)
	r := decode(sb)
	return string(r)
}

func decode(sb []byte) []byte {
	if !bytes.Contains(sb, []byte{'['}) {
		return sb
	}
	ms := list.New()
	rb := []byte{}
	for i := 0; i < len(sb); i++ {
		if sb[i] != '[' && sb[i] != ']' {
			continue
		}
		if ms.Len() == 0 {
			ms.PushBack(item{
				index: i,
				value: sb[i],
			})
			continue
		}

		elem := ms.Back()
		preValue := elem.Value.(item).value
		preIndex := elem.Value.(item).index
		if preValue == '[' && sb[i] == ']' {
			num, start := getK(sb, preIndex-1)
			seq := sb[preIndex+1 : i]
			rb = append(rb, sb[:start]...)
			for i := 0; i < num; i++ {
				rb = append(rb, seq...)
			}
			rb = append(rb, sb[i+1:]...)
			break
		}

		if preValue == sb[i] {
			ms.PushBack(item{
				index: i,
				value: sb[i],
			})
			continue
		}

	}
	return decode(rb)
}

func getK(sb []byte, index int) (int, int) {
	preIndex := index
	for i := index; i >= 0; i-- {
		if sb[i] >= '0' && sb[i] <= '9' {
			preIndex = i
			continue
		}
		break
	}
	r, _ := strconv.Atoi(string(sb[preIndex : index+1]))
	return r, preIndex
}

```