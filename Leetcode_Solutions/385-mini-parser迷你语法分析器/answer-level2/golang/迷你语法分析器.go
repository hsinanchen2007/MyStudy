### 解题思路


### 代码

```golang
func deserialize(s string) *NestedInteger {
	if s[0] != '['{
		ni:=NestedInteger{}
		num, _ := strconv.Atoi(s)
		ni.SetInteger(num)
		return &ni
	}
	
	stack := make([]NestedInteger, 0)
	si := -1
	for ei, c := range s {
		if c == '[' {
			ni := NestedInteger{}
			stack = append(stack, ni)
		} else if c == ']' {
			// [673,123]
			if si != -1 {
				num, _ := strconv.Atoi(s[si:ei])
				ni := NestedInteger{}
				ni.SetInteger(num)
				si = -1
				stack[len(stack)-1].Add(ni)
			}
			// [123,[123]]
			if len(stack) > 1 {
				l := len(stack) - 1
				inner := stack[l]
				stack = stack[0:l]
				stack[l-1].Add(inner)
			}
		}  else if c == ','{
			// [673,123]
			if si != -1 {
				num, _ := strconv.Atoi(s[si:ei])
				ni := NestedInteger{}
				ni.SetInteger(num)
				si = -1
				stack[len(stack)-1].Add(ni)
			}
		} else if si == -1 {
			si = ei
		}
	}
	return &stack[0]
}

```