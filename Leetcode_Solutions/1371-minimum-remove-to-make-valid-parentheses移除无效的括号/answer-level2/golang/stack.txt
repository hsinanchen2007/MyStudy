### 解题思路
此处撰写解题思路

### 代码

```golang
type item struct {
	index int
	value byte
}

func minRemoveToMakeValid(s string) string {
	sb := []byte(s)
	ms := list.New()
	for i := 0; i < len(sb); i++ {
		if sb[i] != '(' && sb[i] != ')' {
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
		v := elem.Value.(item).value
		if v == '(' && sb[i] == ')' {
			ms.Remove(elem)
			continue
		}
		ms.PushBack(item{
			index: i,
			value: sb[i],
		})

	}
	invlidIndex := make(map[int]struct{})
	for ms.Len() > 0 {
		e := ms.Back()
		invlidIndex[e.Value.(item).index] = struct{}{}
		ms.Remove(e)
	}
	r := make([]byte, 0)
	for i := 0; i < len(sb); i++ {
		if _, ok := invlidIndex[i]; ok {
			continue
		}
		r = append(r, sb[i])
	}
	return string(r)
}

```