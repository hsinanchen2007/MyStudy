```
package _2x

var charMap = map[uint8]bool{}
var alphaMap = map[uint8]uint8{}

func init() {
	for i := uint8(0); i < 26; i++ {
		charMap['a'+i] = true
		alphaMap['a'+i] = 'A' + i
		alphaMap['A'+i] = 'A' + i
		charMap['A'+i] = true
	}
	for i := uint8(0); i < 10; i++ {
		alphaMap['0'+i] = '0' + i
		charMap['0'+i] = true
	}
}
func isPalindrome(s string) bool {
	var (
		length = len(s)
		i      = 0
		j      = length - 1
	)

	for i < j {
		for !charMap[s[i]] && i < j {
			i++
		}
		for !charMap[s[j]] && i < j {
			j--
		}
		if i >= j {
			return true
		}
		if alphaMap[s[i]] != alphaMap[s[j]] {
			return false
		}
		i++
		j--
	}
	return true
}

```
