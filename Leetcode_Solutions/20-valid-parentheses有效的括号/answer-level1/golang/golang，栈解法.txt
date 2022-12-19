### 解题思路
此处撰写解题思路

### 代码

```golang
func isValid(s string) bool {
	if len(s)%2 == 1{
		return false
	}

    if len(s) == 0 {
        return true
    }

	var stock = make([]string, 0)
	for i:=0; i<len(s);i++{
		v := string(s[i])
		if v == "[" || v == "(" || v == "{" {
			stock = append(stock, v)
		} else {
			if len(stock) > 0 {
				switch v {
				case ")":
					if stock[len(stock) - 1] == "(" {
						stock = stock[:len(stock) - 1]
					} else {
						return false
					}
				case "]":
					if stock[len(stock) - 1] == "[" {
						stock = stock[:len(stock) - 1]
					} else {
						return false
					}
				case "}":
					if stock[len(stock) - 1] == "{" {
						stock = stock[:len(stock) - 1]
					} else {
						return false
					}
				default:
					return false
				}
			} else {
				return false
			}
		}
	}


	return len(stock) == 0
}
```